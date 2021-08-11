#include<bits/stdc++.h>
using namespace std;
void FindComb2(int ind,int t,vector<int>& r,vector<vector<int>>& ans,vector<int>& ds)
{
    if(t == 0)
    {
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<r.size();i++)
    {
        if(i>ind and r[i] == r[i-1])
            continue;
        if(r[i] > t)
            break;
        ds.push_back(r[i]);
        FindComb2(i+1,t-r[i],r,ans,ds);
        ds.pop_back();
    }
   
}
vector<vector<int>> CombinationSum2(vector<int> r, int t)
{
    sort(r.begin(),r.end());
    vector<vector<int>> ans;
    vector<int> ds;
    FindComb2(0,t,r,ans,ds);
    return ans;
}
int main()
{
    vector<int> r = {1,1,1,2,2};
    int t = 4;
    vector<vector<int>> res = CombinationSum2(r,t);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<"+";
        }
        cout<<" ";
    }
}