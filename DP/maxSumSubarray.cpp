#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;
#define nl cout<<endl;
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);


//Kadanes' algorithm 
int maxSumSubArray(int arr[] , int n)
{
    int max_sum =  INT_MIN;
    int cs[n] = {0};
    cs[0] =  arr[0];
    max_sum =  cs[0];
    
    for(int i=1;i<n;i++)
    {
        if(arr[i] > cs[i-1]+arr[i])
        {
            cs[i] =  arr[i];
        }
        else
        {
            cs[i] =  cs[i-1]+arr[i];
        }

        max_sum =  max( cs[i] ,  max_sum );
    }

    return max_sum;
}


int main()
{ 
    OJ;
    int n ;
    cin>>n;    
    int arr[] =  {-1,-2,3,-4};
    cout<< maxSumSubArray(arr , sizeof(arr)/sizeof(int));
    return 0;
}
