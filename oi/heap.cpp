// 堆，以最小堆为例
struct HEAP
{
    int val[size],n;

    // 在堆中插入数据，时间复杂度 O(logn)
    void add (int x)
    {
        val[++n]=x;
        for (int m=n;m>1 && val[m]<val[m>>1];m>>=1)
            swap (val[m],val[m>>1]);
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
        while ((m<<1)<=n)
        {
            if ((m<<1|1)<=n && val[m<<1|1]<val[m<<1])
                t=m<<1|1;
            else t=m<<1;
            if (val[m]<val[t]) break;
            swap (val[m],val[t]);
            m=t;
        }
    }

} heap;