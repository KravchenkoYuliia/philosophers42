# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 14:29:53 by yukravch          #+#    #+#              #
#    Updated: 2025/08/26 19:24:56 by yukravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo


CFLAGS = -Wall -Werror -Wextra -g3 -I $(INC_DIR)
# CFLAGS = -Wall -Werror -Wextra -fsanitize=thread -g -I $(INC_DIR)
#flags for a big number of threads that is impossible for valgrind
#valgrind --tool=helgrind
#valgrind --tool=drd

all: $(NAME)
	@echo "                      "
	@echo "✨✨✨✨✨✨✨✨✨✨✨"
	@echo "✨                  ✨"
	@echo "✨    ./\___/\.     ✨"
	@echo "✨                  ✨"
	@echo "✨    ( >^ -^<)     ✨"
	@echo "✨                  ✨"
	@echo "✨    / ⊃ 🌸/       ✨"
	@echo "✨                  ✨"
	@echo "✨✨✨✨✨✨✨✨✨✨✨"

SRC_DIR = sources
OBJ_DIR = objects
INC_DIR = includes


FILES = main.c start.c basic_ft.c utils.c args_checking.c write.c time.c philo.c mutex.c routine.c \
	eat.c eat_more.c think_sleep_die.c
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
$(info 5. [number_of_times_each_philosopher_must_eat] - optional argument)
$(info                                                              )


clean: 
	rm -rf $(OBJ_DIR)
fclean: clean 
	rm -f $(NAME)
re: fclean all
