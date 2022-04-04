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
	string s1 = "heap";
	string s2 = "pea";
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

	int p = s1.length();
	int q = s2.length();
	int lcs = table[p][q];
	cout<<"Longest Common Sub sequence length is "<<lcs<<endl;
	cout<<"Number of Deletions "<<p - lcs<<endl;
	cout<<"Number of Insertions "<<q - lcs<<endl;
}