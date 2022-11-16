NAME = Brain 

CXXFLAGS = -Wall -Werror -Wextra -Wshadow  -Wno-shadow

SRCS = Dog.cpp main.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp Cat.cpp WrongDog.cpp Brain.cpp

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
