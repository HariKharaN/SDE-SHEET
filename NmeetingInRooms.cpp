#include<bits/stdc++.h>
using namespace std;
struct meeting
{
    int start,end,pos;
};
bool comparator(struct meeting m1, meeting m2)
{
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}
void NmeetingRoom(vector<int> s,vector<int> f,int n)
{
    struct meeting meet[n];
    for(int i=0;i<n;i++)
    {
        meet[i].start = s[i],meet[i].end = f[i],meet[i].pos = i+1;
    }
    sort(meet,meet+n,comparator);
    vector<int> ans;
    int limit = meet[0].end;
    ans.push_back(meet[0].pos);
    for(int i=0;i<n;i++)
    {
        if(meet[i].start > limit)
        {
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }   
    for(auto x : ans)
        cout<<x<<" ";
    cout<<endl<<" THE NO OF MEETING IN THE ROOM : "<<ans.size();  
}

int main()
{
    vector<int> s = {1,0,3,8,5,8};
    vector<int> f = {2,6,4,9,7,9};
    int n = s.size();
    NmeetingRoom(s,f,n);
}