#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
int main (int argc,char** argv)
{
	if (argc!=2)
	{
		puts ("Bad input.");
		return 0;
	}
	system ("git add .");
	string s="git commit -m \"";
	s+=argv[1];
	s+="\"";
	system (s.c_str());
	system ("git push origin master");
} 
