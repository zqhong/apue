#include <apue.h>

int main(void) {
    printf("uid = %d, guid = %d\n", getuid(), getgid());
    exit(0);
}