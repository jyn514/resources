
# makefile to build a program

hello:	hello.o
	g++ hello.o -o hello

all: hello backup

# main 
hello.o: hello.cpp
	g++ -c hello.cpp

.PHONY: clean clobber

clean:
	/bin/rm -f hello *.o

clobber: clean
	rm -rf archive

backup: hello
	if ! [ -d archive ]; then mkdir archive; fi;
	tar cvf archive/hello.`date +%j`.tar *.cpp makefile readme hello # *.h
	gzip -f archive/hello.*.tar
