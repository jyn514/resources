all:	main

main.o:	main.c
	gcc -c main.c
main:	main.o
	gcc -g main.o -o howdy

clean:
	/bin/rm -f howdy main.o

backup:
	tar cvf `date +%j`.tar *.c howdy Makefile README
	gzip *.tar
	cp *.tar.gz /work/yourname/
	mv *.tar.gz /acct/s1/yourname/LINUX/pgms/c/archive/
	ls -l /acct/s1/yourname/LINUX/pgms/c/archive


