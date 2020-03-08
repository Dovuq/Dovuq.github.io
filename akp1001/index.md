# Different Ways to AK [luogu P1001](https://www.luogu.com.cn/problem/p1001)

[Home](https://dovuque.github.io/)

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
