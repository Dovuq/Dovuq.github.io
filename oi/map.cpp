// Operations on the map
int n,m;
char mp[size][size];
// There are many kinds of maps, here we take the simplest map, that is a '#' stands for an obstacle and a '.' stands for a piece of open space, for example
// Attention! If you have used the head "bits/stdc++.h", you might get a compile error on "map[]" that the name is ambiguous. The name "map" already exists in STL, so please change another name.

// DFS on the map, time complexity O(kmn) in average, where the total time complexity of lines 15 and 24 is k
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};
// This is the possible direction of each step. Here they are up, down, left and right. In some cases there are eight directions: up, down, left, right, left up, right up, left down and right down.
bool visit[size][size];
void dfs (int x,int y) // According to the requirement of the problem, you can change the return type or add parameters
{
    visit[x][y]=1;
    // The point (x,y) is processed according to the requirements of the problem
    for (int k=0;k<4;k++) // There are 4 directions, so it is 4. If there are 8, then it should be changed to 8.
    {
        int xx=x+dx[k];
        int yy=y+dy[k];
        if (xx>0 && xx<=n && yy>0 && yy<=m
            && mp[xx][yy]=='.' && !visit[xx][yy] /*&& requirements of the problem*/)
        {
            dfs (xx,yy);
            // In fact, some operations can also be carried out here
        }
    }
}

// Above are two-dimensional maps, three-dimensional maps can be pushed like this.