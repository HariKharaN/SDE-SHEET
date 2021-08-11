#include<bits/stdc++.h>
using namespace std;

void FindComb(int ind,int t,vector<int>& r,vector<vector<int>>& ans,vector<int>& ds)
{
    if(ind == r.size())
    {
        if(t == 0)
            ans.push_back(ds);
        return;
    }
    // picking
    if(r[ind] <= t)
    {
        ds.push_back(r[ind]);
        FindComb(ind,t-r[ind],r,ans,ds);
        ds.pop_back();
    }
    // Not pickking the same index
    FindComb(ind+1,t,r,ans,ds);
}

vector<vector<int>> CombinationSum1(vector<int> r, int t)
{
    vector<vector<int>> ans;
    vector<int> ds;
    FindComb(0,t,r,ans,ds);
    return ans;
}
int main()
{
    vector<int> r = {2,3,6,7};
    int t = 7;
    vector<vector<int>> res = CombinationSum1(r,t);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<"+";
        }
        cout<<" ";
    }
}