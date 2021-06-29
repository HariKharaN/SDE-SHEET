#include<bits/stdc++.h>
using namespace std;
void nextpermutation(vector<int> a,int n)
{
    int idx = -1;
    // int n =a.size();
    for(int i=n-1;i>0;i--)
    {
        if(a[i]>a[i-1])
        {
            idx =i;
            break;
        }
    }
    if(idx == -1)
        reverse(a.begin(),a.end());
    else{
        int prev = idx;
        for(int i=idx+1;i<n;i++)
        {
            if(a[i]>a[idx-1] and a[i]<=a[prev])
            {
                prev=i;
            }
        }
        swap(a[idx-1],a[prev]);
        reverse(a.begin()+idx,a.end());
    }
    cout<<"THE NEXT PERMUATATION OF ARRAY : ";
    for(auto x : a)
        cout<<x<<" ";
    cout<<endl;
}
int main()
{
    // vector<int> v  = {1,2,3};
    int size;
    cout<<"ENTER THE SIZE OF ARRAY : ";
    cin>>size;
    vector<int> v(size);
    cout<<"ENTER THE ELEMENTS IN ARRAY : ";
    for(int i=0;i<size;i++)
        cin>>v.at(i);
    nextpermutation(v,size);
}