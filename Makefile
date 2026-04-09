# Compilador
CC = gcc

#Bandera de compilacion 
CFLAGS = -Wall -Wextra -Iinclude

#Archivos a compilar
SRC=src/*.c main.c

#Nombre del ejecutable 
TARGET=lista_ligada

#Regla principal para compilar
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

#Regla para ejecutar
run: all
	./$(TARGET)

#Regla para borrar los archivos generados al compilar
clean:
	rm -f $(TARGET)	
