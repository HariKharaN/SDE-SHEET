#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threesum(vector<int> a)
{
    sort(a.begin(),a.end());
    vector<vector<int>> res;
    for(int i=0;i<a.size()-2;i++)
    {
        if(i==0 or (i>0 and a[i]!=a[i-1]))
        {
            int lo=i+1,hi=a.size()-1,sum=0-a[i];
            while(lo<hi)
            {
                if(a[lo]+a[hi] == sum)
                {
                    vector<int> temp;
                    temp.push_back(a[i]);
                    temp.push_back(a[lo]);
                    temp.push_back(a[hi]);
                    res.push_back(temp);
                    while(lo<hi && a[lo]==a[lo+1])  lo++;
                    while(lo<hi && a[hi]==a[hi+1])  hi--;
                    lo++;hi--;
                }
                else if(a[lo]+a[hi] < sum) lo++;
                else hi--;
            }
        }
    }
    return res;
}
int main()
{
    vector<int> r = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threesum(r);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<" " " ";
    }
    cout<<endl;
}