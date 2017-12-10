
# makefile to build a program

# variables
archive = jynelson.assignment4_1.tar
main_files = main.cpp name.cpp makefile readme name.h

# recipies
myname:      main.o name.o 
	g++ -g  main.o name.o -o myname

# name.cpp has it's own header file
name.o:        name.cpp name.h
	g++ -c -g  name.cpp

# main.cpp also uses the header file name.h
main.o:	       main.cpp name.h
	g++ -c -g main.cpp

main.s: main.cpp
	g++ -S main.cpp

name.s: name.cpp name.h
	g++ -S name.cpp

$(archive): $(main_files)
	tar -czvf $(archive) $(main_files)

# aliases
.PHONY: all backup clean clobber assembly over

assembly: main.s name.s

backup: $(archive)

all: assembly myname backup

clean:
	/bin/rm -f myname *.o *.out
	/bin/rm -f *.s 

clobber: clean
	/bin/rm -f $(archive)*

over: clobber myname
