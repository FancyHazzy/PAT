#include <stdio.h>
int main (void){
	char table_a[10010], table_b[10010];
	int table_c[128] = {0};//初始化为0
	gets(table_a);
	gets(table_b);
	int len_a = strlen(table_a);
	int len_b = strlen(table_b);
	for (int i = 0;i < len_b;i++){
		table_c[table_b[i]] = 1;
	}
	for (int i = 0;i< len_a;i++){
		if (table_c[table_a[i]] == 0){
			printf("%c", table_a[i]);
		}
	}

	return 0;
}
