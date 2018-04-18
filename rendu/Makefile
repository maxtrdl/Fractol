# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/13 09:15:16 by mtrudel           #+#    #+#              #
#    Updated: 2017/10/09 12:07:57 by mtrudel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# **************************************************************************** #

# COMPILATION
CC = clang
CCFLAGS = -Wall -Werror -Wextra
FRMW = -framework AppKit -framework OpenGL

# DIRECTORIES
D_SRC = src
D_INC = inc
D_OBJ = obj
D_LIBFT = libft
D_MLX = minilibx

#LIBRARIES
LDL = $(addprefix -L, $(D_LIBFT))
LDM = $(addprefix -L, $(D_MLX))

# SOURCES
F_SRC =\
	   main.c\
	   affichage.c\
	   fractals.c\
	   init_frac.c\
	   consigne.c\
	   key_function.c\
	   color.c\
	   mouse.c

# ***************************************************************************** #

# SPECIAL CHARS
LOG_CLEAR               = \033[2K
LOG_UP                  = \033[A
LOG_NOCOLOR             = \033[0m
LOG_BLACK               = \033[1;30m
LOG_RED                 = \033[1;31m
LOG_GREEN               = \033[1;32m
LOG_YELLOW              = \033[1;33m
LOG_BLUE                = \033[1;34m
LOG_VIOLET              = \033[1;35m
LOG_CYAN                = \033[1;36m
LOG_WHITE               = \033[1;37m

# ****************************************************************************** #

.PHONY: make all fclean re

F_OBJ = $(addsuffix .o, $(basename $(F_SRC)))

DF_SRC = $(addprefix $(D_SRC)/, $(F_SRC))
DF_OBJ = $(addprefix $(D_OBJ)/, $(F_OBJ))

RM = /bin/rm -rf

all: $(NAME)

$(D_OBJ)/%.o: $(D_SRC)/%.c $(D_INC)
	@mkdir -p $(D_OBJ) 2> /dev/null || true
	@echo "$(LOG_CYAN)$(NAME)... $(LOG_NOCOLOR)$<"
	@$(CC) $(CCFLAGS) -I $(D_INC) -o $@ -c $<
$(NAME): $(DF_OBJ)
	@make -C $(D_LIBFT)
	@make -C $(D_MLX)
	@echo "$(LOG_CYAN)$(NAME)... assembling...$(LOG_NOCOLOR)"
	@$(CC) $(LDL) -lft $(LDM) -lmlx $^ -o $@ $(FRMW)
	@echo "$(LOG_GREEN)$(NAME)... compiled ✓$(LOG_NOCOLOR)"
clean:
	@echo "$(LOG_RED)Deleting Fractol's objs ✖$(LOG_NOCOLOR)"
	@$(RM) $(D_OBJ)
fclean: clean
	@echo "$(LOG_RED)Deleting Fractol ✖$(LOG_NOCOLOR)"
	@$(RM) $(NAME)
re: fclean all
