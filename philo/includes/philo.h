/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:25:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/05/18 14:24:58 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

# define ERROR 1
# define SUCCESS 0

typedef struct	s_philos t_philos;

typedef enum e_index {
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_index;

typedef struct s_dinner{
	
	size_t		nb_of_philos;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		nb_of_times_philo_must_eat;
	pthread_mutex_t	*mtx_forks;
	pthread_mutex_t	mtx_printf;
	pthread_mutex_t	mtx_timeofday;
	t_philos	**philos;
	struct timeval start_time;
} t_dinner;

typedef struct	s_philos{
	
	size_t		index;
	bool		dead;
	pthread_t	thread_id;
	size_t		nb_meals;
	size_t		left_fork;
	size_t		right_fork;
	t_dinner	*dinner;

} t_philos;

size_t		ft_atoi(char *str);
int	ft_philo(int ac, char **av);
int     ft_init_dinner(t_dinner **dinner, int ac, char **av);
void	ft_error(char *msg);
int	ft_strlen(char *str);
int	ft_isdigit(int ac, char **av);
int	ft_MAX(int ac, char **av);
void    ft_free_array(t_philos** philos, size_t nb_of_philos);
void    ft_stop_created_threads(t_philos **philos, size_t ind_of_failed_philo);
void    ft_destroy_initialized_mtx(pthread_mutex_t *mtx_forks, size_t end);
void    ft_printf_mtx(t_index msg_index, t_dinner *dinner, size_t index);
size_t  ft_get_time_to_print(suseconds_t start, suseconds_t end);

# endif
