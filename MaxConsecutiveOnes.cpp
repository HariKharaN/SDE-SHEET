#include<bits/stdc++.h>
using namespace std;
int MaxConsOnes(vector<int> r)
{
    int count=0,maxi = 0;
    for(int i=0;i<r.size();i++)
    {
        if(r[i] == 1)
            count++;
        else    
            count=0;

        maxi = max(count,maxi);
    }
    return maxi;
}
int main()
{
    vector<int> r = {1,1,0,1,1,1,1,1,1};
    int res = MaxConsOnes(r);
    cout<<res;
}