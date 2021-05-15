#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);

void removeDuplicates(char *str)
{
    if(*str=='\0')
    {
        return ;
    }

    if(str[0] == str[1])
    {
        int i=1;
        while(str[i]==str[0])
        {
            i++;
        }
        int k=i;
        int j=1;
        while(str[k]!='\0')
        {
            str[j] =  str[k];
            k++;
            j++;
        }
        str[j] = '\0';
    }   
    removeDuplicates(str+1);
}


int main()
{ 
    OJ;
    int size;
    cin>>size;
    char str[] =  "aaaadddqw";
    cout<<str;
    nl
    removeDuplicates(str);   
    cout<<str<<endl;
    return 0;
}