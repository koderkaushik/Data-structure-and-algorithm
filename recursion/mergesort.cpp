#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);


void m(int *arr, int start,int mid , int end)
{
    int size= end-start+1;
    int *op =  new int[size];
    int i=start;
    int j= mid+1;
    int k=0;
    while(1)
    {
        if(i==mid+1 or j==end+1)
        {
            break;
        }
        if(arr[i]<=arr[j])
        {
            op[k]=arr[i];
            i++;
            k++;
        }
        if(arr[j]<arr[i])
        {
            op[k] = arr[j];
            j++;
            k++;
        }
    }
        if(i==mid+1)
        {
            while(j<=end)
            {
                op[k] =  arr[j];
                j++;
                k++;
            }
        }

        if(j==end+1)
        {
            while(i<=mid)
            {
                op[k] = arr[i];
                i++;
                k++;
            }
        }

    
    k=0;
    for(int i=start;i<=end;i++)
    {
        arr[i] = op[k];
        k++;
    }
    delete [] op;
}

void merge_sort(int *arr, int start, int end)
{
    if(start>=end)
    {
        return ;
    }
    int mid=  (start+end)/2;
    merge_sort(arr, start,mid);
    merge_sort(arr,mid+1,end);

    m(arr,start,mid,end);
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

    merge_sort(arr,0,size-1);

    for(int i=0;i<size;i++)
    {
        cout<<arr[i];
        tb
    }
    delete [] arr;

    return 0;
}