#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
char ptext[50],ctext[50],binary[8],XorRes[8],Dres[50],binary_key[8];
int Ascii,AsciiRes,key;
int n,i,Res=0;

void reverse()
{
	int len=strlen(binary_key);
	for(int i=0;i<len/2;i++)
	{
		char temp=binary_key[i];
		binary_key[i]=binary_key[len-i-1];
		binary_key[len-i-1]=temp;
	}
	cout<<"\nThe Binary key Equivalent is :";
	puts(binary_key);
}

void Genkey(int Key)
{
	int a=0;
	while(Key!=0)
	{
		//cout<<"\nkey="<<Key;
		int temp=Key%2;
		binary_key[a++]=char(temp+48);
		Key/=2;
	}
	binary_key[a]='\0';
	puts(binary_key);
	reverse();
	//puts(binary_key);
	for(i=0;i<strlen(binary);i++)
	{
		binary_key[i]=binary_key[i%strlen(binary_key)];
	}
	binary_key[i]='\0';
	cout<<"The final Binary key is :";
	puts(binary_key);
}

void Xor()
{
	for(i=0;i<strlen(binary_key);i++)
	{
		if(binary[i]==binary_key[i])
		   XorRes[i]='0';
		else
		   XorRes[i]='1';
	}
	XorRes[i]='\0';
	cout<<"\nThe Xored Result is :";
	puts(XorRes);
}

void BtoA()
{
	Res=0;
	for(int i=0;i<strlen(XorRes);i++)
	{
		if(XorRes[i]=='1')
		   Res+=pow(2,strlen(XorRes)-i-1);
	}
	cout<<"The final code is:"<<Res;
}

void AtoB(){
	cout<<"\nThe value of n is :"<<n;
	int a=8;
	while(n!=0)
	{
		int temp=n%2;
		binary[--a]=char(temp+48);
		n/=2;
	}
	if(a!=0)
	   while(a!=0)
	   {
	   	  binary[--a]='0';
	   }
	binary[8]='\0';
	cout<<"\nThe binary equivalent is :";
	puts(binary);		
	Genkey(key);
	Xor();
	BtoA();
}

int main()
{
	cout<<"Enter the Number to be encrypted(within range 0-255)\n";
	cin>>n;
	cout<<"The Number is : \n";
	cout<<n;
	
	cout<<"Enter the key to be used(within range 0-255) ?\n";
	cin>>key;
	cout<<"The key is : \n"<<key;
	AtoB();
	cout<<"\n\n\t\tDecrypting Your code ...\n";
	n=Res;
	AtoB();
	
		
	return 0;
	
}
