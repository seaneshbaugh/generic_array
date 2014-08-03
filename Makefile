CFLAGS=-std=c11 -Wall -g

UNITY_ROOT=tests/unity

TARGET_NAME=all_tests

SOURCE_FILES=\
	$(UNITY_ROOT)/src/unity.c \
	$(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
	tests/char_array_tests.c \
	tests/double_array_tests.c \
	tests/float_array_tests.c \
	tests/int_array_tests.c \
	tests/long_array_tests.c \
	tests/long_double_array_tests.c \
	tests/long_int_array_tests.c \
	tests/long_long_array_tests.c \
	tests/long_long_int_array_tests.c \
	tests/short_array_tests.c \
	tests/short_int_array_tests.c \
	tests/signed_char_array_tests.c \
	tests/signed_int_array_tests.c \
	tests/signed_long_array_tests.c \
	tests/signed_long_int_array_tests.c \
	tests/signed_long_long_array_tests.c \
	tests/signed_long_long_int_array_tests.c \
	tests/signed_short_array_tests.c \
	tests/signed_short_int_array_tests.c \
	tests/string_array_tests.c \
	tests/unsigned_array_tests.c \
	tests/unsigned_char_array_tests.c \
	tests/unsigned_int_array_tests.c \
	tests/unsigned_long_array_tests.c \
	tests/unsigned_long_int_array_tests.c \
	tests/unsigned_long_long_array_tests.c \
	tests/unsigned_long_long_int_array_tests.c \
	tests/unsigned_short_array_tests.c \
	tests/unsigned_short_int_array_tests.c \
	tests/all_tests.c

INCLUDE_DIRECTORIES=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src

SYMBOLS=

all: clean default

default: test

test:
	$(CC) $(CFLAGS) $(INCLUDE_DIRECTORIES) $(SYMBOLS) $(SOURCE_FILES) -o $(TARGET_NAME)
	./$(TARGET_NAME)

valgrind:
	which valgrind > /dev/null 2>&1
	if [ $$? -eq 0 ]; then valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET_NAME); else echo "Valgrind not found."; fi

clean:
	rm -f $(TARGET_NAME)
	rm -rf $(TARGET_NAME).dSYM
