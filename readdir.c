#include <stdio.h>
#include <dirent.h>

int main(){
	DIR *dir;
	struct dirent *entry;

	dir = opendir(".");

	printf("FILES IN THE CURENT DIRECTORY\n");

	while ((entry = readdir(dir)) != NULL){
		printf("%s\n", entry->d_name);
	}

	return 0;
}
