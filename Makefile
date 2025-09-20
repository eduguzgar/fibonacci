CC      := gcc
CFLAGS  := -Wall -Wextra -O2
BINDIR  := bin
TESTDIR := tests

SRCDIR := src/fibonacci
APP    := $(BINDIR)/fibonacci
TEST_FIB   := $(BINDIR)/tests_fibonacci
APP_SRCS  := $(SRCDIR)/main.c $(SRCDIR)/fibonacci.c
TEST_FIB_SRCS := $(TESTDIR)/test_fibonacci.c $(SRCDIR)/fibonacci.c

SRCDIR_N4 := src/fibonacci_n4
APP_N4    := $(BINDIR)/fibonacci_n4
TEST_N4   := $(BINDIR)/tests_fibonacci_n4
APP_SRCS_N4  := $(SRCDIR_N4)/main.c $(SRCDIR_N4)/fibonacci_n4.c
TEST_SRCS_N4 := $(TESTDIR)/test_fibonacci_n4.c $(SRCDIR_N4)/fibonacci_n4.c

.PHONY: all app app_n4 test test_n4 run run_n4 dirs clean

# Build all
all: app app_n4 test test_n4

# Apps
app: dirs $(APP)
$(APP): $(APP_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $@

app_n4: dirs $(APP_N4)
$(APP_N4): $(APP_SRCS_N4)
	$(CC) $(CFLAGS) -I$(SRCDIR_N4) $^ -o $@

# Tests
test: dirs $(TEST_FIB)
$(TEST_FIB): $(TEST_FIB_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $@

test_n4: dirs $(TEST_N4)
$(TEST_N4): $(TEST_SRCS_N4)
	$(CC) $(CFLAGS) -I$(SRCDIR_N4) $^ -o $@

# Run
run: app
	$(APP)

run_n4: app_n4
	$(APP_N4)

# Utility
dirs:
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR)
