#include <stdio.h>

#define B_0001	1
#define B_0010	2
#define B_0011	3
#define B_0100	4
#define B_0101	5
#define B_0110	6
#define B_0111	7
#define B_1000	8
#define B_1001	9
#define B_1010	a
#define B_1011	b
#define B_1100	c
#define B_1101	d
#define B_1110	e
#define B_1111	f

#define _B2H(bits)	B_##bits
#define B2H(bits)	_B2H(bits)
#define _HEX(n)	    0x##n##UL
#define HEX(n)		_HEX(n)
#define _CCAT(a, B)	a##b
#define CCAT(a, B)   _CCAT(a, B)

#define BYTE(a,B)				HEX( CCAT(B2H( a), B2H( B)) )
#define WORD(a,b,c,d)			HEX( CCAT(CCAT(B2H( a), B2H( B)), CCAT(B2H( c), B2H( d))) )
#define DWORD(a,b,c,d,e,f,g,h)	HEX( CCAT( CCAT(CCAT(B2H( a),B2H( B)),CCAT(B2H( c),B2H( d))),CCAT(CCAT(B2H( e),B2H( f)),CCAT(B2H( g),B2H( h))) )  )

#define INT_i(n)	int i##n = n;
#define SUM(res,n)	((res) += (i##n))
#define PRINT(n)	printf("i%d = %d\n", n, i##n)


int main() 
{
	int res  =0;
	int i;

	for(i=0;i<10;i++)
	{
		INT_i(i);
		PRINT(i);
		SUM(res,i);
	}

	printf("Result : %d\n", res);

	printf("0b01000001=%ld\n", BYTE(0000, 0001));

	return 0;
}
