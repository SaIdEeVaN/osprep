#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int AT[n], BT[n], CT[n], TAT[n], WT[n];

	for (int i = 0 ; i < n ; i++){
		scanf("%d %d", &AT[i], &BT[i]);
	}

	CT[0] = AT[0] + BT[0];

	for (int i = 1 ; i < n ; i++){
		if (CT[i - 1] < AT[i]){
			CT[i] = AT[i] + BT[i];
		}else{
			CT[i] = CT[i - 1] + BT[i];
		}
	}

	int avgTAT, avgWT;

	for (int i = 0 ; i < n ; i++){
		TAT[i] = CT[i] - AT[i];
		WT[i] = TAT[i] - BT[i];
		avgTAT += TAT[i];
		avgWT += WT[i];
	}

	printf("%.2f\n%.2f", (float)avgTAT/n, (float)avgWT/n);
	return 0;
}

