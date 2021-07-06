// Longestconsecutive Sequence
#include<bits/stdc++.h>
using namespace std;
int Longestconsecutive(vector<int> a)
{
    set<int> hashset;
    for(int n : a)
        hashset.insert(n);
    int longeststreak = 0;
    for(int num : a)
    {
        if(!hashset.count(num-1))
        {
            int currentnum = num;
            int currentstreak = 1;
            while(hashset.count(currentnum+1))
            {
                currentnum++;
                currentstreak++;
            }
            longeststreak = max(longeststreak,currentstreak);
        } 
    }
    return longeststreak;
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
    int res = Longestconsecutive(v);
    cout<<"THE LONHEST CONSECUTIVE SEQUENCE IN THE ARRY IS : "<<res;
}