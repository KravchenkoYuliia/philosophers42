# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yukravch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 14:29:53 by yukravch          #+#    #+#              #
#    Updated: 2025/05/01 09:55:34 by yukravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Werror -Wextra -g3 -I $(INC_DIR)

all: $(NAME)
	@echo "./\___/\."
	@echo "         "
	@echo "( >^ -^<)"
	@echo "         "
	@echo "/ ⊃ 🌸"
	@echo "✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨"


SRC_DIR = sources
OBJ_DIR = objects
INC_DIR = includes


FILES = main.c
SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)
	
$(info Program must take the following arguments)
$(info 1. number_of_philosophers)
$(info 2. time_to_die)
$(info 3. time_to_eat)
$(info 4. time_to_sleep)
$(info 5. [number_of_times_each_philosopher_must_eat])
$(info                                               )


clean: 
	rm -rf $(OBJ_DIR)
fclean: clean 
	rm -f $(NAME)
re: fclean all







