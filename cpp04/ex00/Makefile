NAME = Animals

CXXFLAGS = -Wall -Werror -Wextra -Wall -Werror -Wextra -Wshadow  -Wno-shadow

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

exe: $(NAME)
	time ./$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
