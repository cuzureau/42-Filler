# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 15:57:06 by cuzureau          #+#    #+#              #
#    Updated: 2019/01/02 16:47:34 by cuzureau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
TEST= ko

ifeq ($(TEST),ko)
CFLAGS+= -Wall -Wextra -Werror
else
CFLAGS+=	-Wall -Wextra -Werror -g -fsanitize=address	\
 			-fno-omit-frame-pointer		\
			-fsanitize-address-use-after-scope \

endif

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

INC_PATH = inc/
LFT_PATH = lib/
OBJ_PATH = obj/
SRC_PATH = src/

NAME= cuzureau.filler
INC_NAME= filler.h
OBJ_NAME= $(SRC_NAME:.c=.o)
SRC_NAME= main.c strategy.c get.c tools.c distance.c

INC= $(addprefix $(INC_PATH), $(INC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

all:	$(NAME)

$(NAME): $(OBJ) $(INC)
		@echo "$(OKC)filler$(NOC)	+ obj	$(OKC)[OK]$(NOC)"
		@make -C $(LFT_PATH) --no-print-directory
		@$(CC) $(CFLAGS) -o $@ $(OBJ) -L $(LFT_PATH) -lft
		@echo "$(OKC)filler$(NOC)	+ exe	$(OKC)[OK]$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
		@make -C $(LFT_PATH) clean --no-print-directory
		@rm -rf $(OBJ_PATH)
		@echo "$(OKC)filler$(NOC)	- obj	$(OKC)[OK]$(NOC)"

fclean: clean
		@make -C $(LFT_PATH) fclean --no-print-directory
		@rm -rf $(NAME)
		@echo "$(OKC)filler$(NOC)	- exe	$(OKC)[OK]$(NOC)"

re: fclean all

norme:
	@norminette $(SRC_PATH) $(INC_PATH)

.PHONY: all clean fclean re norme
