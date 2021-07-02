#include<bits/stdc++.h>
using namespace std;
vector<int> TwoSumprobelm(vector<int> v,int t)
{
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<v.size();i++)
    {
        if(mp.find(t - v[i]) != mp.end())
        {
            ans.push_back(mp[t - v[i]]);
            ans.push_back(i);
            return ans;
        }
        mp[v[i]]=i;
    }
    return ans;
}
int main()
{
    int n,t;
    cout<<"ENTER THE ARRAY SIZE : ";
    cin>>n;
    cout<<"ENTER THE ARRAY ELEMENTs : ";
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v.at(i);
    cout<<"ENTER THE TAGET VALUE : ";
    cin>>t;
    vector<int> ans = TwoSumprobelm(v,t);
    cout<<"THE INDEX OF THE TARGET PAIR VALUE : ";
    for(auto x: ans)
        cout<<x<<" ";
    cout<<endl;
}   