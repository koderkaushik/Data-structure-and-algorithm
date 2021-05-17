#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);


int part_fun(int *arr, int start ,int end)
{
    int count=0;
    int res;

    for(int i=start+1;i<=end;i++)
    {
        if(arr[i]<=arr[start])
        {
            count++;
        }
    }

    res =  start+count; // getting the pivot position 
    
    swap(arr[start],arr[res]);
    int i=start,j=end;
    while(i<res)
    {
        while(arr[i]<=arr[res])
        {
               i++;
        }
        while(arr[j]>arr[res])
        {
            j--;
        }
        
        /*this checking is important 
        for the case when all the elments on the LHS are 
        less than the pivot element */
        if(i<res)
        {
            swap(arr[i],arr[j]);    
        }
    }
    return res;
}

void quick_sort(int *arr, int start , int end)
{
    //base case 
    if(start>=end)
    {
        return ;
    }

    int pivot =  part_fun(arr,start,end);

    quick_sort(arr,start,pivot-1); //problem size decreased 
    quick_sort(arr,pivot+1,end); // problem size decreased 
}

int main()
{ 
    OJ;
    int size;
    cin>>size;
    int *arr =  new int[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    quick_sort(arr,0,size-1);

    for(int i=0;i<size;i++)
    {
        cout<<arr[i];
        tb
    }
    delete [] arr;

    return 0;
}