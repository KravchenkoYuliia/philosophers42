/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:25:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/05/06 16:33:20 by yukravch         ###   ########.fr       */
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

typedef struct	s_philos t_philos;

typedef struct s_dinner{
	size_t		nb_of_philos;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		nb_of_times_philo_must_eat;
	pthread_mutex_t	mtx_init;
	t_philos		**philos;
} t_dinner;

typedef struct	s_philos{
	size_t		index;
	bool		stop_threads;
	pthread_t	thread_id;
	size_t		nb_meals;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
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

# endif
