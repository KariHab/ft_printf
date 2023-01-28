
NAME = libft.a

# le compilateur et les flags pour compiler
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Sources are all .c files
SRCS =  ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

# Pour obtenir les .o de chaque .c 
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

# Pour supprimer les .o qu' on a genere
clean:
	$(RM) $(OBJS)

# on clean tout donc .o et les exe
fclean: clean
	$(RM) $(NAME)

# pour remake qui servira pour debbuger si besoin 
re: fclean all