#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);

bool isSorted(int *arr,int size)
{
    //base case 
    if(size==0 or size==1)
    {
        return true ;
    }

    //current problem 
    if(arr[0]>arr[1])
    {
        return false ;
    }

    //recursive case 
    bool smallProblem =  isSorted(arr+1,size-1);
    return smallProblem;
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

    cout<<isSorted(arr,size);
    
    delete [] arr;
    return 0;
}