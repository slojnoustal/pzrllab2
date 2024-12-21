CC = gcc
CFLAGS = -Wall -g
OBJ = main.o text_processing.o file_utils.o
TARGET = sed_simplified

all: $(TARGET)

$(TARGET): $(OBJ)
 $(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
 $(CC) $(CFLAGS) -c $<

clean:
 rm -f $(OBJ) $(TARGET)

test:
 ./$(TARGET) test.txt -r "old" "new"
