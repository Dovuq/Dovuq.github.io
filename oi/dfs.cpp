// ����ʹ���˱߱�������Ϥ�߱��ĳ�����ת���߱���
// ʱ�临�Ӷ� O(kn)�����е� 7 ���� 14 �д�������ʱ�临�Ӷ�Ϊ k
bool visit[size];
void dfs (int u) // ������Ŀ��Ҫ���Ը��ķ������ͻ����Ӳ�����
{
    visit[u]=1;
    // �Ըýڵ� u ����һЩ���������忴��ĿҪ��
    for (int e=head[u];e;e=next[e])
    {
        int v=to[e];
        if (!visit[u] /*&& ��Ŀ�涨��Ҫ��*/)
        {
            dfs (u);
            // ������ʵҲ���Խ���һЩ����
        }
    }
}