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
vector<int> majorityElementNby3(vector<int> a)
{
    int n=a.size();
    int num1=-1,num2=-1,count1=0,count2 =0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == num1)
            count1++;
        else if(a[i] == num2)
            count2++;
        else if(count1 == 0)
        {
            num1 = a[i];
            count1 = 1;
        }
        else if(count2 == 0)
        {
            num2 = a[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }        
    }
    vector<int> ans;
    count1=count2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == num1)
            count1++;
        if(a[i] == num2)
            count2++;
    }
    if(count1 > n/3)          // as given in the answer video but it doesnt satify a condition where 2 element (2,2,1,1,1,2,2) in this both 
        ans.push_back(num1);  // so the ouput will be both 1 2 so the below is coded
    if(count2 > n/3)
        ans.push_back(num2);  

    // if(count1 > n/3 and count1>=count2)
    //     ans.push_back(num1);
    // if(count2 > n/3 and count2>=count1)
    //     ans.push_back(num2);            This code works properly even we have 2 elements having count >  n/3 value

    
    return ans;
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
    cout<<"THE MAJORITY ELEMENT IN THE ARRAY IS : "<<result<<endl;

    int n1;
    cout<<"ENTER THE ARRAY SIZE : ";
    cin>>n1;
    vector<int> v1(n1);
    cout<<"ENTER THE VECTOR ELEMENT : ";
    for(int i=0;i<n1;i++)
        cin>>v1.at(i);
    vector<int> ans = majorityElementNby3(v1);
    cout<<"THE MAJORITY ELEMENT IS : ";
    for(auto i : ans)
        cout<<i<<" ";
    cout<<endl;

}
