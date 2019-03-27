CC	=	g++

RM	=	rm -f

SRC	=	src/

SRCS	=	$(SRC)main.cpp

OBJ	=	$(SRCS:.cpp=.o)

NAME	=	workshop

CXXFLAGS	+=	-Wall -Wextra -Werror -I./include -std=c++11

THREAD	=	-lpthread

IRR	=	-lIrrlicht

GL	=	-lGL

X11 =   -lX11

Xx  =   -lXxf86vm

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(THREAD) $(IRR) $(GL) $(X11) $(Xx) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(SRCS:.cpp=.cpp~)
	$(RM) $(SRCS:.cpp=.cpp#)

fclean: clean
	$(RM) $(NAME)

re: fclean all

c: re
	$(RM) $(OBJ)

.PHONY: all clean fclean re
