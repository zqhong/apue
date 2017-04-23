#include <apue.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // strerror 将 errnum 映射为一个出错消息
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    fprintf(stderr, "EFBIG: %s\n", strerror(EFBIG));

    // 设置当前的 errno 为 ENOENT
    errno = ENOENT;

    // argv[0] 为可执行文件名，如：./bin/error
    // 这句话将打印：./bin/error: No such file or directory
    perror(argv[0]);

    // 这句话将打印：abc: No such file or directory
    perror("abc");

    exit(0);
}