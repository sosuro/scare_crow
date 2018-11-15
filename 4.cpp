#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 10000005
int n,m,l;
int T;
int mp[maxn];
int first[maxn],nxt[maxn],to[maxn],e;
bool vis[maxn];
void add(int u,int v){
    to[e]=v;
    nxt[e]=first[u];
    first[u]=e++;
}
void dfs(int s){
    vis[s]=true;
    for(int i=first[s];~i;i=nxt[i]){
        int v=to[i];
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main()
{
    int u,v;
     freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
            e=0;
        memset(vis,0,sizeof vis);
        memset(first,-1,sizeof first);
        scanf("%d%d%d",&n,&m,&l);
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        int sum=0;
        int ss;
        for(int i=0;i<l;i++){
            scanf("%d",&ss);
            dfs(ss);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==1)sum++;
        }
        printf("%d\n",sum);
    }
}