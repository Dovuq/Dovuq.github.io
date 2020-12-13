// Segment tree, here we take sum for example
struct TREE
{
    int val[400005],tag[400005];
    void build (int i,int l,int r)
    {
        if (l>r) return;
        if (l==r)
        {
            val[i]=a[l]; // a[l] is the value of this node.
            return;
        }
        int mid=(l+r)>>1;
        build (i<<1,l,mid);
        build (i<<1|1,mid+1,r);
        val[i]=val[i<<1]+val[i<<1|1];
    }

    // Push down, time complexity O(1)
    void pushdown (int i,int l,int r)
    {
        tag[i<<1]+=tag[i];
        tag[i<<1|1]+=tag[i];
        val[i]+=tag[i]*(r-l+1);
        tag[i]=0;
    }

    // Interval query, time complexity O(logn)
    int query (int i,int l,int r,int x,int y)
    {
        if (l>=x && r<=y)
            return val[i]+tag[i]*(r-l+1);
        if (l>y || r<x) return 0;
        pushdown (i,l,r);
        int mid=(l+r)>>1;
        return query(i<<1,l,mid,x,y)+query(i<<1|1,mid+1,r,x,y);
    }

    // Interval modification, time complexity O(logn)
    void add (int i,int l,int r,int x,int y,int a)
    {
        if (l>=x && r<=y)
        {
            tag[i]+=a;
            return;
        }
        if (l>y || r<x) return;
        pushdown (i,l,r);
        int mid=(l+r)>>1;
        add (i<<1,l,mid,x,y,a);
        add (i<<1|1,mid+1,r,x,y,a);
        val[i]=val[i<<1]+val[i<<1|1]+tag[i<<1]*(mid-l+1)+tag[i<<1|1]*(r-mid);
    }

} tree;