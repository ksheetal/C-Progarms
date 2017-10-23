#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

char plain[50]={'\0'};//For input
char plain2[50]={'\0'};//Has Decrypted output
char ctext[50]={'\0'};
int col=5;
int temp[20][5];

void decrypt(char ctext2[],int length)
{

    int row;
    if(length%col==0)
        row=length/col;
    else
        row=(length/col)+1;
    //int row=ceil(length/col);

    int inc=0;
	for(int i=0;i<col;i++)
	{
	    for(int k=0;k<row;k++)
		{
		    int buff=ctext2[inc++];

		    if(buff!=' ')
            {
                    temp[k][i]=buff;
            }
            else
            {
                k--;
            }
		}
	}


    inc=0;
    int count=0;
    for(int i=0;i<row;i++)
    {
        for(int k=0;k<col;k++)
        {
            plain2[inc++]=(char)temp[i][k];
            count++;
            if(count>4)
            {
                plain2[inc++]=' ';
                count=0;
            }
        }
    }
    for(int i=inc-1;i>=0;i--)
    {
        if(plain2[i]=='x')
            plain2[i]=' ';
    }


}

void encrypt(char plain2[],int length)
{

    int row;
    if(length%col==0)
        row=length/col;
    else
        row=(length/col)+1;
    //int row=ceil(length/col);

    int inc=0;
	for(int i=0;i<row;i++)
	{
	    for(int k=0;k<col;k++)
		{
		    int buff=plain2[inc++];

		    if(buff!=' ')
            {
                    temp[i][k]=buff;
                if(temp[i][k]=='\0')
                {
                    temp[i][k]='x';
                }
            }
            else
            {
                k--;
            }
		}
	}
	cout<<endl;
	for(int i=0;i<row;i++)
    {
        cout<<endl;
        for(int k=0;k<col;k++)
        {
            cout<<(char)temp[i][k]<<" ";
        }
    }


    inc=0;
    int count=0;
    for(int i=0;i<col;i++)
    {
        for(int k=0;k<row;k++)
        {
            ctext[inc++]=(char)temp[k][i];
            count++;
            if(count>4)
            {
                ctext[inc++]=' ';
                count=0;
            }
        }
    }
}

int main()
{

	int length;
	int key=0;

	cout<<"Enter plain text ";
	cin.getline(plain,50);



	length=strlen(plain);

	encrypt(plain,length);
	cout<<"\nEcrypt text is "<<ctext;
	decrypt(ctext,length);
	cout<<"\nDecrypt text is "<<plain2;
	return 0;
}
