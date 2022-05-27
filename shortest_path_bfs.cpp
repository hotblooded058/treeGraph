#include<bits/stdc++.h>
using namespace std;

const int N=8;
vector<int>g[N];

int vis[N][N];
int level[N][N];

int getX(string s)
{
    return s[0]-'a';
}

int getY(string s)
{
    return s[1]-'1';
}

vector<pair<int,int>> movements={
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {1,2},{-1,2},
    {1,-2},{-1,-2}
};
 
bool isValid(int x,int y)
{
    return x>=0 && y>=0 && x<8 && y<8;
}

int bfs(string source,string dest)
{
    int sourceX=getX(source);
    int sourceY=getY(source);
    int destX=getX(dest);
    int destY=getY(dest);

    queue<pair<int,int>>q;
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY]=1;

    while(!q.empty())
    {
        pair<int,int>v=q.front();
        int x=v.first,y=v.second;
        q.pop();

        for(auto movement: movements)
        {
            int childX= movement.first+x;
            int childY= movement.second+y;

            if(!isValid(childX,childY)) continue;
            if(!vis[childX][childY])
            {
                q.push({childX,childY});
                vis[childX][childY]=1;
                level[childX][childY]=level[x][y]+1;
            }
        }
    }
    return level[destX][destY];
}

void reset(int)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            vis[i][j]=0;
            level[i][j]=0;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        string s1,s2;
        cin>>s1>>s2;

        cout<<bfs(s1,s2)<<endl;
    }

    return 0;
}