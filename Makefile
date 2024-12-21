CC = gcc
CFLAGS = -Wall -g
OBJ = main.o file_utils.o text_processing.o
TARGET = sed_simplified

# Цель по умолчанию
all: $(TARGET)

# Правило для сборки исполнимого файла
$(TARGET): $(OBJ)
<TAB>$(CC) $(CFLAGS) -o $@ $(OBJ)

# Правила для компиляции исходных файлов
%.o: %.c
<TAB>$(CC) $(CFLAGS) -c $<

# Удаление объектных файлов и исполняемого файла
clean:
<TAB>rm -f $(OBJ) $(TARGET)

# Тестирование программы
test:
<TAB>./$(TARGET) test.txt -r "old" "new"
