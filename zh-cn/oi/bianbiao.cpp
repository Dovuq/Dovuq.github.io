// Build an edge list, time complexity O(m)
int head[size],next[size],to[size],edgenum;
// int val[size]; // Add this if it is a weighted graph
// Attention! If you have used the head "bits/stdc++.h", you might get a compile error on "next[]" that the name is ambiguous. The name "next" already exists in STL, so please change another name.
void addedge (int u,int v/*,int w*/) // Add "w" if it is a weighted graph
{
    next[++edgenum]=head[u];
    head[u]=edgenum;
    to[edgenum]=v;
    // val[edgenum]=w; // ditto
}
addedge (u,v/*,w*/); // w ditto
addedge (v,u/*,w*/); // If it is a unidirectional graph, delete this line

// Traversal the edge list, time complexity O(m/n)
// Visit all notes which has an adge to u
for (int e=head[u];e;e=next[e])
{
    int v=to[e];
    // int w=val[e]; // ditto
    // ...
}