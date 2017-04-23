# 第一章：UNIX 基础知识
## 输入和输出
### 文件描述符
文件描述符（file descriptor）通常是一个小的非负整数，内核用来标识一个特定进程正在访问的文件。

### 标准输入、标准输出和标准错误
每当运行一个新程序时，所有的 shell 都为其打开这三个描述符。它们在 `unistd.h` 头文件中定义。如下：
```
// /usr/include/unistd.h:213-215L
#define STDIN_FILENO    0       /* Standard input.  */
#define STDOUT_FILENO   1       /* Standard output.  */
#define STDERR_FILENO   2       /* Standard error output.  */
```

## 程序和进程
### 基本概念
* 程序：程序（program）是一个存储在磁盘上某个目录中的可执行文件。内核使用 exec 函数将程序读入内存，并执行程序。
* 进程和进程 ID：程序的执行实例被成为进程（process）。进程 ID站 则为每个进程唯一的数字标识符。

## 进程控制
* `pid_t fork(void)`：创建一个新进程，fork 对父进程返回新的子进程的进程 ID（非负整数），对子进程返回 0。
* `int execle(const char *path, const char *arg, ...)`：执行命令
* `pid_t waitpid(pid_t pid, int *stat_loc, int options)`：等待某个进程终止

## 线程和线程 ID
* 通常，一个进程只有一个控制线程（thread）。
* 一个进程内的所有线程共享同一个地址空间、文件描述符、栈以及与进程相关的属性。因为它们能访问统一存储区，所有各线程在访问共享数据时需要采取同步措施以避免不一致性。

## 出错处理
UNIX 错误代码可通过 `man 3 errno` 查看。这里列出一部分：
```
EACCES          Permission denied (POSIX.1).
EADDRINUSE      Address already in use (POSIX.1).
EADDRNOTAVAIL   Address not available (POSIX.1).
```

错误处理相关的两个函数：
* `char *strerror(int errnum)`：将 errnum 映射为一个出错消息。
* `void perror(const char *s)`：基于 errno 的当前值，在标准错误上产生一条出错消息，然后返回。

## 用户标识
### /etc/passwd - 存储用户账户信息
/etc/passwd 文件中的一行为一个用户的信息，使用冒号分割七个字段。如：`root:x:0:0:root:/root:/bin/zsh`。
各个字段分别是：
* 用户名
* 加密后的密码，使用 x 表示，具体的密码保存在 /etc/shadow 中
* 数字用户 ID
* 数字组 ID
* 注释字段
* 用户主目录（HOME）
* 用户命令解释器（shell）

root 的用户 ID 和组 ID 都为0。

### /etc/group - 存储用户组信息
/ett/group 同样使用冒号分割，有４个字段。如：`daemon:x:2:root,bin,daemon`。分别是：
* 组名
* 加密后的组密码
* 数字组 ID
* 用户列表，使用逗号分隔