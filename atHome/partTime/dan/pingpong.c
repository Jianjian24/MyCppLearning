#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> // for exit()
int count=0;
int niters;
int turn;
pthread_mutex_t turnlock;
pthread_cond_t myturn;
void *bee(void *arg) {
  int me = (int) arg;  // 0 or 1
  while (count < niters) {
    pthread_mutex_lock(&turnlock);
    while (turn != me)
      pthread_cond_wait(&myturn,&turnlock);
    /* turn == me and I hold the lock */
    if ((++count % 5) == 0)
      // ping goes first
      printf("%s: count is %d\n", (me ? "pong" : "ping"), count);
    turn = 1 - turn;
    pthread_mutex_unlock(&turnlock);
    pthread_cond_signal(&myturn);
  }
  return NULL;
}
int main(int argc, char *argv[]) {
  pthread_t tids[2];
  int i;
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <# iterations>\n",argv[0]);
    exit(1);
  }
  niters = atoi(argv[1]);
  if (pthread_mutex_init(&turnlock, NULL)) {
    fprintf(stderr,"mutex init");
    exit(9);
  }
  if (pthread_cond_init(&myturn,NULL)) {
    fprintf(stderr,"condvar init");
    exit(7);
  }
  for (i=0; i<2; i++)
    if (pthread_create(&tids[i],NULL,bee,(void *)i)) {
      fprintf(stderr,"pthread_create_failed\n");
      exit(9);
    }
  for (i=0; i<2; i++)
    if (pthread_join(tids[i],NULL)) {
      fprintf(stderr,"pthread_join failed\n");
      exit(9);
    }
/* all threads terminated */
  printf("niters %d\n",niters);
  printf("final count=%d\n",count);
  exit(0);
}
      

