SERVER = server
CLIENT = client
BSERVER = server_bonus
BCLIENT = client_bonus

CFLAGS = -Wall -Werror -Wextra -Iincludes/Libft
CC = gcc

SSRCS = server.c
CSRCS = client.c 

SOBJS = $(SSRCS:.c=.o)
COBJS = $(CSRCS:.c=.o)

BSSRCS = server_bonus.c
BCSRCS = client_bonus.c

BSOBJS = $(BSSRCS:.c=.o)
BCOBJS = $(BCSRCS:.c=.o)


LIBFT = includes/Libft
LIBFT_A = $(LIBFT)/libft.a

all : $(SERVER) $(CLIENT)

bonus : $(BSERVER) $(BCLIENT)

$(SERVER) : $(SOBJS) $(LIBFT_A)
		$(CC) $(CFLAGS) -L$(LIBFT) -lft $(SOBJS) -o $(SERVER)

$(CLIENT) : $(COBJS) $(LIBFT_A)
		$(CC) $(CFLAGS) -L$(LIBFT) -lft $(COBJS) -o $(CLIENT)

$(LIBFT_A):
	make -C $(LIBFT)

$(BSERVER) : $(BSOBJS) $(LIBFT_A)
		$(CC) $(CFLAGS) -L$(LIBFT) -lft $(BSOBJS) -o $(BSERVER)

$(BCLIENT) : $(BCOBJS) $(LIBFT_A)
		$(CC) $(CFLAGS) -L$(LIBFT) -lft $(BCOBJS) -o $(BCLIENT)

clean:
	rm -f $(SOBJS) $(COBJS) $(BSOBJS) $(BCOBJS)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(LIBFT_A) $(BSERVER) $(BCLIENT)

re : fclean all

.PHONY : all clean fclean re