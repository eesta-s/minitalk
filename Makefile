FILES	:= liba
SERVER	:= server
CLIENT	:= client

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
HEADER	= minitalk

all:	$(SERVER) $(CLIENT) 

server:	$(SERVER:=.c) Makefile $(HEADER:=.h)
			$(CC) $(CFLAGS) $(SERVER:=.c) $(FILES:=.c) -o server

client:	$(CLIENT:=.c) Makefile $(HEADER:=.h)
			$(CC) $(CFLAGS) $(CLIENT:=.c) $(FILES:=.c) -o client

bonus:	
		$(MAKE) -C bonus

clean:
		rm -rf $(SERVER) $(CLIENT)
		$(MAKE) clean -C bonus

fclean: clean
		$(MAKE) fclean -C bonus

re: fclean all

.PHONY: all clean fclean re bonus
