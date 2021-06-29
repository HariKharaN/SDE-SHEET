#include<bits/stdc++.h>
using namespace std;
// FIND THE DUPLICATE NMBER IN A ARRAY
int findDuplicate(int num[])
{
    int slow= num[0];
    int fast = num[0];
    do
    {
        slow = slow[num];
        fast = num[num[fast]];
    }while (slow != fast);
    fast=num[0];
    while(slow != fast)
    {
        slow = num[slow];
        fast = num[fast];
    }
    return slow;
}

//sort an array with 0,1,2 without using a extra space and algorithm
void sortARRAY(int nums[],int n)
{
    cout<<"BEFORE SORTING THE ARRAY:";
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    cout<<endl;

    // sorting
    int lo=0,mid=0;
    int hi = n-1;
    int temp;
    while(mid <= hi)
    {
        switch(nums[mid])
        {
            case 0:
            {
                // temp=nums[lo];
                // nums[lo]=nums[mid];
                // nums[mid]=temp;
                // lo++;
                // mid++;

                swap(nums[lo++],nums[mid++]);

                break;
            }
            
            case 1:
                mid++;
                break;
            
            case 2:
                // temp = nums[mid];
                // nums[mid]=nums[hi];
                // nums[hi]=temp;
                // hi--;
                swap(nums[mid],nums[hi--]);
                break;
        }
    }

    cout<<"SORETD ARRAY WITHOUT USING ANY ALGO:";
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    cout<<endl;

}
// 3. fIND THE MISSING AND REPEATING NUMBER IN A ARRAY
void findMissing(int arr[],int n)
{
    int i;
    cout<<"THE REPEATING NUMBER IN THE ARRAY : ";
    for(i=0;i<n;i++)
    {
        // Make all array elements as negative format and 
        // the once again repating element will point to the index which is already in negative and 
        // the negative integer will not satisfy >0 condition
        if(arr[abs(arr[i])-1] > 0)
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        else
            cout<<abs(arr[i])<<endl;
    }
    cout<<"THE MISSING ELEMENT : ";
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
            cout<<(i+1);
    }

}
// 4. Merge 2 sorted array without an extrta space
void mergesorted(int arr1[],int arr2[],int n,int m)
{
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(arr2[j] < arr1[i])
                swap(arr2[j],arr1[i]);
        }
    }
    // BASIC SORTING AN ARRAY SYNTAX;
    for(int i=0;i<m-1;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if(arr2[j]<arr2[i])
                swap(arr2[j],arr2[i]);
        }
    }
    cout<<"after sorting the 1st array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"after sorting the 2nd array : ";
    for(int j=0;j<m;j++)
    {
        cout<<arr2[j]<<" ";
    }
    cout<<endl;
}
// 5. Maximum subarray
int maximumsubarray(int arr[],int n)
{
    int sum = 0;
    int max = arr[0];
    // See the notes for explanation , it sets a sum integer as 0
    // the first element in the array as MAX
    // it keeps on adding the elements in array if it gets greater than MAX
    // it add the SUM value to the MAX
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if(sum>max)
            max=sum;
        if(sum<0)
            sum=0;
    }
    return max;
}
// 6. Merger the overlapping interval
vector<vector<int>>  mergedinterval(vector<vector<int>> intervals)
{
    vector<vector<int>> merged;
    if(intervals.size() == 0)
        return merged; // if the intervals are empty we send the empty pairs
    sort(intervals.begin(),intervals.end()); // sorting the pairs of intervals incase it is in sorted manner
    vector<int> temp = intervals[0]; // we create a vector array and store the first pair in it
    for(auto it : intervals) //iterating thorugh all the pairs
    {
        if(it[0] <= temp[1])             // it checks the [1,3],[1,3] then [1,3][2,6] and the condtion makes the temp [1] as the max between the comapared
            temp[1]=max(it[1],temp[1]);
        else
            merged.push_back(temp);      //if the last element in the pair [1,6] [8,10], 8<6 condtion fails and push the temp into the mergerd([1,6])
            temp = it;                     
    }
    merged.push_back(temp);              // at last the left out pair in the temp also pushed to merged([1,6][8,10],[15,18])
    return merged;
}

int main()
{
    //  1. FIND THE DUPLICATE IN ARRAY
    cout<<"\n";
    int arr[7] = {1,2,4,6,3,2,5};
     int res = findDuplicate(arr);
    cout<<"DUPLICATE NUMBER IN THE ARRAY:";
    cout<<res<<endl<<endl;

    // 2.  sort an array with 0,1,2 without using a extra space and algorithm
    // vector<int> v = {0,1,0,2,1,0,0,1,2};
    // sortARRAY(v);
    int arr1[9] = {0,1,0,2,1,0,0,1,2};
    int n=sizeof(arr1)/sizeof(arr1[0]);
     sortARRAY(arr1,n);
    cout<<"\n\n";
    // cout<<"SORETD ARRAY WITHOUT USING ANY ALGO:";
    // for(int i=0;i<n;i++)
    //     cout<<arr1[i]<<" ";
    // cout<<endl;

    // 3. fIND THE MISSING AND REPEATING NUMBER IN A ARRAY
    // int array[6] = {4,3,6,2,1,1};
    // int n=sizeof(array)/sizeof(array[0]);
    int n1;
    cout<<"ENTER THE ARrAY SIZE : ";
    cin>>n1;
    int array[n1];
    cout<<"ENTER THE ARrAY ELEMENTS : ";
    for(int i=0;i<n1;i++)
        cin>>array[i];
    findMissing(array,n1);
    cout<<"\n\n";

    // 4. Merge 2 sorted array without an extrta space
    int size1,size2;
    cout<<"ENTER THE 1st ARRAY SiZE : ";
    cin>>size1;
    cout<<"ENTER THE 2nd ARRAY SiZE : ";
    cin>>size2;
    int arra1[size1],arra2[size2];
    cout<<"ENTER THE ELEMENTS FOR 1ST ARRAY : ";
    for(int i=0;i<size1;i++)
        cin>>arra1[i];
    cout<<"ENTER THE ELEMENTS FOR 2ND ARRAY : ";
    for(int i=0;i<size2;i++)
        cin>>arra2[i];
    mergesorted(arra1,arra2,size1,size2);

    // 5. Maximum subarray
    int nn;
    cout<<"ENTER THE ARRAY SIZE TO FIND THE MAXIMUM SUBARRAY : ";
    cin>>nn;
    int arraysub[nn];
    cout<<"ENTER THE ARRAY ELEMENTS TO FIND THE MAXIMUM SUBARRAY : ";
    for(int i=0;i<nn;i++)
        cin>>arraysub[i];
    int maxisub = maximumsubarray(arraysub,nn);
    cout<<"THE MAXIMUM OF SUBARRRAY IS : "<<maxisub;
    cout<<"\n\n";

    // 6. Merger the overlapping interval

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    // vector<vector<int>> intervals;
    // int si;
    // cout<<"ENTER THE SIZE OF PAIRED INTERVALS : ";
    // cin>>si;
    // cout<<"ENETR THE PAIRED ELEMENTS : ";
    // for(int i=0;i<si;i++)
    // {
    //     int x,y;
    //     cin>>x>>y;
    //     intervals.push_back({x,y});
    // }
    vector<vector<int>> aftremoverint = mergedinterval(intervals); 
    cout<<"THE MERGED INTERVALS ARE : ";
    for(int i=0;i<aftremoverint.size();i++)
    {
        for(int j=0;j<aftremoverint[i].size();j++)
        {
            cout<<aftremoverint[i][j]<<" ";
        }
        cout<<", ";
    }
    cout<<"\n\n";
}