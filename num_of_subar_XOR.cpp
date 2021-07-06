// num_of_subar_XOR
#include<bits/stdc++.h>
using namespace std;
int numofsubarrayXOR(vector<int> a,int t)
{
    map<int,int> mp;
    int count=0,xorr = 0;
    for(auto i : a)
    {
        xorr = xorr^i;
        if(xorr == t)
            count++;
        if(mp.find(xorr^t) != mp.end())
            count+=mp[xorr^t];
        mp[xorr] +=1;
    }
    return count;
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
    cout<<"ENTER THE TARGET VALUE POF XOR : ";
    int n1;
    cin>>n1;
    int res = numofsubarrayXOR(v,n1);
    cout<<"THE NUMBER OF SUBARRAY WITH XOR : "<<res;
}