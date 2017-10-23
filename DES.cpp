#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int SBox[8][4][16]= {	{
							{14, 4, 13, 1, 2, 15, 11, 8,3, 10, 6, 12, 5, 9, 0, 7},
							{0, 15, 7, 4,14,2,13, 1,  10,6,12,11, 9, 5, 3,  8},
							{4, 1, 14, 8,13,6,2,11, 15,12, 9, 7, 3,10, 5, 0},
							{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
						},
						{
							{15,  1,   8, 14 ,  6, 11,   3,  4,   9,  7 ,  2, 13,  12,  0,   5, 10},
							{3, 13,   4,  7,  15,  2,   8, 14,  12,  0,   1, 10,   6,  9,  11,  5},
							{0, 14,   7, 11,  10,  4,  13,  1,   5,  8,  12,  6,   9,  3,   2, 15},
							{13,  8,  10,  1,   3, 15,   4,  2,  11,  6,   7, 12,   0,  5 , 14,  9}
						},
						{
							{10,  0,   9, 14,   6,  3,  15,  5,   1, 13,  12,  7,  11,  4,   2,  8},
							{13,  7,   0,  9,   3,  4,   6, 10,   2,  8,   5, 14 , 12, 11,  15,  1},
							{13,  6,   4,  9,   8, 15,   3,  0 , 11,  1 ,  2 ,12,   5, 10,  14,  7},
							{1, 10,  13 , 0 , 6 ,9 ,  8,  7 ,  4, 15,  14,  3 , 11,  5,   2 , 12}
						},
						{
							{7, 13,  14,  3,   0,  6,   9, 10,   1,  2 ,  8,  5,  11, 12,   4, 15},
							{13,  8,  11,  5,   6, 15,   0,  3,   4,  7,   2, 12,   1, 10,  14,  9},
							{10,  6,   9,  0,  12, 11,   7, 13,  15,  1,   3, 14,   5,  2,   8,  4},
							{3, 15,   0,  6,  10,  1,  13,  8,   9,  4,   5, 11,  12,  7,   2, 14}
						},
						{
							{2, 12,   4,  1 ,  7, 10,  11,  6 ,  8,  5,   3, 15 , 13,  0,  14,  9},
							{14, 11,   2, 12,   4 , 7 , 13,  1,  5 , 0,  15, 10 ,  3 , 9 ,  8,  6},
      						{4,  2,   1, 11 , 10, 13,   7,  8,  15,  9,  12,  5 ,  6,  3,   0, 14},
     						{11,  8,  12,  7,   1, 14,   2, 13 ,  6, 15,   0,  9 , 10,  4,   5, 3}
     					},
						{
							{12,  1,  10, 15,   9,  2,   6,  8,   0, 13,   3,  4,  14,  7,   5, 11},
     						{10, 15,   4,  2,   7, 12 ,  9,  5,   6,  1 , 13 ,14 ,  0, 11 ,  3,  8},
      						{9, 14,  15,  5,   2,  8,  12,  3,   7,  0,   4, 10,   1, 13,  11,  6},
      						{4,  3,   2, 12,   9,  5 , 15, 10 , 11, 14 ,  1,  7,   6,  0 ,  8, 13}
      					},
      					{
      						{4, 11,   2, 14,  15,  0,   8, 13,   3, 12,   9,  7 ,  5, 10,   6 , 1},
     						{13,  0,  11,  7,   4,  9 ,  1, 10,  14,  3 ,  5, 12,   2, 15 ,  8, 6},
      						{1,  4,  11, 13,  12,  3,   7, 14,  10 ,15,   6,  8 ,  0,  5,   9,  2},
      						{6, 11,  13,  8,   1,  4,  10,  7,   9,  5,   0, 15,  14,  2 ,  3, 12}
      					},
      					{
      						{13,  2,   8,  4,   6, 15,  11,  1,  10,  9 ,  3, 14,   5,  0,  12,  7},
      						{1, 15,  13,  8 , 10,  3 ,  7,  4 , 12 , 5 ,  6, 11 ,  0 ,14 ,  9 , 2},
      						{7, 11,   4,  1 ,  9, 12,  14,  2 ,  0 , 6 , 10, 13 , 15,  3,   5,  8},
      						{2,  1,  14,  7,   4, 10,   8 ,13,  15, 12,   9,  0 ,  3,  5,   6, 11}
      					}
					};
class DES
{
	char *ptext;
	int pLen;
	char *ctext;
	char key[64], kp[56];
	char c[17][28], d[17][28];
	char merge[17][56];
	char subKey[17][48];
	char l[17][32], r[17][32];
	char er[48], sER[32];
	char fOutput[32];
	public:
		DES();
		void input();
		void keyGenerate();
		void output();
		void leftShift(char [],char [], int);
		void initialPermutation();
		void iterations();
		void functionF(int);
		void performXor(char, char &);
		int binToDec2(char, char);
		int binToDec4(char [], int, int);
		void DecToBin(char [], int, int &);
		int applySBox(int, int, int);
		void finalPermutation();
};
DES::DES()
{
	
}
void DES::input()
{
	cout<<"\nEnter the no. bits in plaintext:\t";
	cin>>pLen;
	ctext=new char [pLen];
	ptext=new char [pLen+1];
	cin.ignore(pLen+1, '\n');
	cout<<"\nEnter the Message:\t";
	cin.getline(ptext, pLen+1);
	cin.ignore(65, '\n');
	cout<<"\nEnter the 64-bit key:\t";
	cin.getline(key, 65);
}
void DES::output()
{
	cout<<"\nThe message is:\t"<<ptext;
	cout<<"\nThe Key is:\t";
	for(int i=0; i<64; i++)
	{
		cout<<key[i];
	}
	cout<<"\nThe K+ is:\t";
	for(int i=0; i<56; i++)
	{
		cout<<kp[i];
	}
	for(int j=1; j<17; j++)
	{
		cout<<"\nMerge["<<j<<"]:\t";
		for(int i=0; i<56; i++)
		{
			cout<<merge[j][i];
		}
	}
	cout<<"\n\n";
	for(int j=1; j<17; j++)
	{
		cout<<"\nK["<<j<<"]:\t\t";
		for(int i=0; i<48; i++)
		{
			cout<<subKey[j][i];
		}
	}
	cout<<"\n\n";
	cout<<"\nL[0]:\t\t";
	for(int i=0; i<32; i++)
	{
		cout<<l[0][i];
	}
	cout<<"\nR[0]:\t\t";
	for(int i=0; i<32; i++)
	{
		cout<<r[0][i];
	}
	
}
void DES::keyGenerate()
{
	int pc1[]={57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11,  3, 60, 52, 44, 36, 63, 55, 47,39, 31, 23,15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13,  5, 28, 20, 12, 4};
	for(int i=0; i<56; i++)
	{
		kp[i]=key[(pc1[i]-1)];
	}
	for(int i=0; i<56; i++)
	{
		if(i<28)
		{
			c[0][i]=kp[i];
		}
		else
		{
			d[0][i%28]=kp[i];
		}
	}
	int leftShiftArray[]={1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
	for(int i=1; i<17; i++)
	{
		leftShift(c[i], c[i-1], leftShiftArray[i-1]);
		leftShift(d[i], d[i-1], leftShiftArray[i-1]);
	}
	for(int i=1; i<17; i++)
	{
		for(int j=0; j<56; j++)
		{
			if(j<28)
			{
				merge[i][j]=c[i][j];
			}
			else
			{
				merge[i][j]=d[i][j%28];
			}
		}
	}
	int pc2[]={14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52,31, 37, 47,55, 30, 40,51, 45, 33,48, 44, 49,39, 56, 34,53, 46, 42,50,36 , 29, 32};
	for(int j=1; j<17; j++)
	{
		for(int i=0; i<48; i++)
		{
			subKey[j][i]=merge[j][(pc2[i]-1)];
		}
	}
}
void DES::leftShift(char C[], char Cprev[], int n)
{
	int j=0;
	for(int i=n; i<28; i++)
	{
		C[j++]=Cprev[i];
	}
	for(int i=0; i<n; i++)
	{
		C[j++]=Cprev[i];
	}
}
void DES::initialPermutation()
{
	int ip[]={58, 50,42, 34, 26,18 , 10, 2, 60, 52, 44,  36, 28,20 ,12, 4,62,54,46,38, 30, 22, 14, 6,64,56,48,40, 32, 24, 16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19, 11, 3,61,53,45, 37,29 ,21,13, 5,63,55,47,39,31,23, 15,7};
	char ipArr[64];
	for(int i=0; i<64; i++)
	{
		ipArr[i]=ptext[(ip[i]-1)];
	}
	for(int i=0; i<64; i++)
	{
		if(i<32)
		{
			l[0][i]=ipArr[i];
		}
		else
		{
			r[0][i%32]=ipArr[i];
		}
	}
}
void DES::iterations()
{
	for(int i=1; i<=16; i++)
	{
		for(int j=0; j<32; j++)
		{
			l[i][j]=r[i-1][j];
		}
		functionF(i);
		for(int j=0; j<32; j++)
		{
			performXor(l[i-1][j], fOutput[j]);
		}
		for(int j=0; j<32; j++)
		{
			r[i][j]=fOutput[j];
		}
	}
}
void DES::functionF(int n)
{
	int E[]={32, 1, 2, 3, 4, 5,4, 5, 6, 7, 8, 9, 8, 9,10, 11, 12,13,12, 13,14,15, 16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
	for(int i=0; i<48; i++)
	{
		er[i]=r[n-1][(E[i]-1)];
	}
	for(int i=0; i<48; i++)
	{
		performXor(subKey[n][i], er[i]);
	}
	for(int i=0, j=0; i<8; i++)
	{
		int row=binToDec2(er[6*i], er[(6*i)+5]);
		int col=binToDec4(er, (6*i)+1, (6*i)+4);
		int res=applySBox(i, row, col);
		DecToBin(sER, res, j);
	}
	int P[]={16,   7,  20,  21,29,  12,  28,  17,1,  15,  23,  26,5,  18,  31,  10,2,   8,  24,  14,32,  27,   3,   9,19,  13,  30,   6,22,  11,   4,  25};
	for(int i=0; i<32; i++)
	{
		fOutput[i]=sER[(P[i]-1)];
	}
}
int DES::applySBox(int n, int row, int col)
{
	return SBox[n][row][col];
}
void DES::DecToBin(char arr[], int num, int &index)
{
	char buf[4];
	int i=0;
	while(num>0)
	{
		int rem=num%2;
		if(rem==1)
			buf[i++]='1';
		else
			buf[i++]='0';
		num=num/2;
	}
	while(i<4)
		buf[i++]='0';
	for(i=i-1; i>=0; i--)
	{
		arr[index++]=buf[i];
	}
}
int DES::binToDec2(char a, char b)
{
	if(a=='0' && b=='0')
		return 0;
	else if(a=='0' && b=='1')
		return 1;
	else if(a=='1' && b=='0')
		return 2;
	else if(a=='1' && b=='1')
		return 3;
}
int DES::binToDec4(char arr[], int st, int end)
{
	int num=0;
	for(int i=end, j=0; i>=st; i--, j++)
	{
		 if(arr[i]=='1')
		 {
		 	num=num+pow(2, j);
		 }
	}
	return num;
}
void DES::performXor(char x, char &y)
{
	if(x==y)
		y='0';
	else
		y='1';
}
void DES::finalPermutation()
{
	char temp[64];
	for(int i=0; i<64; i++)
	{
		if(i<32)
		{
			temp[i]=r[16][i];
		}
		else 
		{
			temp[i]=l[16][i%32];
		}
	}
	int IPinverse[]={	40,     8,   48,    16,    56,   24,    64,   32,
     			        39,     7,   47,    15,    55,   23,    63,   31,
            			38,     6,   46,    14,    54,   22,    62,   30,
            			37,     5,   45,    13,    53,   21 ,   61 ,  29,
			            36,     4,   44,    12,    52,   20,    60,   28,
            			35,     3,   43,    11,    51,   19 ,   59,   27,
            			34,     2,   42,    10,    50,   18,    58,   26,
            			33,     1,   41,     9,    49,   17,    57,   25
					};
	for(int i=0; i<64; i++)
	{
		ctext[i]=temp[(IPinverse[i]-1)];
	}
	cout<<"\n\nThe Encrypted Message is:\t";
	for(int i=0; i<64; i++)
	{
		if(i%8==0)
			cout<<" ";
		cout<<ctext[i];
	}
}
int main()
{
	DES d;
	d.input();
	d.keyGenerate();
	d.initialPermutation();
	d.iterations();
	d.finalPermutation();
	//d.output();
	return 0;
}
