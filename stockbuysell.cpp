#include<bits/stdc++.h>
using namespace std;
void maxprofit(vector<int> a,int n)
{
    int minprice = INT_MAX;
    int maxprofit = 0;
    for(int i=0;i<n;i++)
    {
        minprice = min(minprice,a[i]);
        maxprofit  = max(maxprofit,a[i]-minprice);
    }
    cout<<"THE MAX PROFIT IS : "<<maxprofit<<endl;
    int daybuy,daysell;
    for(int i=0;i<n;i++)
        {
            if(a[i] == minprice)
                daybuy = i+1;
            if(a[i] == minprice+maxprofit)
                daysell=i+1;
        }
    cout<<"THE BEST DAY TO BUY IS : "<<daybuy<<endl;
    cout<<"THE BEST DAY TO SELLL IS : "<<daysell<<endl;
}
int main()
{ 
    int n;
    cout<<"ENTER THE SIZE OF THE ARRAY : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"ENTER THE ELEMENTS OF THE ARRAY : ";
    for(int i=0;i<n;i++)
        cin>>arr.at(i);
    maxprofit(arr,n);

}