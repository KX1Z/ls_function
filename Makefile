##
## EPITECH PROJECT, 2022
## B-CPE-101-LYN-3-1-myls-arthur.maquet
## File description:
## Makefile
##

# Constants
CC	=	gcc
LIB	=	libmy.a
EXEC	=	my_ls

INCLUDE_DIR	=	./include
LIB_DIR		=	./lib
LIB_FILES	=	$(shell find $(LIB_DIR) -type f -name "*.c")
SRC_DIR		=	./src
SRC_FILES	=	$(shell find $(SRC_DIR) -type f -name "*.c")
SRC_OBJ_FILES	=	$(SRC_FILES:.c=.o)
LIB_OBJ_FILES	=	$(LIB_FILES:.c=.o)

# Flags
CFLAGS	=	-Wall -Wextra -g3

# Rules
.PHONY: all clean fclean re

all: $(EXEC)

$(EXEC): $(LIB) $(SRC_OBJ_FILES)
	@$(CC) -o $(EXEC) $(SRC_OBJ_FILES) -L. -lmy $(CFLAGS)
	@echo "\033[1;32m[OK]\033[0m" $(EXEC)

$(LIB): $(LIB_OBJ_FILES)
	@ar rc $(LIB) $(LIB_OBJ_FILES)
	@echo "\033[1;32m[OK]\033[0m" $(LIB)

$(LIB_OBJ_FILES): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32m[OK]\033[0m" $@

$(SRC_OBJ_FILES): %.o: %.c
	@$(CC) -c $(CFLAGS) -I$(INCLUDE_DIR) $< -o $@
	@echo "\033[1;32m[OK]\033[0m" $@

clean:
	@if [ -f $(LIB) ]; then \
		rm -f $(LIB_OBJ_FILES); \
		echo "\033[1;31m[OK]\033[0m" $(LIB_OBJ_FILES); \
	fi
	@if [ -f $(EXEC) ]; then \
		rm -f $(SRC_OBJ_FILES); \
		echo "\033[1;31m[OK]\033[0m" $(SRC_OBJ_FILES); \
	fi

fclean: clean
	@rm -f $(LIB) $(EXEC)
	@echo "\033[1;31m[OK]\033[0m" $(LIB) $(EXEC)

re: fclean all
