#include <bits/stdc++.h>
using namespace std;
int Max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	int coins[]={2, 3, 5, 10};
	int sum = 15;
	int size = 4;

	int table[size+1][sum+1] = {0};

	for(int i = 0;i <= size;i++)
		table[i][0] = 1;
	
	for(int i=1;i<=sum;i++)
		table[0][i] = 0;

	for(int i = 1;i <= size;i++)
	{
		for(int j = 1;j <= sum;j++)
		{
			if(coins[i-1] > j)
				table[i][j] = table[i-1][j];
			else
				table[i][j] = (table[i][j-coins[i-1]] + table[i-1][j]);
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Number of ways of getting Coins Change "<<table[size][sum];
}