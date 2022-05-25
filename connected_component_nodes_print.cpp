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
1 2 3 5 4 
6 7 
8 

*/

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

vector<int>g[N];
vector<vector<int>> cc;
vector<int>current_cc;

bool vit[N];

void dfs(int vertex)
{
    
    vit[vertex]=true;
    current_cc.push_back(vertex);
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

    for(int i=1;i<=n;i++)
    {
        if(vit[i])
        {
            continue;
        }
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
    }
    cout<<cc.size()<<endl;
    for(auto cc_c:cc)
    {
        for(int vertex :cc_c)
        {
             cout<<vertex<<" ";
        }
        cout<<endl;
    }
    return 0;
}
