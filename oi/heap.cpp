// 堆
inline bool cmp (int a,int b)
{
    // 如果 a 应该成为 b 的父节点，返回 true，否则返回 false
    // 时间复杂度一般为 O(1)
}
struct HEAP
{
    int val[size],n;

    // 在堆中插入数据，时间复杂度 O(logn)
    void add (int x)
    {
        val[++n]=x;
        for (int m=n;m>1 && cmp(val[m],val[m/2]);m/=2)
            swap (val[m],val[m/2]);
    }

    // 返回树根的数据，时间复杂度 O(1)
    int top ()
    {
        return val[1];
    }

    // 删除树根的数据，时间复杂度 O(logn)
    void del ()
    {
        swap (val[1],val[n]);
        n--;
        int m=1,t;
        while (m*2<=n)
        {
            if (m*2+1<=n && cmp(val[m*2+1],val[m*2]))
                t=m*2+1;
            else t=m*2;
            if (cmp(val[m],val[t])) break;
            swap (val[m],val[t]);
            m=t;
        }
    }

} heap;