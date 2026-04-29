#include <stdio.h>

int main(){
	int n, frames;

	scanf("%d", &n);

	int reference[n];

	for (int i = 0 ; i < n ; i++){
		scanf("%d", &reference[i]);
	}

	scanf("%d", &frames);

	int frame[frames];

	for (int i = 0 ; i < n ; i++){
		frame[i] = -1;
	}

	int front = 0, hits = 0, miss = 0;

	for (int i = 0 ; i < n ; i++){
		int found = 0;
		for (int j = 0 ; j < frames ; j++){
			if (frame[j] == reference[i]){
				found = 1;
				hits++;
				break;
			}
		}
		if (!found){
			frame[front] = reference[i];
			front = (front + 1) % frames;
			miss++;
		}
	}
	printf("%d %d", hits, miss);
	return 0;
	
}
