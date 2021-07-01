// majority_elementNby2
#include<bits/stdc++.h>
using namespace std;
int majorityElement( vector<int> a )
{
    int count=0;
    int ele=0;
    for(int i=0;i<a.size();i++)
    {
        if(count == 0)
            ele = a[i];
        if(a[i] == ele)
            count++;
        else    count--;
    }
    return ele;
}
int  main()
{
    int n;
    cout<<"ENTER THE ARRAY SIZE : ";
    cin>>n;
    vector<int> v(n);
    cout<<"ENTER THE VECTOR ELEMENT : ";
    for(int i=0;i<n;i++)
        cin>>v.at(i);
    int result = majorityElement(v);
    cout<<"THE MAJORITY ELEMENT IN THE ARRAY IS : "<<result;
}