# **************************************************************************** #

NAME		?=	btc

SRCS		?=	BitcoinExchange.cpp
SRCS		+=	main.cpp

# **************************************************************************** #

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3 -gdwarf-3

OBJS		:=	$(SRCS:.cpp=.o)

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

# **************************************************************************** #

run: $(NAME)
	@clear
	@./$(NAME)

vgrun: $(NAME)
	@clear
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(VG_ARGS)

# **************************************************************************** #

.PHONY: all clean fclean re run vgrun
