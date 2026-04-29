#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int tq;
	scanf("%d", &tq);
	int at[n], bt[n], ct[n], tat[n], wt[n], rt[n];

	for (int i = 0 ; i < n ; i++){
		scanf("%d %d", &at[i], bt[i]);
		rt[i] = bt[i];
	}

	int time, completed = 0;

	while (completed < n){
		int done = 1;
		for (int i = 0 ; i < n ; i++){
			if (rt[i] > 0 && at[i] <= time){
				done = 0;
				if(rt[i] > tq){
					time += tq;
					rt[i] -= tq;
				}else{
					time += rt[i];
					rt[i] = 0;
					ct[i] = time;
					completed++;
				}
			}
		}
		if (done == 1){
			time++;
		}
	}
}
