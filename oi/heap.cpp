// �ѣ�����С��Ϊ��
struct HEAP
{
    int val[size],n;

    // �ڶ��в������ݣ�ʱ�临�Ӷ� O(logn)
    void add (int x)
    {
        val[++n]=x;
        for (int m=n;m>1 && val[m]<val[m>>1];m>>=1)
            swap (val[m],val[m>>1]);
    }

    // �������������ݣ�ʱ�临�Ӷ� O(1)
    int top ()
    {
        return val[1];
    }

    // ɾ�����������ݣ�ʱ�临�Ӷ� O(logn)
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