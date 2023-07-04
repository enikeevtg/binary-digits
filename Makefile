.PHONY: all clean test binary.a gcov_report

# UTILITIES
CC = gcc
AR = ar rs
RAN = ranlib
MK = mkdir -p
MAKE = make

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra
DEBUG = #-DDEBUG

# FILENAMES
TARGET = binary.a
SRCDIR = src/
OBJDIR = obj/
SRC = $(wildcard $(SRCDIR)*.c)
OBJ = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRC))
TESTDIR = tests/


# MAIN TARGET
lib: $(TARGET)

$(TARGET): objects
	@$(AR) $@ $(OBJ)
	@$(RAN) $@
	@echo "$(AR): creating library $(TARGET) \033[0;32msuccess\033[0m"

objects: makeobjdir $(OBJ) OBJ_SUCCESS

makeobjdir:
	@$(MK) $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CF) -c $< -o $@ $(DEBUG)

OBJ_SUCCESS:
	@echo "$(CC): objects compilation \033[0;32msuccess\033[0m"


# TESTS
test: lib
	$(MAKE) -C $(TESTDIR) $@

test_add: lib
	$(MAKE) -C $(TESTDIR) $@

test_sub: lib
	$(MAKE) -C $(TESTDIR) $@

test_mul: lib
	$(MAKE) -C $(TESTDIR) $@

test_get: lib
	$(MAKE) -C $(TESTDIR) $@

test_set: lib
	$(MAKE) -C $(TESTDIR) $@

test_shift: lib
	$(MAKE) -C $(TESTDIR) $@

# SERVICES
style:
	clang-format --style=google -n $(SRCDIR)*.c *.h $(TESTDIR)*.c
	
gost:
	clang-format --style=google -i $(SRCDIR)*.c *.h $(TESTDIR)*.c

clean:
	rm -rf $(TARGET) $(OBJDIR) *.out *.gch

