#include <stdio.h>
int main (void){
	int N, t;
	int a[100010] = {0}, b[10010] = {0};
	scanf("%d",&N);

	for (int i = 0;i < N;i++){
		scanf("%d", &a[i]);
		b[a[i]] += 1;
	}
	for (int i = 0;i < N;i++){
		if (b[a[i]] == 1){
			printf("%d", a[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}
