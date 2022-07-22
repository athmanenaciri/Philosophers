# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaciri <anaciri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 15:12:36 by anaciri           #+#    #+#              #
#    Updated: 2022/07/21 17:00:43 by iait-bel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g
DBUILD = build
FILES = main ft_atoi generate_threads my_time between_times ft_printf is_died ft_usleep
	
OBJS = $(addprefix $(DBUILD)/, $(FILES:=.o))

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@

$(DBUILD)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I ./inc

clean:
	rm -rf $(OBJ) $(DBUILD)
fclean: clean
	rm -f $(NAME) 
re: fclean all
