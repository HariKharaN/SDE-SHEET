#include<bits/stdc++.h>
using namespace std;

void permuationAll(int index , vector<int>& r, vector<vector<int>>& ans)
{
    if(index == r.size())
    {
        ans.push_back(r);
        return;
    }
    for(int i=index;i<r.size();i++)
    {
        swap(r[index],r[i]);
        permuationAll(index+1 , r, ans);
        swap(r[index],r[i]);
    }
}

vector<vector<int>> perm(vector<int> r)
{
    vector<vector<int>> ans;
    permuationAll(0,r,ans);
    return ans;        
}

int main()
{
    vector<int> r ={1,2,3};
    vector<vector<int>> res = perm(r);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<"+";
        }
        cout<<" ";
    }
}