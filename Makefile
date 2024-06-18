NAME = minishell
COMPIL = cc
FLAGS = -Wall -Werror -Wextra 
PINK = \033[1;35m
BLUE = \033[1;36m
NC = \033[0m

HEADER_F = headers/minishell.h \
			headers/built_in.h \

BUILTIN_SRCS = ft_echo.c \
			ft_env.c \
			ft_pwd.c \
			ft_exit.c \
			ft_exit_utils.c \

MANDATORY_SRCS = main.c \

# Magic with srcs and objs #

PMANDATORY = $(addprefix srcs/, $(MANDATORY_SRCS))
PBUILTIN = $(addprefix srcs/built_in/, $(BUILTIN_SRCS))
B_OBJS = $(PBUILTIN:srcs/%.c=objs/%.o)
M_OBJS = $(PMANDATORY:srcs/%.c=objs/%.o)

LIBFT = libft/libft.a

all : $(NAME) 

$(LIBFT): 
	@make -sC libft 
	@make bonus -sC libft 
	@echo  "$(PINK)\n     LIBFT COMPILED \n$(NC)"

	
objs/%.o: srcs/%.c $(HEADER_F)
	@mkdir -p objs/built_in
	@$(COMPIL) $(FLAGS) -c $< -o $@

$(NAME) : $(M_OBJS) $(B_OBJS) $(HEADER_F) $(LIBFT)
	@$(COMPIL) $(FLAGS) -o $@ $(M_OBJS) $(B_OBJS) $(LIBFT)
	@echo  "$(BLUE)\n    MINISHELL COMPILED \n$(NC)"


clean :
	@rm -rf objs/*
	@make -sC libft clean
	@echo  "$(PINK) \n     LIBFT CLEANED  \n$(NC)"
	@echo  "$(BLUE) \n     MINISHELL CLEANED \n$(NC)"

fclean : clean
	@rm -f $(NAME) 
	@make -sC libft fclean

re : fclean all

.PHONY : all clean fclean re bonus