NAME = easyfind

CXXFLAGS = -Wall -Werror -Wextra # -fsanitize=address

SRCS = main.cpp 

OBJS = $(SRCS:.cpp=.o)

CXX = c++

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
