GPP = g++ -O3 -Wall -Wpedantic
TEST_DIR = testing
SOURCE_DIR = source
FINISHED_DIR = archives
SUBDIRS != ls --quoting=shell-escape source
.PHONY: clean zip copy test assembly

# each of the following functions takes 1 parameter: directory

define do_test =
	$(MAKE) -C $(TEST_DIR)/$(1) test
	cat $(TEST_DIR)/$(1)/output
endef 

define do_copy =
	# Ve vill Xtract Ze File!
	ln -s ../$(FINISHED_DIR)/tarfile$(1).tar.gz $(TEST_DIR)
	tar -C$(TEST_DIR) -vxzf $(TEST_DIR)/tarfile$(1).tar.gz
	rm $(TEST_DIR)/tarfile$(1).tar.gz
endef

define do_zip =
	# Ve vill Create Ze File!
	uname -a > $(SOURCE_DIR)/$(1)/SystemUNAME.txt
	tar -C $(SOURCE_DIR) -vczf $(FINISHED_DIR)/tarfile$(1).tar.gz $(1)
endef
 
# requires $(SOURCE_DIR)/$dir to have a makefile
# requires said makefile to include the command './prog | tee output'
# fails if output doesn't exist
test: copy
	$(foreach dir, $(SUBDIRS),$(call do_test,$(dir)))

copy: zip $(TEST_DIR)
	$(foreach dir,$(SUBDIRS),$(call do_copy,$(dir)))

zip: clean $(FINISHED_DIR)
	$(foreach dir,$(SUBDIRS),$(call do_zip,$(dir)))

assembly: $(SOURCE_DIR)
	for dir in $(SOURCE_DIR)/*; do $(MAKE) -C $$dir assembly; done;

$(FINISHED_DIR):
	mkdir $(FINISHED_DIR)

$(TEST_DIR):
	mkdir $(TEST_DIR)

clean:
	rm -rf $(TEST_DIR)
	rm -rf $(FINISHED_DIR) # want a nicer way to do this with make
	for dir in $(SOURCE_DIR)/*; do $(MAKE) -C $$dir clean; done;

tasks:
	@echo clean assembly zip copy test 
