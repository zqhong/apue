all:
	gcc ls.c -o ls
	gcc cp.c -o cp

clean:
    # 删除当前目录下 *.c、*.h 或 Makefile 以外的所有普通文件
	find . -type f ! \( -name "*.c" -o -name "*.h" -o -name "Makefile" \) | xargs rm -f