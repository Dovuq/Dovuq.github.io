// 这里使用了边表，不熟悉边表的出门右转“边表”
// 时间复杂度 O(kn)，其中第 12 行与 20 行处理的总时间复杂度为 k
enum {white,gray,black} visit[size];
void bfs (int s)
{
    memset (visit,white,sizeof(visit));
    queue<int> que; // 使用了 STL queue
    que.push (s);
    while (!que.empty())
    {
        int u=que.pop();
        // 对该节点 u 进行一些处理，具体看题目要求
        for (int e=head[u];e;e=next[u])
        {
            int v=to[e];
            if (visit[v]==white /*&& 题目规定的要求*/)
            {
                que.push(v);
                visit[v]=gray;
                // 这里其实也可以进行一些操作
            }
        }
        visit[u]=black;
    }
}