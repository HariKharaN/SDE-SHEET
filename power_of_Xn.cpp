// power_of_Xn
#include<bits/stdc++.h>
using namespace std;
double powerofN(double x,int n)
{
    double ans=1.0;
    long long nn = n;
    if(nn<0)
        nn=-1*nn; // if the power is in negative change it in pos and at last 1/X^n;
    while(nn)
    {
        if(nn % 2)
        {
            ans=ans*x;
            nn=nn-1;
        }
        else{
            x=x*x;
            nn=nn/2;
        }
        // cout<<nn<<"    "<<ans<<" "<<x<<endl; for checking the nn and ans and x value after all iteration
    }
    if(n<0)
        ans = (double)(1.0)/(double)(ans);  // if the power value is negative 1/X^n
    
    return ans;
}
int main()
{
    double X;
    int n;
    cin>>X;
    cin>>n;
    double ans=powerofN(X,n);
    cout<<"THE POWER OF GIVEN X of n is : "<<ans;
}