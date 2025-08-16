// Heap, here we take minimum heap for example
struct HEAP
{
    int val[size],n;

    // Insert data to the heap, time complexity O(logn)
    void add (int x)
    {
        val[++n]=x;
        for (int m=n;m>1 && val[m]<val[m>>1];m>>=1)
            swap (val[m],val[m>>1]);
    }

    // Return the data of the root, time complexity O(1)
    int top ()
    {
        return val[1];
    }

    // Delete the root, time complexity O(logn)
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