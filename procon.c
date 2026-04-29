#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 5, x = 0;

int wait(int s){
	return --s;
}

int signal(int s){
	return ++s;
}

void producer(){
	mutex = wait(mutex);
	empty = wait(empty);
	full = signal(full);

	x++;
	printf("\nProducer produced : %d\n", x);

	mutex = signal(mutex);
}

void consumer(){
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);

	printf("\nConsumer consumed : %d\n", x);
	x--;

	mutex = signal(mutex);
}

int main(){
	int n;

	printf("\nProducer consumer problem\n");
	printf("1. Produce an item\n");
	printf("2. Consume an item\n");
	printf("3. Exit\n");

	while(1){
		scanf("%d", &n);
		switch(n){
			case (1):
				if (mutex == 1 && empty != 0){
					producer();
				}else{
					printf("The memory is full retard");
				}
				break;

			case (2):
				if (mutex == 1 && full != 0){
					consumer();
				}else{
					printf("The memory is empty retard");
				}
				break;

			case (3):
				printf("Bye bye retard");
				exit(0);

			default:
				printf("please enter a valid option");
				break;
		}
	}
	return 0;
}
