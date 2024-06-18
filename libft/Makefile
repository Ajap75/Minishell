EXECUTABLE = libft.a

FILES = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c	\
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \


SRCBONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

PRINTF_SRC = printf/ft_printf.c \
			printf/ft_put_hexa.c \
			printf/ft_put_unsigned_nbr.c \
			printf/ft_putchar.c \
			printf/ft_putnbr.c \
			printf/ft_putpointeur.c \
			printf/ft_putstr.c \


ARRC = ar rc

RANLIB = ranlib 

COMPIL = cc

FLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj

HEADER_F = libft.h

O = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

B = $(SRCBONUS:.c=.o)

PRINTF_O = $(PRINTF_SRC:.c=.o)

$(OBJ_DIR)/%.o: %.c $(HEADER_F)
	@mkdir -p $(OBJ_DIR)
	$(COMPIL) $(FLAGS) -c $< -o $@

$(EXECUTABLE) : $(O) 
	$(ARRC)  $(EXECUTABLE) $(O) 
	$(RANLIB) $(EXECUTABLE)

all : $(EXECUTABLE)

bonus : $(B)
		$(ARRC) $(EXECUTABLE) $(B)
		$(RANLIB) $(EXECUTABLE)
clean :
	rm -f libft.so 
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(EXECUTABLE)

re : fclean all

.PHONY : all clean fclean re