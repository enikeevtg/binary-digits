.PHONY: all clean test binary.a gcov_report

# UTILITIES
CC = gcc
AR = ar rs
RAN = ranlib
MK = mkdir -p
MAKE = make

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra
TEST_FLAGS = -lcheck
DEBUG = #-DDEBUG

# FILENAMES
LIB = ../binary.a
TEST_TARGETS = test_get_bit test_set_bit test_addition test_subtruction test_multiplication test_shift

# LOG = test_binary.log
# WRITELOG = >> $(LOG)
# OPENLOG = open $(LOG)


# TESTS
test: clean UT_start_msg $(TEST_TARGETS)
	$(OPENLOG)

UT_start_msg:
	@echo "\n\033[0;32m>>>>>>>>SET OF UNIT TESTS LAUNCHED<<<<<<<<\033[0m" $(WRITELOG)

test_get: clean test_get_bit
	$(OPENLOG)

test_get_bit: test_get_bit.c
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_set: clean test_set_bit
	$(OPENLOG)

test_set_bit: test_set_bit.c
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_add: clean test_addition
	$(OPENLOG)

test_addition: test_add.c
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_sub: clean test_subtruction
	$(OPENLOG)

test_subtruction: test_sub.c
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB) $(DEBUG)
	@./$@ $(WRITELOG)
	@rm -f $@

test_mul: clean test_multiplication
	$(OPENLOG)

test_multiplication: test_mul.c
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_shift: test_shift.c
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@


# SERVICES
style:
	clang-format --style=google -n $(SRCDIR)*.c *.h *.c
	
gost:
	clang-format --style=google -i $(SRCDIR)*.c *.h *.c

clean:
	rm -rf $(LOG)
