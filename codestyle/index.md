# My Code Style for OI

[Home](https://dovuque.github.io)

# c++

建议使用例子：

```cpp
#include <bits/stdc++.h>
using namespace std;
struct bigint
{
    int size,num[5005];
    bigint()
    {
        size=0;
        memset (num,0,sizeof(num));
    }
};
int n;
bigint ans,a[2025];
bigint cal (bigint x,bigint y)
{
    if (x.size<y.size) swap(x,y);
    bigint c;
    c.size=x.size;
    int d=0;
    for (int i=0;i<x.size;i++)
    {
        c.num[i]+=x.num[i]+y.num[i]+d;
        d=(c.num[i]<7?0:(c.num[i]<14?1:2));
        c.num[i]%=10;
    }
    if (d) c.num[c.size++]=d;
    return c;
}
istream& operator>> (istream &is,bigint &x)
{
    int n,i=0;
    is>>n;
    for (;n;i++)
    {
        x.num[i]=n%10;
        n/=10;
    }
    x.size=i;
    return is;
}
ostream& operator<< (ostream &os,bigint x)
{
    for (int i=x.size-1;i>=0;i--)
        os<<x.num[i];
    return os;
}
int main ()
{
    scanf ("%d",&n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    ans=a[0];
    for (int i=1;i<n;i++)
        ans=cal(ans,a[i]);
    cout<<ans;
    return 0;
}
```

不建议使用例子：

```cpp
# include<bits/stdc++.h>
using namespace std ;
struct bigint{
    int size;
    int num[5005];
    bigint() { size=0; memset (num,0,sizeof(num)); }
};
int n;
bigint ans , a[2025];
bigint cal (bigint x , bigint y) {
    if (x.size < y.size) swap(x,y);
    bigint c;
    c.size =x.size;
    int d=0;
    for( int i = 0 ; i < x . size ; ++ i )
    {
        c.num[i]+=x.num[i]+y.num[i]+d;
        d = c.num[i] < 7 ? 0 : c.num[i] < 14 ? 1 : 2 ;
        c.num[i]%=10 ;
    }
    if (d) c.num[c.size++]=d;
    return c;
}
istream& operator>> (istream &is,bigint &x)
{
  int n,i=0;
  is>>n;
  for (;n;i++)
  {
    x.num[i]=n%10;
    n/=10;
  }
  x.size=i;
  return is;
}
ostream& operator<< (ostream &os,bigint x)
{
        for (int i=x.size-1;i>=0;i--)
                os<<x.num[i];
        return os;
}
int main ()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    ans = a [ 1 ] ;
    for (int i=2;i<=n;i++)
        ans=cal(ans,a[i]);
    cout<<ans;
    return 0;
}
```

# Markdown

建议使用例子：

```markdown
# H1

## H2

### H3

**Bold**, *Italic*, and ~~Strikeout~~.

This is a paragraph.

This is another paragraph.

> Quote.

- 1
- 2
- 3

1. 1
2. 2
3. 3

1. 1
1. 2
1. 3
```

不建议使用例子：

```markdown
H1
===

H2
---

###H3

__Bold__, * Italic * , and ~~Strikeout~~.

This is a paragraph.
This is another paragraph.

* 1
* 2
* 3

+ 1
+ 2
+ 3
```

# LaTeX

# Dovuque
