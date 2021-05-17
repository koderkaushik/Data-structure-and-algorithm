#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);

int subSeq(string s1, string *op)
{
    if(s1.size()==0)
    {
        op[0] = "";
        return 1;
    }
    
    int k=  subSeq(s1.substr(1),op); 
    /*Assume that the subsequence of the substring gets stored
    in the array and size of array is initialised in k
    */
    for(int i=0;i<k;i++)
    {
        string temp  =  s1[0]+op[i];
        op[k+i] = temp;
    }
    return 2*k;
}

int main()
{ 
    OJ;
    string s;
    string *op =  new string[100];
    getline(cin, s);
    int res = subSeq(s,op);      
    for(int i=0;i<res;i++)
    {
        cout<<op[i];
        nl
    }
    delete []  op;
    return 0;
}