// Largsubarwith0
#include<bits/stdc++.h>
using namespace std;
int Largestsubarry(vector<int> a)
{
    unordered_map<int,int> mp;
    int sum=0,maxi=0;
    for(int i=0;i<a.size();i++)
    {
        sum += a[i];
        if(sum == 0)
            maxi = i+1;
        else
        {
            if(mp.find(sum) != mp.end())
                maxi = max(maxi, i-mp[sum]);
            else
                mp[sum] = i;
        }
    }
    return maxi;
}
int main()
{
    int n;
    cout<<"ENTER THE SIZE OF THE ARRAY : ";
    cin>>n;
    vector<int> v(n);
    cout<<"ENTER THE ARRAY ELEMENTS : ";
    for(int i=0;i<n;i++)
        cin>>v.at(i);
    int res = Largestsubarry(v);
    cout<<"THE LARGEST SUBARRAY WIHT SUM 0 IN THE ARRY IS : "<<res;
}