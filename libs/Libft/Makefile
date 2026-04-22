# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 16:13:12 by shunwata          #+#    #+#              #
#    Updated: 2026/02/09 22:22:04 by shunwata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(FT_PRINTF_DIR) -I $(GNL_DIR) -I $(ADDITIONAL_DIR)

SRC_DIR = srcs
INC_DIR = includes

FT_PRINTF_DIR = $(SRC_DIR)/ft_printf
GNL_DIR = $(SRC_DIR)/get_next_line
ADDITIONAL_DIR = $(SRC_DIR)/additional

SRCS = $(addprefix $(SRC_DIR)/, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	   ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	   ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c)
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = $(addprefix $(SRC_DIR)/, ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			 ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

FT_PRINTF_SRCS = $(addprefix $(FT_PRINTF_DIR)/, ft_printf.c ft_printf_utils.c)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

GNL_SRCS = $(addprefix $(GNL_DIR)/, get_next_line.c)
GNL_OBJS = $(GNL_SRCS:.c=.o)

ADDITIONAL_SRCS = $(addprefix $(ADDITIONAL_DIR)/, free_2d_array.c ft_atol.c ft_replace.c ft_strcmp.c ft_strndup.c ft_strnlen.c search_get_env.c)
ADDITIONAL_OBJS = $(ADDITIONAL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(BONUS_OBJS) $(ADDITIONAL_OBJS)
	ar rcs $(NAME) $(OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(BONUS_OBJS) $(ADDITIONAL_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(BONUS_OBJS) $(ADDITIONAL_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
