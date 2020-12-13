// Here we use edge list. If you don't know edge list, turn to "edge list"
// Time complexity O(kn), where the total time complexity of lines 12 and 20 is k
enum {white,gray,black} visit[size];
void bfs (int s)
{
    memset (visit,white,sizeof(visit));
    queue<int> que; // We use STL queue
    que.push (s);
    while (!que.empty())
    {
        int u=que.pop();
        // The node u is processed according to the requirements of the problem
        for (int e=head[u];e;e=next[u])
        {
            int v=to[e];
            if (visit[v]==white /*&& requirements of the problem*/)
            {
                que.push(v);
                visit[v]=gray;
                // In fact, some operations can also be carried out here
            }
        }
        visit[u]=black;
    }
}