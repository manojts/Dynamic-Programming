#include <bits/stdc++.h>
using namespace std;
int Max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}
int main()
{
	string s1 = "axy";
	string s2 = "acxby";
	int table[s1.length()+1][s2.length()+1];
	for(int i = 0;i < s1.length()+1;i++)
	{
		table[i][0] = 0;
	}
	for(int j = 0;j < s2.length()+1;j++)
	{
		table[0][j] = 0;
	}
	for(int i = 1;i < s1.length()+1; i++)
	{
		for(int j = 1;j < s2.length()+1; j++)
		{
			
			if(s1[i-1] == s2[j-1])
			{
				table[i][j] = 1 + table[i-1][j-1];
			}
			else
			{
				table[i][j] = Max(table[i-1][j], table[i][j-1]);
			}
		}
	}
	int lcs = table[s1.length()][s2.length()];
	int minLength;
	if(s1.length() < s2.length())
	{
		minLength = s1.length();
	}
	else
	{
		minLength = s2.length();
	}
	if(minLength == lcs)
	{
		cout<<"Sequence Matched";
	}
	else
	{
		cout<<"Sequence not matched";
	}
}