#include <stdio.h>
int main (void)
{
	long long A,DA,B,DB,PA = 0,PB = 0;
	scanf("%lld%lld%lld%lld",&A,&DA,&B,&DB);
	while(A != 0){
		if (A % 10 == DA) PA = 10 * PA + DA;
		A = A / 10;		
	}
	while(B != 0){
		if (B % 10 == DB) PB = 10 * PB + DB;
		B = B / 10;
	}
	printf("%lld",PA+PB);
	
	return 0;
}
