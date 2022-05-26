/*

Given Q queries ,Q <=10^5,
In each queries given V,
Print subtree sum of V & number of even numbers in a subtree of V?

*/

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];

bool vis[N];
int subtree_sum[N];
int even_no[N];

void dfs(int vertex)
{
    if(vertex%2==0)
    {
        even_no[vertex]++;
    }
    subtree_sum[vertex]+=vertex;
    vis[vertex]=true;
    for(int child:g[vertex])
    {
        if(vis[child])
        {
            continue;
        }
        dfs(child);
        subtree_sum[vertex]+=subtree_sum[child];
        even_no[vertex]+=even_no[child];
    }
}

int main()
{
    int m,n;
    cin>>m>>n;

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);

    int q;
    cin>>q;

    while(q--)
    {
        int v;
        cin>>v;

        cout<<subtree_sum[v]<<endl;
        cout<<even_no[v]<<endl;
    }
    return 0;
}