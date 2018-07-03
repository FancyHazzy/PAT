#include <stdio.h>

int main (void)
{
	long long C1,C2,secs,HH,MM,SS;

	scanf("%lld%lld",&C1,&C2);
	secs = (C2 - C1 + 50) / 100;
	HH = secs / 3600;
	MM = (secs % 3600) / 60;
	SS = secs % 60;
	printf("%02d:%02d:%02d\n",HH,MM,SS);

	return 0;
}
