#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull base=131;
ull a[10010];
char s[10010];
int n,ans=1;
ull hashs(char s[])
{
    int len=strlen(s);
    ull ans=0;
    for (int i=0;i<len;i++)
        ans=ans*base+(ull)s[i];
    return ans&0x7fffffff;
}
main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        a[i]=hashs(s);
    }
    sort(a+1,a+n+1);
    for (int i=2;i<=n;i++)
        if (a[i]!=a[i-1])
        {
            printf("a :%d\n",a[i]);
            ans++;
        }
    printf("%d\n",ans);
}