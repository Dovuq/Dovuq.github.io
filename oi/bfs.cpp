// ����ʹ���˱߱�����Ϥ�߱�ĳ�����ת���߱�
// ʱ�临�Ӷ� O(kn)�����е� 12 ���� 20 �д������ʱ�临�Ӷ�Ϊ k
enum {white,gray,black} visit[size];
void bfs (int s)
{
    memset (visit,white,sizeof(visit));
    queue<int> que; // ʹ���� STL queue
    que.push (s);
    while (!que.empty())
    {
        int u=que.pop();
        // �Ըýڵ� u ����һЩ�������忴��ĿҪ��
        for (int e=head[u];e;e=next[u])
        {
            int v=to[e];
            if (visit[v]==white /*&& ��Ŀ�涨��Ҫ��*/)
            {
                que.push(v);
                visit[v]=gray;
                // ������ʵҲ���Խ���һЩ����
            }
        }
        visit[u]=black;
    }
}