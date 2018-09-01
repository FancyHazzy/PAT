#include <stdio.h>
 int main (void){
 	int N, temp, score, a;
 	int team[1010] = {0};
 	int MAXSCORE = 0,TEAM;
 	scanf("%d", &N);
 	for (int i = 0; i < N; i++){
 		scanf("%d-%d %d", &a, &temp, &score);
 		team[a] += score;
 		if (team[a] > MAXSCORE){
 			MAXSCORE = team[a];
 			TEAM = a;
 		}

 	}


 	printf("%d %d", TEAM, MAXSCORE);

 	return 0;
 }
