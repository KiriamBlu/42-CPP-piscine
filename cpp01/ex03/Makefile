NAME = unnecesaryviolence

CXXFLAGS = -Wall -Werror -Wextra

SRCS = HumanB.cpp HumanA.cpp main.cpp Weapon.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
