// 建边表，时间复杂度 O(m)
int head[size],next[size],to[size],edgenum;
// int val[size]; // 如果是带权图就加上这句
// 注意！如果使用了万能头文件，在 next[] 上会编译错误，原因是重复名称。next 这个名字在 STL 中已经存在，请换一个名字。
void addedge (int u,int v/*,int w*/) // 如果是带权图就加上 w
{
    next[edgenum]=head[u];
    head[u]=edgenum;
    to[edgenum]=v;
    // val[edgenum]=w; // 同上
}
addedge (u,v/*,w*/); // w 同上
addedge (v,u/*,w*/); // 如果是单向图就去掉这句

// 遍历边表，时间复杂度 O(m/n)
// 访问与点 u 有边连接的所有节点
for (int e=head[u];e;e=next[e])
{
    int v=to[e];
    // int w=val[e]; // 同上
    // ...
}