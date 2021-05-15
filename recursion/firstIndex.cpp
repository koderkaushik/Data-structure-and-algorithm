#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);

 int firstIndex(int * arr,int size, int key)
{
    //base case 
    if(size==0)
    {
        return -1 ;
    }


    if(arr[0]==key)
    {
        return 0;
    }

    int subAns =  firstIndex(arr+1,size-1,key); //recursive case 
    if(subAns == -1)
    {
        return -1;
    }
    else
    {
        return subAns+1;
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


    cout<<firstIndex(arr,size,key);
    delete [] arr;
    return 0;
}