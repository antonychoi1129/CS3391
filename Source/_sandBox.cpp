#include<bits/stdc++.h>
using namespace std;
const int maxn=201;
typedef long long ll;
const ll LL_max=1+10e15;
struct Edge//边
{
    int from,to;
    ll cap,flow,cost;//出点，入点，容量，当前流量，费用（也就是权值）
    Edge(int u,int v,ll c,ll f,ll w):from(u),to(v),cap(c),flow(f),cost(w){}
};

struct MCMF
{
    int n,m;
    vector<Edge> edges;//保存表
    vector<int> G[maxn];//保存邻接关系
    int inq[maxn];//判断一个点是否在队列当中（SPFA算法当中要用）
    long long d[maxn];//起点到d[i]的最短路径保存值
    int p[maxn];//用来记录路径，保存上一条弧
    ll a[maxn];//找到增广路径后的改进量

    void init(int n)//初始化
    {
        this->n=n;
        for(int i=0;i<=n;i++)
            G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int cap,long long cost)//添加边
    {
        edges.push_back(Edge(from,to,cap,0,cost));//正向
        edges.push_back(Edge(to,from,0,0,-cost));//反向
        m=edges.size();
        G[from].push_back(m-2);//按照边的编号保存邻接关系
        G[to].push_back(m-1);
    }

    bool BellmanFord(int s,int t,ll& flow,ll& cost)//最短路径算法
    {
        for(int i=0;i<=n;i++)
            d[i]=LL_max;
        memset(inq,0,sizeof(inq));
        d[s]=0;
        inq[s]=1;
        p[s]=0;
        a[s]=LL_max;

        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            inq[u]=0;
            for(int i=0;i<G[u].size();i++)
            {
                Edge& e=edges[G[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost)//寻找满足容量大于流量的可松弛边
                {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to])//是否在队列当中
                    {
                        Q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        if(d[t]==LL_max)//如果d[t]没有被更新，相当于没找到增广路径，则没有最大流也没有最小费用
            return false;
        flow+=a[t];//更新最大流
        cost+=d[t]*a[t];//单位流量乘以单位路径长度用来计算消耗
        for(int u=t;u!=s;u=edges[p[u]].from)//通过使用p[]保存的上一个边的值来对刚刚找到的增广路径上面的流量进行更新
        {
            edges[p[u]].flow+=a[t];//正向变更新
            edges[p[u]^1].flow-=a[t];//反向变更新（用位运算实现的）
        }
        return true;
    }

    ll MincostMaxflow(int s,int t,long long& cost)//计算从s到t的最小消耗cost，返回最大流
    {
        ll flow = 0;
        cost=0;
        while(BellmanFord(s,t,flow,cost));//不断寻找最短增广路径，直到找不到为止
        return flow;
    }
};
MCMF mcmf;
struct node
{
    int f,t,c;
};
int n,m,d,k;
node tmp[5001];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        for(int i=1;i<=m;i++)
            cin>>tmp[i].f>>tmp[i].t>>tmp[i].c;
        cin>>d>>k;
        mcmf.init(n+1);
        for(int i=1;i<=m;i++)
        {
            mcmf.AddEdge(tmp[i].f,tmp[i].t,k,tmp[i].c);
            mcmf.AddEdge(tmp[i].t,tmp[i].f,k,tmp[i].c);
        }
        mcmf.AddEdge(0,1,d,0);
        long long ans;
        ll flow=mcmf.MincostMaxflow(0,n,ans);
        if(flow<d)
            cout<<"Impossible."<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
/*--------------------- 
作者：红鲤鱼遇绿鲤鱼 
来源：CSDN 
原文：https://blog.csdn.net/tengfei461807914/article/details/55854611 
版权声明：本文为博主原创文章，转载请附上博文链接！   */
