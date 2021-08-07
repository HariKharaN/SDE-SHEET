#include<bits/stdc++.h>
using namespace std;
int trapped(vector<int> r)
{
    int n=r.size();
    int left = 0, right=n-1,res = 0,maxleft = 0,maxright = 0;
    while(left<=right)
    {
        if(r[left]<=r[right])
        {
            if(r[left]>=maxleft)
                maxleft= r[left];
            else    
                res += maxleft  - r[left];
            left++;
        }
        else
        {
            if(r[right]>=maxright)
                maxright= r[right];
            else    
                res += maxright  - r[right];
            right--;
        }
    }
    return res;
}
int main()
{
    vector<int> r = {1,0,2,1,0,1,3,2,1,2,1};
    int res = trapped(r);
    cout<<res;
}