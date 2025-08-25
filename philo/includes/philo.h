/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:25:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/25 18:55:28 by yukravch         ###   ########.fr       */
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

# define SUCCESS 0
# define ERROR -1
# define NOT_SPECIFIED -100
# define SIGNED_LONG_LONG 9223372036854775807

typedef struct s_philo		t_philo;
typedef struct s_general	t_general;

typedef enum e_index {
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
	STOP,
	START
}	t_index;

typedef struct s_time {
	long long		current_time;
	long long		time_left;
	long long		deadline;
}	t_time;

typedef struct s_philo {
	int			index;
	int			right_fork;
	int			left_fork;
	int			has_eaten_times;
	bool		already_counted_not_hungry;
	long long	last_meal_time;
	pthread_t	threads_id;
	t_general	*main;	
}	t_philo;

typedef struct s_general {
	bool			start;
	bool			stop;
	int				nb_of_philo;
	int				not_hungry_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_to_eat;
	long long		start_of_simulation;
	t_philo			*philo;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	food_status_mutex;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	stop_mutex;
}	t_general;
int					ft_strlen(char *str);
int					ft_atoi(const char *nptr);
unsigned long long	ft_atoi_unsigned_longlong(char *str);
char				*ft_strcpy(char *dest, char *src);
int					ft_isdigit(int ac, char **av);
int					ft_limits(char **av);
void				ft_error(char *msg);
int					ft_protected_write(t_philo *philo, int action);
int					ft_init(char **av, t_general **main);
int					ft_time_to_eat(t_philo *philo);
long long			ft_get_current_time(void);
long long			ft_count_time_from_the_start(t_general *main);
long long			ft_min(long long a, long long b);
void				ft_init_last_meal_time(t_general *main);
void				ft_destroy_all_mutex(t_general *main);
int					ft_create_philos(t_general *main);
int					ft_init_mutex(t_general *main);
int					ft_init_start_mutex(t_general *main);
void				*ft_routine(void *data);
bool				ft_not_hungry(t_general *main, t_philo *philo);
int					ft_check_stop_flag(t_general *main);
int					ft_check_start_flag(t_general *main);
int					ft_stop_flag_is_true(t_general *main);
int					ft_start_flag_is_true(t_general *main);
int					ft_think(t_philo *philo);
int					ft_eat(t_philo *philo);
int					ft_sleep(t_philo *philo);
int					ft_monitor_checking(t_general *main, long long current_time, int i);

#endif
