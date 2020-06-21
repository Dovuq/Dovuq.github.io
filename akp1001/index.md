# Different Ways to AK [luogu P1001](https://www.luogu.com.cn/problem/P1001)

[Home](/)

# 1. C

```c
#include <stdio.h>
int main ()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",a+b);
    return 0;
}
```

# 2. C++

```cpp
#include <iostream>
using namespace std;
int main ()
{
    int a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    return 0;
}
```

# 3. Pascal

```pascal
var a,b:longint;
begin
  read(a,b);
  writeln(a+b);
end.
```

# 4. Dovuque

```dovuq
print read+read
```

# 5. Djadja

```djadja
program name:=main;
main uses (2,screen,keyboard);
main begins:
    boolean function putchar(c:char);
    putchar begins:
        var x,y:integers;
        x:=screen.xnow;
        y:=screen.ynow;
        if (y=screen.width) then it begins:
            if (x=screen.height) then return false;
            y:=1;
            x:=x+1;
        it ends;
        screen.characters[x,y]:=c;
        screen.review();
        return true;
    putchar ends;
    boolean function print(x:longint);
    print begins:
        var ans:boolean;
        if (x=0) then ans:=putchar('0');
        if (ans=false) then return false;
        if (x<0) then it begins:
            ans:=putchar('-');
            if (ans=false) then return false;
            return print(-x);
        it ends;
        ans:=putchar(x div 10);
        if (ans=false) then return false;
        return putchar(chr(x mod 10+48));
    print ends;
    char function getchar();
    getchar begins:
        return keyboard.get();
    getchar ends;
    longint function read();
    read begins:
        var ch:char;
        var n,flag:longints;
        ch:=getchar();
        flag:=1;
        while (ch<'0' or ch>'9') do it begins:
            if (ch='-') then
                flag:=-flag;
            ch:=getchar();
        it ends;
        while (ch>='0' and ch<='9') do it begins:
            n:=n*10+ord(ch)-48;
            ch:=getchar();
        it ends;
        return n;
    read ends;
    nothing function f();
    f begins:
        var a,b:longints;
        a=read();
        b=read();
        print(a+b);
    f ends;
    program starts with f();
    program ends with 0;
main ends.
```

# 6. Stack & Fast I/O & A lot of #includes and #defines

```cpp
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define dq deque
#define e 2.71828182845904523536
#define elif else if
#define fo(i,a,b) for (int i=a;i<b;i++)
#define inf 2.1e9
#define inf64 9.2e18
#define inff 1e309
#define ll long long
#define lll __int128
#define loop while (1)
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define pi acos(-1)
#define pq priority_queue
#define rdz srand(time(0))
#define rd rand()
#define templ template <class T>
#define usg unsigned
using namespace std;
void read (int& x)
{
	int flag=1;
	char ch=getchar();
	x=0;
	while (ch<'0'||ch>'9') { if (ch=='-') flag=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x*=flag;
}
void print (int x)
{
	if (x<0) putchar('-'),print(-x);
	elif (!x) putchar('0');
	else { if (x/10) print(x/10); putchar(x%10+'0'); }
}
int a;
stack<int> sta;
int main ()
{
	fo(i,1,3)
	{
		read(a);
		int flag=1;
		if (a<0) flag=-1,a=-a;
		int j=0;
		while(a)
		{
			if(a&1) sta.push((j+1)*flag);
			j++;
			a>>=1;
		}
	}
	while(!sta.empty())
	{
		int j=sta.top();
		sta.pop();
		if (j>0) a+=1<<(j-1);
		else a-=1<<(-j-1);
	}
	print(a);
	return 0;
}
```

# 7. Shortest

```pascal
var a,b:int64;begin read(a,b);print(a+b);end.
```
