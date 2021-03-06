/* 
INPUT
8 5
1 2
2 3
2 4
3 5
6 7

OUTPUT
3

*/

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

vector<int>g[N];
bool vit[N];

void dfs(int vertex)
{
    vit[vertex]=true;
    for(int child: g[vertex])
    {
        if(vit[child])
        {
            continue;
        }
        dfs(child);
    }
}

int main()
{
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;

        g[y].push_back(x);
        g[x].push_back(y);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(vit[i])
        {
            continue;
        }
        dfs(i);
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
