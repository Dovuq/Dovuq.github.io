// ���߱�ʱ�临�Ӷ� O(m)
int head[size],next[size],to[size],edgenum;
// int val[size]; // ����Ǵ�Ȩͼ�ͼ������
// ע�⣡���ʹ��������ͷ�ļ����� next[] �ϻ�������ԭ�����ظ����ơ�next ��������� STL ���Ѿ����ڣ��뻻һ�����֡�
void addedge (int u,int v/*,int w*/) // ����Ǵ�Ȩͼ�ͼ��� w
{
    next[edgenum]=head[u];
    head[u]=edgenum;
    to[edgenum]=v;
    // val[edgenum]=w; // ͬ��
}
addedge (u,v/*,w*/); // w ͬ��
addedge (v,u/*,w*/); // ����ǵ���ͼ��ȥ�����

// �����߱�ʱ�临�Ӷ� O(m/n)
// ������� u �б����ӵ����нڵ�
for (int e=head[u];e;e=next[e])
{
    int v=to[e];
    // int w=val[e]; // ͬ��
    // ...
}