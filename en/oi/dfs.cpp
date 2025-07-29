// Here we use edge list. If you don't know edge list, turn to "edge list"
// Time complexity O(kn), where the total time complexity of lines 7 and 14 is k
bool visit[size];
void dfs (int u) // According to the requirement of the problem, you can change the return type or add parameters
{
    visit[u]=1;
    // The node u is processed according to the requirements of the problem
    for (int e=head[u];e;e=next[e])
    {
        int v=to[e];
        if (!visit[u] /*&& requirements of the problem*/)
        {
            dfs (u);
            // In fact, some operations can also be carried out here
        }
    }
}