#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);

int staircase(int num)
{
    if(num==2)
    {
        return 2;
    }
    if(num==0)
    {
        return 1;
    }
    if(num==1)
    {
        return 1;
    }

    int a =staircase(num-1);
    int b= staircase(num-2);
    int c = staircase(num-3);
    return a+b+c;
}

int main()
{ 
    OJ;
    int num ;
    cin>> num ;
    cout<<staircase(num);   
    return 0;
}