#include<bits/stdc++.h>
using namespace std;
void setmatrix(vector<vector<int>> matrix)
{
    int colo = 1;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i=0;i<rows;i++)
    {
        if(matrix[i][0] == 0)  
            colo = 0;   
        for(int j=1;j<cols;j++)
        {
            if(matrix[i][j]== 0)
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for(int i=rows-1;i>=0;i--)
    {
        for(int j=cols-1;j>=1;j--)
            if(matrix[i][0] ==0 || matrix[0][j] == 0 )
                matrix[i][j]=0; 
        if(colo = 0) matrix[i][0] = 0;
    }
    cout<<"AFTER SETTING MATRIX ZEROS"<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


}
int main()
{
     vector<vector<int>> intervals = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
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
    cout<<"before setting the matrix to zero :\n ";
    int rows = intervals.size();
    int cols = intervals[0].size();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<intervals[i][j]<<" ";
        }
        cout<<endl;
    }
    setmatrix(intervals);
}

