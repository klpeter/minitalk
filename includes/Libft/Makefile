Library = libft

files = ft_atoi \
		ft_atol \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_split \
		ft_strchr \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper \
		ft_printf \
		ft_putnumbers \
		ft_putcharl \
		ft_putstrl \
		get_next_line \
		get_next_line_utils \


bonusfiles = ft_lstnew \
			ft_lstadd_front \
			ft_lstsize \
			ft_lstlast \
			ft_lstadd_back \
			ft_lstdelone \
			ft_lstclear \
			ft_lstiter \
			ft_lstmap \

Compiler = cc

CmpFlags = -Wall -Wextra -Werror

OUTN = $(Library).a

CFILES = $(files:%=%.c)

CFILESB = $(bonusfiles:%=%.c)

OFILES = $(files:%=%.o)

OFILESB = $(bonusfiles:%=%.o)

NAME = libft.a

all: $(NAME) clean

$(NAME): $(OFILES)
		$(Compiler) $(CmpFlags) -c $(CFILES)
		ar -rc $(OUTN) $(OFILES)

bonus: $(OFILESB)
		$(Compiler) $(CmpFlags) -c $(CFILESB)
		ar -rc $(OUTN) $(OFILESB)

clean:
		rm -f $(OFILES)
		rm -f $(OFILESB)

fclean: clean
		rm -f $(NAME)

re: fclean all
	
.PHONY: all, clean, fclean, re