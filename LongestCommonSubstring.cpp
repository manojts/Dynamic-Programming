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
	string s1 = "geeksabcfor";
	string s2 = "geeksa";
	int table[s1.length()+1][s2.length()+1];
	for(int i = 0;i < s1.length()+1;i++)
	{
		table[i][0] = 0;
	}
	for(int j = 0;j < s2.length()+1;j++)
	{
		table[0][j] = 0;
	}
	int result = 0;
	for(int i = 1;i < s1.length()+1; i++)
	{
		for(int j = 1;j < s2.length()+1; j++)
		{		
			if(s1[i-1] == s2[j-1])
			{
				table[i][j] = 1 + table[i-1][j-1];
				result = Max(result, table[i][j]);
			}
			else
			{
				table[i][j] = 0;
			}
		}
	}
	cout<<"Longest Common Sub string length is "<<result;
}