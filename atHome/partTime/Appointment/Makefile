# Project: 校医院锟斤拷锟斤拷系统
# Makefile created by Dev-C++ 5.11

CPP      = g++.exe -D__DEBUG__
CC       = gcc.exe -D__DEBUG__
WINDRES  = windres.exe
OBJ      = main.o
LINKOBJ  = main.o
LIBS     = -L"D:/系统锟斤拷锟斤拷锟斤拷装/Dev/Dev-Cpp/MinGW64/lib" -L"D:/系统锟斤拷锟斤拷锟斤拷装/Dev/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib" -static-libgcc -g3
INCS     = -I"D:/系统锟斤拷锟斤拷锟斤拷装/Dev/Dev-Cpp/MinGW64/include" -I"D:/系统锟斤拷锟斤拷锟斤拷装/Dev/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"D:/系统锟斤拷锟斤拷锟斤拷装/Dev/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include"
CXXINCS  = -I"D:/系统锟斤拷锟斤拷锟斤拷装/Dev/Dev-Cpp/MinGW64/include" -I"D:/系统锟斤拷锟斤拷锟斤拷装/Dev/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"D:/系统锟斤拷锟斤拷锟斤拷装/Dev/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" -I"D:/系统锟斤拷锟斤拷锟斤拷装/Dev/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++"
BIN      = 校医院锟斤拷锟斤拷系统.exe
CXXFLAGS = $(CXXINCS) -g3
CFLAGS   = $(INCS) -g3
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.c
	$(CC) -c main.c -o main.exe $(CFLAGS)
