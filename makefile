
# SELECT TARGET OPERATING SYSTEM 
OS = LINUX


CC = gcc
SRC_DIR = Src
INC_DIR = Inc
OBJ_DIR = Obj
CFLAGS = -Wall -g -Wl,--export-dynamic
PACKAGE = `pkg-config --cflags --libs gtk+-3.0 gmodule-2.0`
LIBS = `pkg-config --libs gtk+-3.0 gmodule-2.0`
EXE = Gui

# CONDITIONAL COMPILATION
ifeq ($(OS), "WINDOWS")
SERIAL = WinSerial
CLEAR = cls
else
SERIAL = LinSerial
CLEAR = clear
endif


SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/error.c 
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/error.o


all: clean build

#build:
#	$(CC) $(CFLAGS) -o $(EXE) -I$(INC_DIR) $(SRCS) $(PACKAGE)

build: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -I$(INC_DIR) $< -o $@ $(PACKAGE)

		
clean :
	$(CLEAR)
	rm -f $(OBJS)
