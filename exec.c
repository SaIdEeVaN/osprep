#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec()\n");
    execl("/bin/ls", "ls", NULL);
    /*anything after the execl command, nothing executes*/
    printf("After exec()\n");
    return 0;
}
