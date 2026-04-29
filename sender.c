#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(){
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, 1024, 066 | IPC_CREAT);
	char *str = (char*) shmat(shmid, (void*)0, 0);

	printf("Write data to send : ");
	fgets(str, 1024, stdin);

	shmdt(str);
	return 0;
	
}
