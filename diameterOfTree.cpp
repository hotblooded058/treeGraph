#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>g[N];

int depth[N];

void dfs(int vertex,int par=-1)
{
    for(int child:g[vertex])
    {
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,par);
    }
}

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);

    int maxDepth=-1;
    int maxDepth_node;

    for(int i=1;i<=n;i++)
    {
        if(maxDepth<depth[i])
        {
            maxDepth=depth[i];
            maxDepth_node=i;
        }
        depth[i]=0;
    }

    dfs(maxDepth_node);
    maxDepth=-1;
    for(int i=1;i<=n;i++)
    {
        if(maxDepth<depth[i])
        {
            maxDepth=depth[i];
        }
    }

    cout<<"Diameter of Tree="<<maxDepth<<endl;
    return 0;
}