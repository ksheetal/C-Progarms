#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
void decrypt(char ctext[], int a , int b, int a_inverse)
{
	cout<<"\nThe derypted text is:\t";
	for(int i=0; i<strlen(ctext); i++)
	{
		if(ctext[i]==' ' || (ctext[i]>='0' && ctext[i]<='9'))
		{
			cout<<ctext[i];
			continue;
		}
		int temp=(a_inverse*(ctext[i]-65-b))%26;
		cout<<(char)(temp+97);
	}
}
void encrypt(char ptext[], int a, int b, int a_inverse)
{
	char ctext[50];
	int res[strlen(ptext)];
	cout<<"\nIndex :\t\t";
	int j=0, i;
	for( i=0; i<strlen(ptext); i++)
	{
		if(ptext[i]==' ' || (ptext[i]>='0' && ptext[i]<='9'))
		{
			ctext[i]=ptext[i];
			continue;
		}
		int x=(int)(ptext[i]-97);
		cout<<x<<"\t";
		int temp=((a*x)+b)%26;
		res[j++]=temp;
		ctext[i]=(char)(temp+65);
	}
	ctext[i]='\0';
	cout<<"\n(aX+b)%26:\t";
	for(int k=0; k<j; k++)
	{
		cout<<res[k]<<"\t";
	}
	cout<<"\nThe Encrypted text is:\t";
	for( i=0; i<strlen(ctext); i++)
	{
		cout<<ctext[i];
	}
	decrypt(ctext, a, b, a_inverse);
}
	
int main()
{
	char plaintext[50];
	int a, b;
	cin.ignore(50, '\n');
	cout<<"\nEnter the plaintext:\t";
	cin.getline(plaintext, 50);
	cout<<"\nEnter the value of a:\t";
	cin>>a;
	cout<<"\nEnter the value of b:\t";
	cin>>b;
	int a_inverse=0;
	for(int i=0; i<26; i++)
	{
		int temp=(a*i)%26;
		if(temp==1)
		{
			a_inverse=i;
		}	
	}
	if(a_inverse==0)
	{
		cout<<"\nModular Inverse doesn't exist for this number";
		exit(0);
	}
	cout<<"\nThe modular inverse of this number is:\t"<<a_inverse;
	encrypt(plaintext, a, b, a_inverse);
	return 0;
}
