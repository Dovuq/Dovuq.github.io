# Games **For Windows**

[Home](/)

# 扫雷

[link](#扫雷source)

# 2048

[link](#2048source)

# 跳棋

[link](#跳棋source)

<!--more-->

# 扫雷source

```cpp
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
char ans[105][105],now[105][105];
int n,m,bnum;
const int dx[]={-1,-1,-1,0,0,1,1,1};
const int dy[]={-1,0,1,-1,1,-1,0,1};
void go ()
{
	memset (ans,' ',sizeof(ans));
	memset (now,'?',sizeof(now));
	srand(time(NULL));
	for (int i=0;i<bnum;i++)
		while (1)
		{
			int x=rand()%n;
			int y=rand()%m;
			if (ans[x][y]=='*') continue;
			ans[x][y]='*';
			for (int j=0;j<8;j++)
			{
				int xx=x+dx[j];
				int yy=y+dy[j];
				if (xx<0||xx>=n||yy<0||yy>=m) continue;
				switch (ans[xx][yy])
				{
				case ' ':
					ans[xx][yy]='1';
					break;
				case '*':
					break;
				default:
					ans[xx][yy]++;
				}
			}
			break;
		}
}
void printmap ()
{
	printf ("   ");
	for (int i=0;i<m;i++)
		printf ("%3d",i);
	printf ("\n");
	for (int i=0;i<n;i++)
	{
		printf ("%3d",i);
		for (int j=0;j<m;j++)
			printf ("  %c",now[i][j]);
 		printf ("\n");
 	}
	printf ("\n");
	printf ("-------------------------------------\n");;
	printf ("Tips:\n");
	printf ("Input 0 x y to click(x,y).\n");
	printf ("Input 1 x y to mark (x,y).\n");
	printf ("Input 2 to restart.\n");
	printf ("-------------------------------------\n");
	printf ("I want:\n");
}
void printans ()
{
	printf ("   ");
	for (int i=0;i<m;i++)
		printf ("%3d",i);
	printf ("\n");
	for (int i=0;i<n;i++)
	{
		printf ("%3d",i);
		for (int j=0;j<m;j++)
			printf ("  %c",ans[i][j]);
 		printf ("\n");
 	}
 	printf ("\n");
}
void k (int x,int y)
{
	now[x][y]=ans[x][y];
	for (int j=0;j<8;j++)
	{
		int xx=x+dx[j];
		int yy=y+dy[j];
		if (xx<0||xx>=n||yy<0||yy>=m) continue;
		if (ans[xx][yy]==' '&&now[xx][yy]=='?')
			k (xx,yy);
		else now[xx][yy]=ans[xx][yy];
	}
}
bool doit (int t,int x,int y)
{
	switch (t)
	{
	case 1:
		if (now[x][y]=='!')
			now[x][y]='?';
		else if (now[x][y]=='?')
			now[x][y]='!';
		return 1;
	case 0:
		if (ans[x][y]=='*')
			return 0;
		if (ans[x][y]==' ')
			k (x,y);
		else now[x][y]=ans[x][y];
		return 1;
	}
}
int main ()
{
	printf ("Welcome to Minesweeper!\n");
	Sleep (2000);
	while (1)
	{
		int win=1;
		system ("cls");
		printf ("How many rows(3..100):\n");
		while (1)
		{
			scanf ("%d",&n);
			if (n>=3&&n<=100)
				break;
			printf ("Wrong, input again!\n");
		}
		system ("cls");
		printf ("How many columns(3..100):\n");
		while (1)
		{
			scanf ("%d",&m);
 			if (m>=3&&m<=100)
				break;
			printf ("Wrong, input again!\n");
		}
		system ("cls");
		printf ("How many mines(1..%d):\n",(int)(n*m*0.85));
		while (1)
		{
			scanf ("%d",&bnum);
			if (bnum>=1&&bnum<=n*m*0.85)
				break;
			printf ("Wrong, input again!\n");
		}
		system ("cls");
		go ();
		printf ("Ready?");
		Sleep (800);
		system ("cls");
		printf ("Go!");
		Sleep (800);
		while (1)
		{
			system ("cls");
			printmap ();
			int t,x,y;
			scanf ("%d",&t);
			if (t==2) break;
			scanf ("%d%d",&x,&y);
			if (t<0||t>=3||x<0||x>=n||y<0||y>=m)
			{
				printf ("Wrong\n");
				Sleep (800);
			}
			else
			{
				bool ok=doit (t,x,y);
				if (!ok)
				{
					win=0;
					break;
				}
			}
			int p=0;
			for (int i=0;i<n;i++)
				for (int j=0;j<m;j++)
					if (now[i][j]=='?'||now[i][j]=='!')
						p++;
			if (p==bnum)
			{
				win=2;
				break;
			}
		}
		system ("cls");
		printans ();
		if (win==0)
		{
			printf ("\n\nPlease try again!\n");
		}
		else if (win==2)
		{
			printf ("\n\nYou won!\n");
		}
		Sleep (1000);
		system("pause");
	}
}
```

# 2048source

```cpp
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
char sel;
string a[105],p[25][25];
int b[505][3],n,m,d[25][25];
int size,width;
void setup0 ()
{
	n=19;
	m=18;
	size=4;
	width=6;
	a[0]="2";
	a[1]="4";
	a[2]="8";
	a[3]="16";
	a[4]="32";
	a[5]="64";
	a[6]="128";
	a[7]="256";
	a[8]="512";
	a[9]="1024";
	a[10]="2048";
	a[11]="4096";
	a[12]="8192";
	a[13]="16384";
	a[14]="32768";
	a[15]="65536";
	a[16]="131072";
	a[17]="262144";
	a[18]="524288";
	for (int i=0;i<18;i++)
		b[i][0]=b[i][1]=i, b[i][2]=i+1;
	for (int i=0;i<size;i++)
		for (int j=0;j<size;j++)
		{
			p[i][j]=" ";
			d[i][j]=-1;
		}
	int x=rand()%size,y=rand()%size;
	p[x][y]=a[0];
	d[x][y]=0;
	system ("cls");
}
void setup1 ()
{
p:	puts ("Input setup, input -1 for information:");
	scanf ("%d",&n);
	if (n==-1)
	{
		puts ("");
		puts ("Syntax of input:");
		puts ("n s // n: number of diff blocks, s: size of border (s*s)");
		puts ("a[0] // the smallest number, it can be string, but not too long");
		puts ("a[1] // etc.");
		puts ("......");
		puts ("a[n-1] // if you reach this, you win");
		puts ("x y z // when a[x] reaches a[y], they merge into a[z]");
		puts ("x y z // etc.");
		puts ("......");
		puts ("-1 -1 -1 // symbol of end of input");
		puts ("");
		goto p;
	}
	scanf ("%d",&size);
	width=0;
	for (int i=0;i<n;i++)
	{
		printf ("%d ",i);
		cin>>a[i];
		width=max(width,(int)a[i].length());
	}
	for (int i=0;;i++)
	{
		scanf ("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
		if (b[i][0]==-1)
		{
			m=i;
			break;
		}
	}
	for (int i=0;i<size;i++)
		for (int j=0;j<size;j++)
		{
			p[i][j]=" ";
			d[i][j]=-1;
		}
	int x=rand()%size,y=rand()%size;
	p[x][y]=a[0];
	d[x][y]=0;
	system ("cls");
}
void print ()
{
	puts ("¡ü¡ý¡û¡ú: Move");
	puts ("Esc: Main menu");
	for (int k=0;k<size;k++)
	{
		for (int i=0;i<size;i++)
		{
			putchar (' ');
			for (int j=0;j<width+2;j++)
				putchar ('-');
		}
		putchar (10);
		for (int i=0;i<size;i++)
		{
			putchar ('|');
			for (int j=0;j<width+2;j++)
				putchar (' ');
		}
		putchar ('|');
		putchar (10);
		for (int i=0;i<size;i++)
			cout<<"| "<<setw(width)<<p[k][i]<<" ";
		putchar ('|');
		putchar (10);
		for (int i=0;i<size;i++)
		{
			putchar ('|');
			for (int j=0;j<width+2;j++)
				putchar (' ');
		}
		putchar ('|');
		putchar (10);
	}
	for (int i=0;i<size;i++)
	{
		putchar (' ');
		for (int j=0;j<width+2;j++)
			putchar ('-');
	}
	putchar (10);
}
void play ()
{
	while (1)
	{
		print ();
		int dir=0;
		while (1)
		{
			sel=getch();
			switch (sel)
			{
			case -32:
				switch (getch())
				{
				case 72:
					dir=1;
					break;
				case 75:
					dir=2;
					break;
				case 80:
					dir=3;
					break;
				case 77:
					dir=4;
					break;
				default:
					puts ("Wrong, try again.");
				}
				break;
			case 27:
				return;
			default:
				printf ("%d ",sel);
				puts ("Wrong, try again.");
			}
			if (dir) break;
			Sleep (1000);
		}
		puts ("Moving . . .");
		switch (dir)
		{
		case 1:
			for (int j=0;j<size;j++)
				for (int i=0;i<size;)
				{
					if (i==0 || p[i][j]==" ")
					{
						i++;
						continue;
					}
					if (p[i-1][j]==" ")
					{
						p[i-1][j]=p[i][j];
						d[i-1][j]=d[i][j];
						p[i][j]=" ";
						d[i--][j]=-1;
						continue;
					}
					for (int k=0;k<m;k++)
						if (d[i][j]==b[k][0] && d[i-1][j]==b[k][1]
							|| d[i][j]==b[k][1] && d[i-1][j]==b[k][0])
						{
							p[i-1][j]=a[b[k][2]];
							d[i-1][j]=b[k][2];
							p[i][j]=" ";
							d[i][j]=-1;
							i-=2;
							if (b[k][2]==n-1)
							{
								puts ("You won!");
								return;
							}
							break;
						}
					i++;
				}
			break;
		case 2:
			for (int i=0;i<size;i++)
				for (int j=0;j<size;)
				{
					if (j==0 || p[i][j]==" ")
					{
						j++;
						continue;
					}
					if (p[i][j-1]==" ")
					{
						p[i][j-1]=p[i][j];
						d[i][j-1]=d[i][j];
						p[i][j]=" ";
						d[i][j--]=-1;
						continue;
					}
					for (int k=0;k<m;k++)
						if (d[i][j]==b[k][0] && d[i][j-1]==b[k][1]
							|| d[i][j]==b[k][1] && d[i][j-1]==b[k][0])
						{
							p[i][j-1]=a[b[k][2]];
							d[i][j-1]=b[k][2];
							p[i][j]=" ";
							d[i][j]=-1;
							j-=2;
							if (b[k][2]==n-1)
							{
								puts ("You won!");
								return;
							}
							break;
						}
					j++;
				}
			break;
		case 3:
			for (int j=0;j<size;j++)
				for (int i=size-1;i>=0;)
				{
					if (i==size-1 || p[i][j]==" ")
					{
						i--;
						continue;
					}
					if (p[i+1][j]==" ")
					{
						p[i+1][j]=p[i][j];
						d[i+1][j]=d[i][j];
						p[i][j]=" ";
						d[i++][j]=-1;
						continue;
					}
					for (int k=0;k<m;k++)
						if (d[i][j]==b[k][0] && d[i+1][j]==b[k][1]
							|| d[i][j]==b[k][1] && d[i+1][j]==b[k][0])
						{
							p[i+1][j]=a[b[k][2]];
							d[i+1][j]=b[k][2];
							p[i][j]=" ";
							d[i][j]=-1;
							i+=2;
							if (b[k][2]==n-1)
							{
								puts ("You won!");
								return;
							}
							break;
						}
					i--;
				}
			break;
		case 4:
			for (int i=0;i<size;i++)
				for (int j=size-1;j>=0;)
				{
					if (j==size-1 || p[i][j]==" ")
					{
						j--;
						continue;
					}
					if (p[i][j+1]==" ")
					{
						p[i][j+1]=p[i][j];
						d[i][j+1]=d[i][j];
						p[i][j]=" ";
						d[i][j++]=-1;
						continue;
					}
					for (int k=0;k<m;k++)
						if (d[i][j]==b[k][0] && d[i][j+1]==b[k][1]
							|| d[i][j]==b[k][1] && d[i][j+1]==b[k][0])
						{
							p[i][j+1]=a[b[k][2]];
							d[i][j+1]=b[k][2];
							p[i][j]=" ";
							d[i][j]=-1;
							j+=2;
							if (b[k][2]==n-1)
							{
								puts ("You won!");
								return;
							}
							break;
						}
					j--;
				}
		}
		for (int i=0;;i++)
		{
			int x=rand()%size,y=rand()%size;
			if (p[x][y]==" ")
			{
				p[x][y]=a[0];
				d[x][y]=0;
				break;
			}
			if (i>=size*size*100)
			{
				puts ("You lose!");
				return;
			}
		}
		system ("cls");
	}
}
int main ()
{
	srand(time(0));
	while (1)
	{
		puts ("****************MENU****************");
		puts ("1. Default");
		puts ("2. Setup");
		puts ("0. Exit");
		puts ("************************************");
		sel=getch();
		switch (sel)
		{
		case '1':
			setup0 ();
			play ();
			break;
		case '2':
			setup1 ();
			play ();
			break;
		case '0':
			puts ("Bye!");
			return 0;
		default:
			puts ("Wrong, try again.");
		}
		Sleep (2000);
		system ("cls");
	}
}
```

# 跳棋source

```cpp
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#define N 17
#define loop while(1){
#define end }
#define elif else if
using namespace std;
const int dx[]={-1,-1,0,0,1,1};
const int dy[]={-1,0,-1,1,0,1};
const char a[][105]={"",
bcb o
};
char mp[20][20]={
	"####4############",
	"####44###########",
	"####444##########",
	"####4444#########",
	"5555.....3333####",
	"#555......333####",
	"##55.......33####",
	"###5........3####",
	"####.........####",
	"####6........2###",
	"####66.......22##",
	"####666......222#",
	"####6666.....2222",
	"#########1111####",
	"##########111####",
	"###########11####",
	"############1####"
};
char num[20][20]={
	"####0############",
	"####12###########",
	"####345##########",
	"####6789#########",
	"0123.....0123####",
	"#456......456####",
	"##78.......78####",
	"###9........9####",
	"####.........####",
	"####0........0###",
	"####12.......12##",
	"####345......345#",
	"####6789.....6789",
	"#########0123####",
	"##########456####",
	"###########78####",
	"############9####"
};
char info[20][20],now;
void dfs (int x,int y)
{
	for (int i=0;i<6;i++)
	{
		int xx,yy,tx,ty;
		xx=x+dx[i];
		yy=y+dy[i];
		tx=x+2*dx[i];
		ty=y+2*dy[i];
		if (xx>=0 && xx<N && yy>=0 && yy<N && tx>=0 && tx<N && ty>=0 && ty<N &&
			mp[xx][yy]>'0' && mp[xx][yy]<'7' && mp[tx][ty]=='.' && info[tx][ty]==' ')
		{
			info[tx][ty]=now++;
			dfs (tx,ty);
		}
	}
}
void printmap (char per,char che)
{
	memset (info,' ',sizeof(info));
	now='a';
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			if (mp[i][j]==per && num[i][j]==che)
			{
				dfs (i,j);
				for (int k=0;k<6;k++)
				{
					int xx,yy;
					xx=i+dx[k];
					yy=j+dy[k];
					if (xx>=0 && xx<N && yy>=0 && yy<N && mp[xx][yy]=='.')
						info[xx][yy]=now++;
				}
			}
	puts (a[per-'0']);
	for (int i=0;i<N;i++)
	{
		for (int j=i;j<N;j++)
			putchar (32);
		for (int j=0;j<N;j++)
		{
			if (mp[i][j]=='#') printf ("  ");
			elif (mp[i][j]==per) printf ("%c ",num[i][j]);
			elif (mp[i][j]=='.')
			{
				if (info[i][j]==' ') printf (". ");
				else printf ("%c ",info[i][j]);
			}
			else printf ("# ");
		}
		putchar (10);
	}
	printf ("Press a~%c to move.\n",now-1);
	puts ("Press 1 to cancel.");
	puts ("Press 2 to quit.");
}
void printmap (char per)
{
	puts (a[per-'0']);
	for (int i=0;i<N;i++)
	{
		for (int j=i;j<N;j++)
			putchar (32);
		for (int j=0;j<N;j++)
		{
			if (mp[i][j]=='#') printf ("  ");
			elif (mp[i][j]==per) printf ("%c ",num[i][j]);
			elif (mp[i][j]=='.') printf (". ");
			else printf ("# ");
		}
		putchar (10);
	}
	puts ("Press 0~9 to move.");
	puts ("Press s to skip.");
	puts ("Press q to quit.");
}
int main ()
{
	loop for (int i=1;i<=6;i++)
	{
		char ch,ch2;
p:		printmap (i+'0');
		loop
			ch=getch ();
			if ((ch<'0' || ch>'9') && ch!='s' && ch!='q')
				puts ("Wrong, try again!");
			else break;
		end
		system ("cls");
		if (ch=='s') continue;
		elif (ch=='q') return 0;
		ch2=ch;
		printmap (i+'0',ch2);
		loop
			ch=getch ();
			if ((ch<'a' || ch>=now) && ch!='1' && ch!='2')
				puts ("Wrong, try again!");
			else break;
		end
		system ("cls");
		if (ch=='1') goto p;
		elif (ch=='2') break;
		int i1,j1,i2,j2;
		for (int x=0;x<N;x++)
			for (int y=0;y<N;y++)
			{
				if (mp[x][y]==i+'0' && num[x][y]==ch2)
					i1=x,j1=y;
				elif (info[x][y]==ch)
					i2=x,j2=y;
			}
		swap (mp[i1][j1],mp[i2][j2]);
		swap (num[i1][j1],num[i2][j2]);
		printmap (i+'0');
		getch ();
		system ("cls");
	} end
}
```
