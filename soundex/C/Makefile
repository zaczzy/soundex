CC = clang
CFLAGS = -g -Wall
S_FLAGS = -fsanitize=address -fno-omit-frame-pointer
default: soundex

soundex : soundex.o
	$(CC) $(CFLAGS) $(S_FLAGS) $^ -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) soundex soundex.o