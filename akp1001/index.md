# Different Ways to AK [luogu P1001](https://www.luogu.com.cn/problem/p1001)

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
main uses (1,screen);
main begins:
    boolean function putchar (c:char);
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
```
