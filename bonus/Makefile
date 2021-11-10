FILES	:= liba
SERVER	:= server
CLIENT	:= client

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
HEADER	= minitalk

all:	$(SERVER) $(CLIENT)

server:	${SERVER:=_bonus.c} Makefile $(HEADER:=_bonus.h)
		$(CC) $(CFLAGS) $(SERVER:=_bonus.c) $(FILES:=_bonus.c) -o server

client:	${CLIENT:=_bonus.c} Makefile $(HEADER:=_bonus.h)
		$(CC) $(CFLAGS) $(CLIENT:=_bonus.c) $(FILES:=_bonus.c) -o client

clean:
		rm -rf $(SERVER) $(CLIENT)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
