#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

int main()
{
    char p[40];
    char plain[40];
    char rail[10][10];
    cout<<"\nEnter plaintext: ";
    gets(plain);
    int k=0;
    for(int i=0; i<strlen(plain); i++)
    {
            if(plain[i]!=' ')
            p[k++]=plain[i];
    }  
    p[k]='\0';                       
    int len=strlen(p);
    k=0;
    int length;
    if(len%2==0)
                length=len;
    else
                length=len+1;
    for(int i=0; i<length/2; i++)
    {
            for(int j=0; j<2; j++)
            {
                    rail[j][i]=p[k++];
            }
    }
    char c[40];
    k=0;
    cout<<"\n\nArray: \n";
    for(int i=0; i<2; i++)   
    {
            for(int j=0; j<length/2; j++)             
            {
                    cout<<"   "<<rail[i][j];
                    c[k++]=rail[i][j];
            }
            cout<<"\n\n\n";
            cout<<"  ";
    }
    c[k]='\0';
    cout<<"\nEncrypted text: "<<c; 
    cout<<"\nDECRYPTION\n";
    char derail[10][10];
    k=0;
    for(int i=0; i<2; i++)
    {
            for(int j=0; j<length/2; j++)
            {
                    derail[i][j]=c[k++];
                    cout<<"   "<<derail[i][j];
            }
            cout<<"\n\n\n";
            cout<<"  ";
    }
    char d[40];
    k=0;
    for(int i=0; i<length/2; i++)   
    {
            for(int j=0; j<2; j++)             
            {
                    
                    d[k++]=derail[j][i];
            }
        
    }
    d[k]='\0';
    cout<<"\nDecrypted text: "<<d;
    getch();
    return 0;
}
