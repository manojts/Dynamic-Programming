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
	string input = "agbcba";
	string s1 = input;
	reverse(s1.begin(), s1.end());
	int table[input.length()+1][s1.length()+1];
	for(int i = 0;i < input.length()+1;i++)
	{
		table[i][0] = 0;
	}
	for(int j = 0;j < s1.length()+1;j++)
	{
		table[0][j] = 0;
	}
	for(int i = 1;i < input.length()+1; i++)
	{
		for(int j = 1;j < s1.length()+1; j++)
		{
			
			if(input[i-1] == s1[j-1])
			{
				table[i][j] = 1 + table[i-1][j-1];
			}
			else
			{
				table[i][j] = Max(table[i-1][j], table[i][j-1]);
			}
		}
	}
	int lpsLength = table[input.length()][s1.length()];
	int len = input.length();
	cout<<"Minimum Deletion to make string "<<input<<" Palindrome is "<< (len - lpsLength);
}