# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaylor <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 09:35:25 by jaylor            #+#    #+#              #
#    Updated: 2017/03/24 14:51:55 by jaylor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = lem-in
HEADERS = includes

CFLAGS += -g
CFLAGS += -I$(HEADERS)

FILESO =	parse2.o \
			parse.o \
			parse3.o \
			main.o \
			initialize.o \
			utilities.o \
			make_map.o \
			solver.o \

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(FILESO) $(LIBFT)
	gcc -o $(NAME) $^ $(CFLAGS)

%.o: srcs/%.c
	gcc -o $@ -c $< $(CFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(FILESO) 
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
