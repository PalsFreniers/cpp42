NAME = btc

INCLUDES = inc/

CFLAGS = -I$(INCLUDES) -Werror -Wall -Wextra -g --std=c++98
CC = c++

SRC_DIR = src/
SRC_NAME =	main.cpp \
			BitcoinExchange.cpp \
			StockMarket.cpp \
			Date.cpp \

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $< -c -o $@
	@echo "\033[1;36m Compiled" $(*F)


$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\033[1;32m Executable" $(NAME) "created"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;31m Deleted all object files"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31m Deleted $(NAME)"

all: $(NAME)

re: fclean all
