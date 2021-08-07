#include<bits/stdc++.h>
using namespace std;
void func(int ind , int sum , vector<int>& r,int n,vector<int>& sumsub)
{
    if(ind == n)
    {
        sumsub.push_back(sum);
        cout<<sum<<" ";
        return;
    }
    func(ind+1,sum+r[ind],r,n,sumsub);
    func(ind+1,sum,r,n,sumsub);
}
vector<int> Subsetsum(vector<int> r , int n)
{
    vector<int> sumsub;
    func(0,0,r,n,sumsub);
    sort(sumsub.begin(),sumsub.end());
    return sumsub;
}
int main()
{
    vector<int> r = {3,1,2};
    int n = r.size();
    vector<int> res = Subsetsum(r,n);
    for(auto x : res)
        cout<<x<<" ";

}