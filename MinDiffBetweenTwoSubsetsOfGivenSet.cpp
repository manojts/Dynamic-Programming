#include <bits/stdc++.h>
using namespace std;
/*	
	to find the two subsets such that the difference between the sum of two subsets 
	is minimum

	Solution:

	Find the sum of the array given which will be the max limit of the range .

	find the sum with sub set array elements such that 

	the difference between the range and 2(sum) is minimum

*/

int main(){
	int arr[] = {1, 6, 5, 11};
	int table[100][100];
	int sum = 0;
	int range = 0;
	int size = 4;
	for(int i = 0;i < size;i++)
	{
		range += arr[i];
	}

	for(int i = 0;i < range+1;i++){
		table[0][i] = 0;
	}

	for(int i = 0;i < size+1;i++){
		table[i][0] = 1;
	}

	for(int i = 1;i < size+1;i++)
	{
		for(int j = 1;j < range+1;j++)
		{
			if(arr[i-1] > j)
			{
				table[i][j] = table[i-1][j];
			}
			else
			{
				table[i][j] = table[i-1][j] || table[i-1][j-arr[i-1]];
			}
		}
	}

	for(int i = 0;i < size+1;i++)
	{
		for(int j = 0;j < range+1;j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int min = 99999;
	for(int i = 0;i <= range/2;i++){
		if(table[size][i]){
			if(min > (range-2*i))
			{	
				min = range - (2*i);
				sum = i;
			}
		}
	}
	cout<<"Minimum difference between the two sets "<<min<<endl;
}