#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> rotate90(vector<vector<int>> a)
{
    int n=a.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            swap(a[i][j],a[j][i]);
    
    for(int i=0;i<n;i++)
        reverse(a[i].begin(),a[i].end());
    
    return a;
}
int main()
{
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    // cout<<a.size();
    vector<vector<int>> result =  rotate90(a);
    int rows = result.size();
    // int cols = result[0].size();
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}