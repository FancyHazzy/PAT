#include <stdio.h>
int main (void){
	int num = 1111;
	int a[1111] = {0};
	int N, M,t;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N;i++){
		scanf("%d", &t);
		a[t] += 1;
	}
	int f = 0;
	for (int f = 0;f < num;f++){
		if (a[f] >= 1 && a[M-f] >= 1){
			printf("%d %d", f, M-f);
			return 0;
		}
		if (f == (M-f) && a[f] > 1){
			printf("%d %d", f, M-f);
			return 0;
		}
	}
	
	printf("No Solution\n");
	return 0;
}
