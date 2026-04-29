#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int AT[n], BT[n], CT[n], TAT[n], WT[n], P[n], visited[n];

	for (int i = 0 ; i < n ; i++){
		scanf("%d %d %d", &AT[i], &BT[i], &P[i]);
		visited[i] = 0;
	}

	int time = 0, completed = 0, min;

	while (completed < n){
		min = -1;
		for (int i = 0 ; i < n ; i++){
			if (AT[i] <= time && visited[i] == 0){
				if (min == -1 && P[i] < P[min]){
					min = i;
				}
			}
		}
		if(min == -1){
			time++;
		}else{
			time += BT[min];
			CT[min] = time;
			completed++;
			visited[min] = 1;
		}
	}

	for (int i = 0 ; i < n ; i++){
		printf("%d\n", CT[i]);
	}
	return 0;
	
}
