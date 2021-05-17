#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);
string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void printKeypads(int num, string op)
{
    if(num==0)
    {
        cout<<op;
        nl;
    }
    
    for(int i=0;i<arr[num%10].size();i++)
    {
        printKeypads(num/10,arr[num%10][i]+op);
    }
    

}


int main()
{ 
    OJ;
    int num;
    cin>>num;
    printKeypads(num,"");      
    return 0;
}