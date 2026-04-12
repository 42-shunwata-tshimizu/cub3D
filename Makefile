# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/06 22:14:58 by tshimizu          #+#    #+#              #
#    Updated: 2026/04/06 22:15:07 by tshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ===============================
#             Color
# ===============================
GREEN   = \033[0;32m
RED     = \033[0;31m
YELLOW  = \033[0;33m
RESET   = \033[0m

# ========================
#       CONFIGURATION
# ========================
NAME		= cub3D

CC			= cc
SRC_DIR		= srcs
OBJ_DIR		= objs
INC_DIR		= includes

LIBFT_DIR	= libs/libft
LIBFT_A	= $(LIBFT_DIR)/libft.a

GNL_DIR = libs/get_next_line/srcs
GNL_SRC = get_next_line.c get_next_line_utils.c
GNL_SRCS = $(addprefix $(GNL_DIR)/, $(GNL_SRC))
GNL_OBJS = $(GNL_SRCS:.c=.o)

MLX_DIR		= libs/minilibx-linux
MLX_LIB	= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11

INCFLAG		= -I$(INC_DIR) -I$(LIBFT_DIR)/includes -I$(MLX_DIR) -I$(GNL_DIR)
CFLAGS		= -Wall -Wextra -Werror $(INCFLAG)

RM			= rm -f


# ===============================
#               SRC
# ===============================

SRC_VALIDATION   = validation/validate_argv.c\

SRC_READ   = read/read_file.c\

SRC_UTILS   = utils/free_utils.c\

SRC_INPUT   = \

SRC_PARSE   = \

SRC_ENGINE    = \

SRC_RENDER = \

SRC_MAIN    = main.c

ALL_SRC = \
    $(SRC_VALIDATION) \
    $(SRC_READ) \
    $(SRC_UTILS) \
    $(SRC_INPUT) \
    $(SRC_PARSE) \
    $(SRC_ENGINE) \
    $(SRC_RENDER) \
    $(SRC_MAIN)

SRCS        = $(addprefix $(SRC_DIR)/, $(ALL_SRC))
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ========================
#        TARGETS
# ========================
all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS) $(MLX_LIB) $(GNL_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBFT_A) $(MLX_FLAGS) -o $@
	@echo "$(GREEN)✅ Compiled: $(NAME)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)🔧 Compiled: $<$(RESET)"

# ========================
#   LIBRARY BUILD TARGET
# ========================
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) bonus
	@echo "$(YELLOW)🔧 Compiled LIBFT$(RESET)"

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)
	@echo "$(YELLOW)🔧 Compiled MLX$(RESET)"

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)🔧 Compiled GNL: $<$(RESET)"

# ===============================
#       SANITIZER / DEBUG
# ===============================
asan: CFLAGS += -g -fsanitize=address
asan: re
	@echo "$(GREEN)🚀 AddressSanitizer Enabled$(RESET)"
	./$(NAME)

debug: CFLAGS += -g -DDEBUG
debug: re
	@echo "$(GREEN)🚀 Debug build ready$(RESET)"

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=readline.supp ./$(NAME)


# ========================
#       CLEANING
# ========================
clean:
	@$(RM) $(OBJS) $(GNL_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "🧹 Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "🧼 Cleaned executable.$(RESET)"

re: fclean all

# ========================
#        PHONY
# ========================
.PHONY: all clean fclean re mlx
