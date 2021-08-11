#include<bits/stdc++.h>
using namespace std;
void Findsubsets(int ind,vector<int>& r,vector<int>& ds,vector<vector<int>>& ans)
{
    ans.push_back(ds);
    for(int i=ind;i<r.size();i++)
    {
        if(i!=ind && r[i] == r[i-1])
            continue;
        ds.push_back(r[i]);
        Findsubsets(i+1,r,ds,ans);
        ds.pop_back();
    }
}
vector<vector<int>> Subsets2(vector<int> r)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(r.begin(),r.end());
    Findsubsets(0,r,ds,ans);
    return ans;
}

int main()
{
    vector<int> r = {1,2,2,2,3,3};
    vector<vector<int>> res = Subsets2(r);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j];
        }
        cout<<" ";
    }
}