#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];

int par[N];

void dfs(int vertex,int p=-1)
{
    par[vertex]=p;
    for(int child:g[vertex])
    {
        if(child==p) continue;
        dfs(child,vertex);
    }
}

vector<int> path(int vertex)
{
    vector<int>ans;
    while(vertex!= -1)
    {
        ans.push_back(v);
        vertex=par[vertex];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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

    int a,b;
    cin>>a>>b;

    vector<int> path_a=path(a);
    vector<int> path_b=path(b);

    int min_path=min(path_a.size(),path_b.size());
    int lca=-1;
    for(int i=0;i<min_path;i++)
    {
        if(path_a[i]==path_b[i])
        {
            lca=path_a[i];
        }
        else
        {
            break;
        }
    }

    cout<<lca<<endl;
    
    return 0;
}