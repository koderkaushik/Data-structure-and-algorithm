#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);

bool fun(string str)
{
    
    //base  case 
    if(str.length()==1)
    {
        if(str=="a")
        {
            return true;
        }
        return false;
    }

    //base case 
    if(str.length()==2)
    {
        if(str=="bb")
        {
            return true;
        }
        return false;
    }

    if(str.substr(0,1)=="a")
    {
        return fun(str.substr(1));
    }
    if(str.substr(0,2)=="bb")
    {
        return fun(str.substr(2));
    }
    return false;
    
}




int main()
{ 
    OJ;
    string a ;
    getline(cin, a);
    if(a[0]=='a')
    {
        cout<<fun(a);
    }   
    else
    {
        cout<<false;
    }
    return 0;
}