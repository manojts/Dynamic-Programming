#include <bits/stdc++.h>
using namespace std;
int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int main(int argc, char const *argv[])
{
    int wt[] = {1,3,4,5,2};
    int val[] = {1,4,5,8,2};
    int capacity = 7;
    int n = 5   ;//size of weight array
    int w = capacity;//value of capacity
    int table[100][100];
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < capacity + 1 ; j++)
        {
            if(i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            else
            {
                table[i][j] = max(table[i-1][j], val[i-1] + table[i-1][j-wt[i-1]]);
            }
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Maximum profit "<<table[n][w]<<endl;
    return 0;
}