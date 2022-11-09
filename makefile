NAME = minishell

FLAGS = -Wall -Werror -Wextra -MMD -g -fsanitize=address
SRC_DIR = src
OBJ_DIR = obj
MAKE_FILE = makefile
INC_DIR = includes
LIBFT_DIR = ./libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

READLINE_LIB = -lreadline

EXECUTE_FI	=	executor.c \
				file.c \
				paths.c \
				exit.c \
				errors.c \
				redirect.c \
				builtin.c \
				cd.c
#export.c
				

LEXER_FILES =	lexer.c \
				handle_quotes.c \
				handle_variables.c

MAIN_FILES =	main.c \
				line_input.c \
				argv_input.c

PARSER_FILES =	parser.c

SRC_FILES =		$(addprefix main/, $(MAIN_FILES)) \
				$(addprefix executor/, $(EXECUTE_FI)) \
				$(addprefix lexer/, $(LEXER_FILES)) \
				$(addprefix parser/, $(PARSER_FILES))

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC:.c=.o))

INC = -I $(INC_DIR)

DEP = $(OBJ:%.o=%.d)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MAKE_FILE)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(READLINE_LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INC) $(READLINE_INC) -c -o $@ $<

-include $(DEP)

$(LIBFT):
	@$(MAKE) bonus -C $(LIBFT_DIR)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(OBJDIR)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
