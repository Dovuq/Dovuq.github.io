// 这里使用了边表，不熟悉边表的出门右转“边表”
// 时间复杂度 O(kn)，其中第 7 行与 14 行处理的总时间复杂度为 k
bool visit[size];
void dfs (int u) // 根据题目需要可以更改返回类型或增加参数等
{
    visit[u]=1;
    // 对该节点 u 进行一些处理，具体看题目要求
    for (int e=head[u];e;e=next[e])
    {
        int v=to[e];
        if (!visit[u] /*&& 题目规定的要求*/)
        {
            dfs (u);
            // 这里其实也可以进行一些操作
        }
    }
}