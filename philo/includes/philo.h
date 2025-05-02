/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:25:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/05/02 11:42:42 by yukravch         ###   ########.fr       */
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

typedef struct s_philo{
	size_t		count_philo;
	size_t		nb_of_philo;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		nb_of_times_philo_must_eat;
	pthread_t	philo;
} t_philo;

size_t		ft_atoi(char *str);
int	ft_philo(int ac, char **av);
int	ft_init(t_philo **philo, int ac, char **av);
int	ft_philo(int ac, char **av);
void	ft_error(char *msg, t_philo **philo);
int	ft_strlen(char *str);
int	ft_isdigit(int ac, char **av);
int	ft_MAX(int ac, char **av);

# endif
