#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int color[201];
int n,e;
vector<int> edge[201];//邻接表
bool dfs(int x,int k)
{
    color[x]=k%2;
    for(int i=0;i<edge[x].size();i++)
    {
        int tmp=edge[x][i];
        if(color[x]==color[tmp])//当前的节点和它相邻的节点颜色相同
            return false;//如果相同就说明无法染色
        else
        {
            if(color[tmp]==-1)//-1代表这个节点还没有染色
            {
                if(dfs(tmp,k+1))//把这个节点染了
                return true;//染色成功就返回true
                else
                return false;//染不了就false
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    int a,b;
    while(cin>>n)
    {
        if(n==0)
        return 0;
        cin>>e;
        for(int i=0;i<201;i++)
        edge[i].clear();
        for(int i=0;i<e;i++)
        {
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        memset(color,-1,sizeof(color));
        if(dfs(a,0))
        cout<<"BICOLORABLE."<<endl;
        else
        cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
}