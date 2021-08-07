#include<bits/stdc++.h>
using namespace std;
vector<int> MinNoOfcoins(vector<int> r,int V)
{
    int n=r.size();
    vector<int> res;
    for(int i=n-1;i>=0;i--)
    {
        while(V>=r[i])
        {
            V -= r[i];
            res.push_back(r[i]);
        }
    }
    return res;
}
int main()
{
    vector<int> r = {1,2,5,10,20,50,100,500,1000};
    int V=49;
    vector<int> res = MinNoOfcoins(r,V);
    for(auto x : res)
        cout<<x<<" ";
    cout<<endl;
    // cout<<"Minimum No of coins to make the V : "<<res.size();
}