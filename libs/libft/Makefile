# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprovoos <bprovoos@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/19 08:27:15 by bprovoos      #+#    #+#                  #
#    Updated: 2022/11/16 17:29:36 by bprovoos      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Change this data depends on your files you have

NAME		= libft.a
HEADER		= libft.h
SRCS		= ft_isalpha.o $\
			  ft_isspace.o $\
			  ft_memccpy.o $\
			  ft_memset.o $\
			  ft_split.o $\
			  ft_strlcpy.o $\
			  ft_strrchr.o $\
			  ft_atoi.o $\
			  ft_isascii.o $\
			  ft_memchr.o $\
			  ft_putchar_fd.o $\
			  ft_strchr.o $\
			  ft_strlen.o $\
			  ft_strtrim.o $\
			  ft_bzero.o $\
			  ft_isdigit.o $\
			  ft_memcmp.o $\
			  ft_putendl_fd.o $\
			  ft_strdup.o $\
			  ft_strmapi.o $\
			  ft_substr.o $\
			  ft_calloc.o $\
			  ft_isprint.o $\
			  ft_memcpy.o $\
			  ft_putnbr_fd.o $\
			  ft_strjoin.o $\
			  ft_strncmp.o $\
			  ft_tolower.o $\
			  ft_isalnum.o $\
			  ft_itoa.o $\
			  ft_memmove.o $\
			  ft_putstr_fd.o $\
			  ft_strlcat.o $\
			  ft_strnstr.o $\
			  ft_toupper.o $\
			  ft_strstr.o $\
			  ft_strrev.o $\
			  ft_islower.o $\
			  ft_isupper.o $\
			  ft_strtolower.o $\
			  ft_strtoupper.o $\
			  ft_strlendump.o $\
			  ft_realloc.o
BONUSSRCS	= ft_lstnew.o $\
			  ft_lstadd_front.o $\
			  ft_lstsize.o $\
			  ft_lstiter.o $\
			  ft_lstlast.o $\
			  ft_lstclear.o $\
			  ft_lstadd_back.o $\
			  ft_lstdelone.o $\
			  ft_lstmap.o $\
			  ft_itoa_base.o

# The code below does not need to be changed

CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
RM 			= rm -rf
SRCOBJ		= $(SRCS:.c=.o)
BONUSOBJ	= $(BONUSSRCS:.c=.o)

ifdef BONUS
OBJ = $(SRCOBJ) $(BONUSOBJ)
else
OBJ = $(SRCOBJ)
endif

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o : %.c $(HEADER)
	$(CC) -c $(FLAGS) -o $@ $<

bonus:
	$(MAKE) BONUS=1

clean:
	${RM} $(SRCOBJ) $(BONUSOBJ)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean bonus fclean re
