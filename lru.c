#include <stdio.h>

int main(){
	int n, frames;

	scanf("%d", &n);

	int ref[n];

	for (int i = 0 ; i < n ; i++){
		scanf("%d", &ref[i]);
	}

	scanf("%d", &frames);

	int frame[frames],time[frames];

	for (int i = 0 ; i < frames ; i++){
		frame[i] = -1;
		time[i] = 0;
	}

	int counter, hits, miss;

	for (int i = 0 ; i < n ; i++){
		int found = 0;
		for (int j = 0 ; j < frames ; j++){
			if (frame[j] == ref[i]){
				counter++;
				hits++;
				time[j] = counter;
				found = 1;
				break;
			}
		}
		if (!found){
			int	lruIndex = 0;
			for (int j = 1 ; j < frames ; j++){
				if (time[j] < time[lruIndex]){
					lruIndex = j;
				}
			}
			counter++;
			time[lruIndex] = counter;
			frame[lruIndex] = ref[i];
			miss++;
		}
	}
	printf("%d %d\n", hits, miss);
	return 0;
}
