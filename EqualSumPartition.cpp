#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[] = {1, 6, 11, 6, 2};

	int sum = 0;

	int n = 5;

	for(int i = 0;i < n;i++)
	{
		sum+=arr[i];
	}
	if(sum%2 == 0)
	{
		sum = sum/2;
	}
	else{
		cout<<"Not possible"<<endl;
		return 0;
	}
	cout<<sum<<endl;
	int table[100][100];

	for(int i = 0;i < sum+1;i++)
		table[0][i] = 0;
	for(int i = 0;i < n+1;i++)
		table[i][0] = 1;

	for(int i = 1;i < n+1;i++)
	{
		for(int j = 1;j < sum+1;j++){
			if(arr[i-1] == j){

				table[i][j] = 1;
			}
		
			table[i][j] = table[i-1][j] || table[i-1][j-arr[i-1]];
			
		}
	}
	for(int i = 0;i < n+1;i++){
		for(int j = 0;j < sum+1;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"sum is "<<table[n][sum]<<endl;
	if(table[n][sum])
	{
		cout<<"There are 2 sets which can form the sum "<<sum<<endl;
	}
	else
	{
		cout<<"There are no 2 sets which can form the sum "<<sum<<endl;
	}
}