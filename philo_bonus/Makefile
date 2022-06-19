# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaciri <anaciri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 09:25:54 by anaciri           #+#    #+#              #
#    Updated: 2022/06/18 12:45:23 by anaciri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra
DBUILD = build
FILES_BONUS = 
	
OBJS_BONUS = $(addprefix $(DBUILD)/, $(FILES_BONUS:=.o))

NAME = philo_bonus

bonus : $(NAME)

$(NAME) :$(OBJS_BONUS)
	$(CC) $^ -o $@

$(DBUILD)/%.o:/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I ./inc

clean:
	rm -rf $(OBJ_BONUS) $(DBUILD)
fclean: clean
	rm -f $(NAME)

re: fclean all