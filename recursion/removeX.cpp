#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<"\n";
#define nl cout<<"\n";
#define tb cout<<" ";
#define OJ \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);

int length(char *ch)
{
    if(ch[0]=='\0')
    {
        return 0;
    }
    int subLength =  length(ch+1);
    return subLength+1;
}

void removeX(char *ch)
{
    if(*ch=='\0')
    {
        return ;
    }

    if(*ch=='x')
    {
        int i=1;
        while(ch[i]!='\0')
        {
            ch[i-1]=  ch[i];
            i++;
        }
        ch[i-1] = '\0';
        removeX(ch);
    }
    else
    {
        removeX(ch+1);
    }
}


void removeX1(char *ch, int size)
{
    if(size==0)
    {
        return ;
    }

    if(ch[size-1]=='x')
    {
        char *ptr=&ch[size];
        while(*ptr!='\0')
        {
            *(ptr-1)=  *ptr;
            ptr++;
        }
        *(ptr-1) = '\0'; 
        removeX1(ch , size-1);
    }
    else
    {
        removeX1(ch,size-1);
    }
}


int main()
{ 
    OJ;
    int size;
    cin>>size;
    char str[20] = "xaxbxcxx";
    char str1[20] = "xaxbxcxx";
    
    removeX(str1);
    cout<<str1;
    nl
    
    int l =  length(str);
    removeX1(str,l);
    if(str[0]=='\0')
    {
        cout<<-1<<endl;
    }
    else
        cout<<str;   
    return 0;
}