#include<stdio.h>

typedef unsigned int uint;
uint gcd(uint x,uint y)
{	return y==0? x:gcd(y,x%y);	}

uint multi(uint txt, uint ed, uint n)
{	uint i,rem=1;
	for(i=1; i<=ed; i++)
		rem=(rem*txt)%n;
	return rem;
}
short prime(uint no)
{	uint i;
	for(i=2; i<=no/2; i++)
		if(no%i==0) return 1;
	return 0;
}

int main()
{ 	char msg[100];
 	uint pt[100],ct[100],n,d,e,p,q,z,i,len;

	do{
	printf("\nEnter 2 large prime numbers p & q:\n");
	scanf("%d %d",&p,&q);
	}while(prime(p) || prime(q));
	n=p*q;
	z=(p-1)*(q-1);

	do
	{	printf("\nEnter prime value of e relative to %d(z):",z);
		scanf("%d",&e);
	}while(gcd(e,z)!=1 || e>n);

	for(d=2;d<z;d++)
		if((e*d)%z == 1)
			break;

	printf("Enter the Message\n");		//get message from keybrd.
	len=read(1,msg,100)-1;

	for(i=0;i<len;i++)			//store it in plain text array
		pt[i]=msg[i];

	printf("\n Cipher Text=");
	for(i=0;i<len;i++)			//convert plain to cipher text
		printf("%d ",ct[i]=multi(pt[i],e,n));

	printf("\n Plain Text=");
      for(i=0;i<len;i++)			//convert cipher to plain text
		printf("%c",multi(ct[i],d,n));
}

//Output:-

//[root@localhost nwcn]# cc rs.c
//[root@localhost nwcn]# ./a.out

//Enter 2 large prime numbers p & q:
//11 17

//Enter prime value of e relative to 160(z):159
//Enter the Message
//Siddaganga Institute of Technology

//Cipher Text=164 11 9 27 146 77 27 76 41 66 174 79 57 79 8 79 50 76 155 136 76 118 50 11 9 66 155 71 155 69 77
//Plain Text=Siddaganga Institute of Technology[root@localhost nwcn]# ./a.out

//[root@localhost nwcn]# cc rs.c
//[root@localhost nwcn]# ./a.out

//Enter 2 large prime numbers p & q:
//31 37

//Enter prime value of e relative to 1080(z):1013
//Enter the Message
//Department of ISE

//Cipher Text=956 233 815 1118 761 387 190 233 850 387 94 999 1113 94 1035 885 723
//Plain Text=Department of ISE

