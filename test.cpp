
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
 
const int maxn=2e3+100;
string str[maxn];
int a[maxn];
int l[maxn];
int r[maxn];
int vis[maxn];
int main()
{
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        int num=s.size();
        memset(vis,0,sizeof(vis));
        int sum=0;
        for(int j=0;j<num;j++)
        {
            a[j]=min(s[j]-'A','Z'-s[j]+1);
            sum+=a[j];
        }
        int ans=sum+num-1;
        int tot=0;
        for(int j=1;j<num;j++)
        {
            if(s[j]=='A'&&!vis[j])
            {
                vis[j]=1;
                l[++tot]=j-1;
                int now=j+1;
                while(now<num&&s[now]=='A')
                {
                    vis[now]=1;
                    now++;
                }
                if(now==num)
                {
                    r[tot]=num;
                }
                else r[tot]=now;
            }
        }
        cout << ans << endl;
        for(int j=1;j<=tot;j++)
        {
          cout << l[j] << " " << r[j] << " " << min(ans,min(sum+l[j]*2+num-r[j],sum+(num-r[j])*2+l[j])) << endl;
          cout << sum+l[j]*2+num-r[j] << " " << sum+(num-r[j])*2+l[j] << endl;
            ans=min(ans,min(sum+l[j]*2+num-r[j],sum+(num-r[j])*2+l[j]));
        }
        cout<<ans<<endl;
    }
    return 0;

}