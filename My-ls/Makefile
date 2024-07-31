CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
TARGET = my_ls
SRCS = my_ls.c lib/print_files.c lib/print_files_details.c lib/reverse_array.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

fclean: clean

re: fclean all