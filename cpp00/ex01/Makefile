NAME = phonebook

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ./main.cpp	\
	   ./contact_var.cpp	\
	   ./phonebook.cpp	\


OBJS = $(SRCS:.cpp=.o)

CXX = clang++

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
