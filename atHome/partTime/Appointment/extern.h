typedef struct patient//ҽ�����û���¼���ݹ��õĽṹ�� 
	{
	    char user[30];
	    char name[30];
	    char password[30];
	    char office[30];
	    struct patient *next;
	}Patient;
		
typedef struct list//�Խṹ������ͷβָ�� 
	{
	    Patient *head;
	    Patient *tail;
	}List;
	
typedef struct formp// ҽ�����û��ĳ��ＰԤԼ���ݹ��ýṹ�� 
	{
        char user[30];
	    char name[30];
	    int timeYear;
        int timeMon;
        int timeDay;
	    char office[30];
	    char doctor[30];
        int number;
	    struct formp *next;
	}Formp;
		
typedef struct formlistp//�Խṹ������ͷβָ��
	{
	    Formp *head;
	    Formp *tail;
	}Formlistp;
	

struct tm //��time.h��ṹ��tm���ٴ������������ļ����޷�������ȡ 
{
   int tm_sec;         /* �룬��Χ�� 0 �� 59        */
   int tm_min;         /* �֣���Χ�� 0 �� 59        */
   int tm_hour;        /* Сʱ����Χ�� 0 �� 23        */
   int tm_mday;        /* һ���еĵڼ��죬��Χ�� 1 �� 31    */
   int tm_mon;         /* �£���Χ�� 0 �� 11        */
   int tm_year;        /* �� 1900 ���������        */
   int tm_wday;        /* һ���еĵڼ��죬��Χ�� 0 �� 6    */
   int tm_yday;        /* һ���еĵڼ��죬��Χ�� 0 �� 365    */
   int tm_isdst;       /* ����ʱ                */
};


int n = 0;//��¼�û�������ȫ�ֱ��� 
int m = 0;//��¼ҽ��������ȫ�ֱ���
int inputp = 0;//��¼ԤԼ������ȫ�ֱ���
int inputd = 0;//��¼����������ȫ�ֱ���
