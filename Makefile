# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 21:10:35 by cbagdon           #+#    #+#              #
#    Updated: 2019/05/13 22:02:06 by cbagdon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cribby

SRC = main.c \

TERMINAL = terminal_mode.c

UTILS = cribby_error.c \
		ft_getch.c \
		ft_clear_screen.c \
		cursor.c

DRAW = draw_rows.c \
		refresh.c

WINDOW = window_update.c

INPUT = cursor_movement.c

FILE = row.c

INCLUDES = includes/ -I libft/includes

OBJECTS = $(patsubst %.c,%.o,$(SRC))
OBJECTS += $(patsubst %.c,%.o, $(TERMINAL))
OBJECTS += $(patsubst %.c,%.o, $(UTILS))
OBJECTS += $(patsubst %.c,%.o, $(WINDOW))
OBJECTS += $(patsubst %.c,%.o, $(DRAW))
OBJECTS += $(patsubst %.c,%.o, $(INPUT))
OBJECTS += $(patsubst %.c,%.o, $(FILE))

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	@gcc $(CCFLAGS) -I $(INCLUDES) -c $(addprefix src/terminal/,$(TERMINAL))
	@gcc $(CCFLAGS) -I $(INCLUDES) -c $(addprefix src/utils/,$(UTILS))
	@gcc $(CCFLAGS) -I $(INCLUDES) -c $(addprefix src/window/,$(WINDOW))
	@gcc $(CCFLAGS) -I $(INCLUDES) -c $(addprefix src/draw/,$(DRAW))
	@gcc $(CCFLAGS) -I $(INCLUDES) -c $(addprefix src/input/,$(INPUT))
	@gcc $(CCFLAGS) -I $(INCLUDES) -c $(addprefix src/file/,$(FILE))
	@gcc $(CCFLAGS) -I $(INCLUDES) -c $(addprefix src/,$(SRC))
	@mkdir build
	@mv $(OBJECTS) build
	@gcc $(CCFLAGS) -o $(NAME) $(addprefix build/,$(OBJECTS)) -L ./libft -lft -ltermcap

clean:
	make -C libft clean
	@rm -rf build

fclean: clean
	make -C libft fclean
	@rm -rf $(NAME)

re: fclean all
