#include<bits/stdc++.h>
using namespace std;
void searchGFG2D(vector<vector<int>> a,int t)
{
    int i=0;
    int n= a.size();
    int j=n-1;
    while(i<n and i>=0)
    {
        if(a[i][j] == t)
        {
            cout<<"GFG QUESTION matrix is sorted row and as well as column wise : ";
            cout<<"FOUND THE ELEMENT "<<t<<" at "<<i<<", "<<j<<endl;
            return;
        }
        if(a[i][j] > t) // if the matrixvalue is grater than the target value
            j--;        //make j-1 so the index comes left
        else            // if the matrixvalue is lesser than the target value
            i++;        //make i+1 so the index comes down
    }
}
bool searchLEET2D(vector<vector<int>> a,int t)
{
    if(!a.size()) return false;
    int n=a.size(); //row
    int m=a[0].size(); //col
    int lo=0;
    int hi = (n*m)-1; //last index (11)
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(a[mid/2][mid%2] == t)
            return true;
        if(a[mid/2][mid%2] < t)
            lo=mid+1;
        else
            hi=mid-1;
    }
    return false; // if the element is not present
}
int main()
{
    vector<vector<int>> a = {{10,20,30,40},{11,21,36,43},{25,29,34,50},{50,60,70,80}};
    // searching as per given in GFG question by the 
    // matrix is sorted row and as well as column wise
    searchGFG2D(a,25);
    // As in the leetcode question
    // all the rows are sorted and the last element in all the row is always lessser the first element of the next row
    // only return true or false (Is the element is present or not)
    vector<vector<int>> ar = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    if(searchLEET2D(ar,30) == true)
        cout<<"BY THE LEETCODE CODE THE ELEMENT IS PRESENT";
    else
        cout<<"BY THE LEETCODE CODE THE ELEMENT IS NOT PRESENT";
       
}   