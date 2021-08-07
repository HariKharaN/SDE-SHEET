#include<bits/stdc++.h>
using namespace std;
int MinimumNoPlatforms(vector<int> arr,vector<int> dep,int n)
{
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int plat = 1,res = 1;
    int i=1,j=0;
    while(i<n and j<n)
    {
        if(arr[i]<=dep[j])
        {
            plat++;
            i++;
        }
        else if(arr[i]>dep[j])
        {
            plat--;
            j++;
        }
        if(plat>res)
            res = plat;
    }
    return res;
}
int main()
{
    vector<int> s = {50,120,200,440,700,850};
    vector<int> f = {500,200,520,600,900,900};
    int n = s.size();
    int res = MinimumNoPlatforms(s,f,n);
    cout<<res;
}