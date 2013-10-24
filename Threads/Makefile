## ┌───────────────────────────────────────────────────────────────────────────┐
## │                                MAKEFILE                                   │
## └───────────────────────────────────────────────────────────────────────────┘



NAME	     ?=	libThread.so


SRCS =	      	ThreadCond.cpp	\
		ThreadMutex.cpp	\

F.C	     +=	-W -Wall -Werror -fPIC
F.I	     +=	-I $(DIR.H)
F.L	     += -lpthread -shared
F.D	     += -DNDEBUG


all:		start $(NAME)

$(NAME):	compile

clean:		remove_objects

fclean:		clean remove_name

re:		fclean all























































include .libmake
