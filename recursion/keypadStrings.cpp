#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);

string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int allStrings(int num , string *op)
{
    if(num/10==0)
    {
        int i=0;
        for( ;i<arr[num].size();i++)
        {
            op[i] =  arr[num].substr(i,1);
        }
        return i;
    }
    int subSize = allStrings(num/10,op);
    string *temp = new string[subSize];
    for(int i=0;i<subSize;i++)
    {
        temp[i] =  op[i];
    }
    int finalSize=0;
    for(int i=0;i<arr[num%10].size();i++)
    {
        for(int j=0;j<subSize;j++)
        {
            op[finalSize] =  temp[j] + arr[num%10][i];
            finalSize++;
        }
    }
    delete [] temp;  
    return finalSize;
}


int main()
{ 
    OJ;
    string *op =  new string[1000];
    int num;
    cin>>num ;
    int res = allStrings(num,op);      
    for(int i=0;i<res;i++)
    {
        cout<<op[i];
        nl
    }
    delete []  op;
    return 0;
}