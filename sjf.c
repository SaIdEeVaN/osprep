#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int AT[n], BT[n], CT[n], TAT[n], WT[n], visited[n];

	for (int i = 0 ; i < n ; i++){
		scanf("%d %d", &AT[i], &BT[i]);
		visited[i] = 0;
	}

	int time, completed = 0, min;

	while (completed < n){
		min = -1;
		for (int i = 0 ; i < n ; i++){
			if (AT[i] <= time && visited[i] == 0){
				if (min == -1 || BT[i] < BT[min]){
					min = i;
				}
			}
		}
		if (min == -1){
			time++;
		}else{
			time += BT[min];
			CT[min] = time;
			visited[min] = 1;
			completed++;
		}
	}

	int totalWT, totalTAT;

	for (int i = 0 ; i < n; i++){
		TAT[i] = CT[i] - AT[i];
		WT[i] = TAT[i] - BT[i];

		totalTAT += TAT[i];
		totalWT += WT[i];
	}

	printf("%.2f\n%.2f\n", (float)totalTAT/n, (float)totalWT/n);
	return 0;
	
}
