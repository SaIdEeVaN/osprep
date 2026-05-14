#include <stdio.h>
#include <dirent.h>

int main(){
	DIR *dir;
	dir = opendir(".");

	if (dir == NULL){
		printf("THE CODE DOESNT WORK FUCKER\n");
		return 1;
	}

	printf("DIRECTORY OPENED SUCESSFULLY\n");
	closedir(dir);
	return 0;
}
