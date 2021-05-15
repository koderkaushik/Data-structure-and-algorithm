#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);

int lastIndex1(int *arr, int size , int key)
{
    //base case 
    if(size==0)
    {
        return -1; 
    }

    if(arr[size-1] ==  key)
    {
        return size-1;
    }

    int subProblem =  lastIndex1(arr,size-1,key);
    return subProblem;
}



int lastIndex2(int *arr,int size,int key)
{
    //base case 
    if(size==0)
    {
        return -1; 
    }

    //recursive case 
    int index =  lastIndex2(arr+1,size-1,key);

    if(index==-1)
    {
        if(arr[0] ==  key)
        {
            return 0;
        }
        return -1;
    }
    else
    {
        return index+1;
    }

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
    int key ;
    cin >> key ;

    cout<<lastIndex1(arr,size,key)<<endl;
    cout<<lastIndex2(arr,size,key);
    delete [] arr;
    return 0;
}