CC    	:= gcc
CFLAGS  := -Wall -Wextra -O2
BINDIR  := bin
SRCDIR	:= src
TESTDIR := test

APP_NAME := fibonacci
APP := $(BINDIR)/$(APP_NAME)
TEST := $(BINDIR)/tests_$(APP_NAME)
APP_SRCS := $(SRCDIR)/$(APP_NAME)/main.c $(SRCDIR)/$(APP_NAME)/$(APP_NAME).c
TEST_SRCS := $(TESTDIR)/$(APP_NAME)/test_$(APP_NAME).c $(SRCDIR)/$(APP_NAME)/$(APP_NAME).c

APP_NAME_N4 := fibonacci_n4
APP_N4 := $(BINDIR)/$(APP_NAME_N4)
TEST_N4 := $(BINDIR)/tests_$(APP_NAME_N4)
APP_SRCS_N4 := $(SRCDIR)/$(APP_NAME_N4)/main.c $(SRCDIR)/$(APP_NAME_N4)/$(APP_NAME_N4).c
TEST_SRCS_N4 := $(TESTDIR)/$(APP_NAME_N4)/test_$(APP_NAME_N4).c $(SRCDIR)/$(APP_NAME_N4)/$(APP_NAME_N4).c

.PHONY: all app app_n4 test test_n4 run run_n4 dirs clean

# Build all
all: app app_n4 test test_n4

# Apps
app: dirs $(APP)

$(APP): $(APP_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR)/$(APP_NAME) $^ -o $@

app_n4: dirs $(APP_N4)

$(APP_N4): $(APP_SRCS_N4)
	$(CC) $(CFLAGS) -I$(SRCDIR)/$(APP_NAME_N4) $^ -o $@

# Tests
test: dirs $(TEST)
	@echo "Running $(TEST)"
	$(TEST)

$(TEST): $(TEST_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR)/$(APP_NAME) $^ -o $@

test_n4: dirs $(TEST_N4)
	@echo "Running $(TEST_N4)"
	$(TEST_N4)

$(TEST_N4): $(TEST_SRCS_N4)
	$(CC) $(CFLAGS) -I$(SRCDIR)/$(APP_NAME_N4) $^ -o $@

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
