# Copyright (c) 2017 Joshua Nelson
# Licensed under the GNU General Public License v3.0

# In short, you may modify, distribute, or copy this program,
# but you may not change this license and you MUST make any
# modifications available AS SOURCE CODE to the users of this program.

# See https://www.gnu.org/licenses/gpl-3.0.en.html for details.


# ADD THIS FIRST
# program name here (requires proper capitalization)
PROGRAM = didnt-change-makefile

#### Note before further modification: ####

# Many of these variables are used further on,
# especially in recipies for $(ARCHIVE) and $(TEST),
# as well as pattern-matching.

# If you simply uncomment existing code, you'll be fine.

# However, you may wish to glance over the rest of this file
# before making changes.

#### If working with C++ #################

#SOURCE = $(PROGRAM).cpp
#COMPILED = $(PROGRAM)

#$(COMPILED): $(SOURCE)
#	@:$(call fail_if_not_defined, SOURCE)
#	$(CC) -o $(COMPILED) $(SOURCE)

#$(PROGRAM).s: $(SOURCE)
#	@:$(call fail_if_not_defined, SOURCE)
#	$(CC) -S $(SOURCE)

#assembly: $(PROGRAM).s


#### If working with Java ################

#SOURCE = $(PROGRAM).java
#COMPILED = $(PROGRAM).class
#$(COMPILED): $(SOURCE)
#	@:$(call fail_if_not_defined,SOURCE)
#	$(JAVAC) $(JAVACFLAGS) $(SOURCE)

# nothing to do, class files are (in essence) assembly
# more info here: https://en.wikipedia.org/wiki/Java_bytecode
#assembly:

###########################################

# For your own sanity, I recommend you keep this updated
tasks:
	@echo tasks: backup clean clobber over all \
		     run test assembly clean_run self_check

all: $(COMPILED)

# Change this to a goal to have it run when make is called without arguments
# You will likely want it to be $(COMPILED) or all
.DEFAULT_GOAL := tasks

# If you add named goals, add them here to avoid naming conflicts
.PHONY: clean clobber backup tasks over all \
	test archive assembly run clean_run self_check

# := means evaluate immediately instead of lazily
ARCHIVE := archives/$(PROGRAM)-`date -I`.tar

# Files that will be used later; feel free to change these
# Note, your test directory should NOT be the same as your current directory,
# as this will overwrite your existing files
TEST_ARCHIVE = testing/test.tar.gz
TEST_SCRIPT = test.sh

# I strongly encourage adding more tests
define my_tests =
	make
	make backup
	cat $(README)
endef

clean:
	rm -rf testing
	rm -f $(COMPILED) *.out *.o *.class

# add more files on next line for them to be added automatically to archive
$(ARCHIVE): archives $(MAKEFILE) $(README) $(SOURCE)
	@:$(call fail_if_not_defined,ARCHIVE MAKEFILE README SOURCE, \
		Files starting with readme will be added automatically)
	tar -cvzf $(ARCHIVE) $(filter-out archives ,$^)

###################### ARE YOU SURE YOU WANT TO EDIT ? ########################

# Good luck! For help, see
# https://www.gnu.org/software/make/manual/html_node/index.html#Top
# or email me at 'jyn514 AT gmail DOT com'

# Makefile specific
SHELL = sh
export MAKEFLAGS += --warn-undefined-variables -S
# get current makefile
# assumes current dir has no spaces in name (if false, rethink your choices)
MAKEFILE := $(lastword $(MAKEFILE_LIST))

# Compilers and flags
CC = g++ -g -Wall -Wpedantic
JAVAC != which javac
# note: if using the (deprecated) gcj, these flags are invalid.
JAVAC += -g -Xlint:all -source 1.8 -target 1.8

# ignore case, undefined if nothing exists
# https://unix.stackexchange.com/questions/198254
ifeq ($(shell find -maxdepth 1 -iname readme | wc -l), 0)
	README =
else
	README != find -maxdepth 1 -iname 'readme*'
endif

# Takes 2 params: variable(s) which must exist, seperated by spaces (required); and description (optional)
# https://stackoverflow.com/questions/10858261
fail_if_not_defined = \
    $(strip $(foreach arg,$1, \
        $(call __check_single_var_defined,$(arg),$(strip $(value 2)))))

__check_single_var_defined = \
    $(if $(value $1),, \
      $(error $1 undefined$(if $2,. Comment: $2)))

# pattern matching: java
$(filter .class,$(COMPILED)): %.class: %.java
ifneq ($(strip $^),)
	$(JAVAC) $<
endif

# pattern matching: all .o files require corresponding .c or .cpp files
$(filter .o,$(COMPILED)): %.o: %.cpp
ifneq ($(strip $^),)
	$(CC) -c $^ -o $@
endif

# Directories; should be variables but I find make variables irritating to read
archives:
	mkdir archives

testing:
	mkdir testing

# overwrites existing test archive
$(TEST_ARCHIVE): $(ARCHIVE) testing
	ln -f $(ARCHIVE) $(TEST_ARCHIVE)

$(TEST_SCRIPT): testing
	echo 'cd testing' > $(TEST_SCRIPT)
	echo 'tar -xvzf $(TEST_ARCHIVE)' >> $(TEST_SCRIPT)
	# this makes $(TEST_SCRIPT) look strange, I'll take ideas for making it nicer
	echo $(my_tests) | tr '\n' ';' >> $(TEST_SCRIPT)
	./$(COMPILED) | tee output1
	echo "make clean" >> $(TEST_SCRIPT)
	chmod u+x $(TEST_SCRIPT)


archive: $(ARCHIVE)

backup: $(ARCHIVE)

clobber: clean
	rm -rf archives

over: clean all

run: $(COMPILED)
	./$(COMPILED)

clean_run: clean run

self_check:
	@printf "Running test of $(MAKEFILE). Don't worry, none of these commands are actually executing.\n\n"

	@$(MAKE) -f $(MAKEFILE) --warn-undefined-variables --no-keep-going --dry-run test \
	&& echo All good! || printf "\nFailed. See above for reason.\n"

test: clean $(TEST_ARCHIVE) $(TEST_SCRIPT)
	./$(TEST_SCRIPT)

check: test
