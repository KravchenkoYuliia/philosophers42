/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:25:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/20 14:39:19 by yukravch         ###   ########.fr       */
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

#define	SIGNED_LONG_LONG 9223372036854775807

typedef struct s_philo t_philo;
typedef	struct s_general t_general;

typedef enum e_index {
	SUCCESS,
	ERROR,
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_index;

typedef struct s_philo {

	int		index;
	pthread_t	threads_id;
	t_general	*main;	

} t_philo;

typedef	struct s_general {

	int		nb_of_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int		must_to_eat;
	t_philo		*philo;

} t_general ;

/////////////libft

int			ft_strlen(char *str);
int			ft_atoi(const char *nptr);
unsigned long long	ft_atoi_unsigned_longlong(char *str);
//////////////

int	ft_isdigit(int ac, char **av);
int	ft_limits(char **av);

///////////////errors

void	ft_error(char *msg);

/////////////////
int	ft_init(char **av, t_general **main);
int	ft_init_philos(t_general *main);

////////////////

void	*ft_routine(void *data);

# endif
