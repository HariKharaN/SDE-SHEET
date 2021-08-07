// RemoveDuplicateFromSortedArray
#include<bits/stdc++.h>
using namespace std;
int RemoveDup(vector<int> v)
{
    if(v.size() == 0)
        return 0;
    int i=0;
    for(int j=1;j<v.size();j++)
    {
        if(v[i] != v[j])
        {
            i++;
            v[i] = v[j];
        }
    }
    return i+1;
}
int main()
{
    vector<int> v = {1,1,2,2,2,2,3,3};
    int res = RemoveDup(v);
    cout<<res; // only the length of the array which has non duplicate returned if the array want to print store the a[i] in another array and return array
}