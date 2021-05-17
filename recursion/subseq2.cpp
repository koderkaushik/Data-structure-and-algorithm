#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);

void subseq2(string input , string output)
{
    if(input.empty())
    {
        cout<<output;
        nl;
        return ;
    }

    subseq2(input.substr(1),output); /* w/o considering the first character */

    subseq2(input.substr(1),output+input[0]); /* considering the first character */

}


int main()
{ 
    OJ;
    string  input ;
    getline(cin, input);
    subseq2(input,"");      
    return 0;
}