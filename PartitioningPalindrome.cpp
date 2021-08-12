#include<bits/stdc++.h>
using namespace std;

bool isPal(string s , int start , int end)
{
    while(start<=end)
    {
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}
void func(int index, string s, vector<vector<string>>& res, vector<string> ds)
{
    if(index == s.size())
    {
        res.push_back(ds);
        return;
    }
    for(int i=index;i<s.size();i++)
    {
        if(isPal(s,index,i))
        {
            ds.push_back(s.substr(index,i-index+1));
            func(i+1,s,res,ds);
            ds.pop_back();
        }
    }
}
vector<vector<string>> partitioning(string s)
{
    vector<vector<string>> res;
    vector<string> ds;
    func(0,s,res,ds);
    return res;
}
int main()
{
    string s = "aabb";
    vector<vector<string>> res = partitioning(s);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<"/";
        }
        cout<<" ";
    }
}