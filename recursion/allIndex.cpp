#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);

int allIndex1(int *arr, int size, int key ,int *op)
{
    //it returns the size of the output array 
    //indexes in op are stored in increasing order 
    if(size==0)
    {
        return 0;
    }

    //recursive case
    //splitting the array from the back 
    int index =  allIndex1(arr,size-1,key,op);

    if(arr[size-1]==key)
    {
        op[index]= size-1;
        return index+1;
    }
    else
    {
        return index;
    }
}

int allIndex2(int *arr, int size, int key ,int *op)
{
    //base case 
    if(size==0)
    {
        return 0;
    }

    int index =  allIndex2(arr+1,size-1,key, op);

    //update the elements of the op array 
    for(int i=0;i<index;i++)
    {
            op[i] ++;
    }
    
    if(arr[0]==key)
    {
        //shift elements of OP to the right 
        int i = index ;
        while(i>=1)
        {
            op[i]= op[i-1];
            i--;
        }
        op[i] =  0;
        return index+1;
    }
    return index;
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

    int *op  = new int[size];

    int res =  allIndex1(arr,size,key,op);
    // cout<<lastIndex2(arr,size,key);
    
    if(res==0)
    {
        cout<<-1;
    }
    else
    {
        for(int i=0;i<res;i++)
        {
        cout<<op[i];
        tb;
        }
        nl;
    }
    
    delete [] op;
    op =  new int[size];

    res = allIndex2(arr,size,key,op);
    
    if(res==0)
    {
        cout<<-1;
    }
    else
    {
        for(int i=0;i<res;i++)
        {
        cout<<op[i];
        tb;
        }
        nl;
    }

    delete [] arr;
    delete [] op;
    return 0;
}