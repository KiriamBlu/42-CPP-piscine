NAME = min_max_swap

VERSION = --std=c++98

CXXFLAGS = -Wall -Werror -Wextra $(VERSION) -Wshadow  -Wno-shadow

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

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
