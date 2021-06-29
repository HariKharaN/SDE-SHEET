#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> pascaltraingle(int n)
{
    vector<vector<int>> r(n);

    for(int i=0;i<n;i++)
    {
        r[i].resize(i+1);
        r[i][0] = r[i][i] = 1;

        for(int j=1;j<i;j++)
            r[i][j] = r[i-1][j-1]+r[i-1][j];
    }
    return r;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> res = pascaltraingle(n);
    int rows = res.size();
  
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}