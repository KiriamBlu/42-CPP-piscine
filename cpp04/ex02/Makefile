NAME = Abstract 

CXXFLAGS = -Wall -Wextra -Wshadow  -Wno-shadow

SRCS = Dog.cpp main.cpp Animal.cpp Cat.cpp Brain.cpp

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
