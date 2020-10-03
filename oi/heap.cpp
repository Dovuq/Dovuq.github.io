// ��
inline bool cmp (int a,int b)
{
    // ��� a Ӧ�ó�Ϊ b �ĸ��ڵ㣬���� true�����򷵻� false
    // ʱ�临�Ӷ�һ��Ϊ O(1)
}
struct HEAP
{
    int val[size],n;

    // �ڶ��в������ݣ�ʱ�临�Ӷ� O(logn)
    void add (int x)
    {
        val[++n]=x;
        for (int m=n;m>1 && cmp(val[m],val[m/2]);m/=2)
            swap (val[m],val[m/2]);
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