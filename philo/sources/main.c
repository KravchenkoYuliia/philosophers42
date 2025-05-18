/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:23:29 by yukravch          #+#    #+#             */
/*   Updated: 2025/05/18 14:26:34 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// return 1 = error
// return 0 = success

int	ft_init_mtx_forks_array(pthread_mutex_t **mtx_forks, size_t nb_of_philos)
{
	size_t	i;

	i = 0;
	*mtx_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb_of_philos);
	if (!*mtx_forks)
	{
		printf("Malloc failed for array of mtx_forks\n");	
		return (ERROR);
	}
	while (i < nb_of_philos)
	{
        	if(pthread_mutex_init(&(*mtx_forks)[i], NULL) != 0)
        	{
                	printf("Failed to initialize mutex for forks\n");
			ft_destroy_initialized_mtx(*mtx_forks, i);
			free(*mtx_forks);
        	        return (ERROR);
        	}
		i++;
	}
        return (SUCCESS);
}


int     ft_init_dinner(t_dinner **dinner, int ac, char **av)
{
        *dinner = (t_dinner *)malloc(sizeof(t_dinner));
        if (!*dinner)
        {
                ft_error("Malloc failed in init dinner");
                return (ERROR);
        }
        (*dinner)->nb_of_philos = ft_atoi(av[1]);
        (*dinner)->time_to_die = ft_atoi(av[2]);
        (*dinner)->time_to_eat = ft_atoi(av[3]);
        (*dinner)->time_to_sleep = ft_atoi(av[4]);
        if (ac == 6)
                (*dinner)->nb_of_times_philo_must_eat = ft_atoi(av[5]);
	if (ft_init_mtx_forks_array(&(*dinner)->mtx_forks, (*dinner)->nb_of_philos) != 0)
	{
		free(*dinner);	
		return (ERROR);
	}
        if(pthread_mutex_init(&(*dinner)->mtx_printf, NULL) != 0)
        {
               	printf("Failed to initialize mutex for printf\n");
		ft_destroy_initialized_mtx((*dinner)->mtx_forks, (*dinner)->nb_of_philos);
		free((*dinner)->mtx_forks);
                return (ERROR);
        }
	return (SUCCESS);
}

int	ft_malloc_array_of_philos(t_dinner *dinner)
{
	dinner->philos = (t_philos **)malloc((sizeof(t_philos *)) * (dinner->nb_of_philos));
	if (!dinner->philos)
	{
		ft_error("Malloc failed for array of philos");
		free(dinner);
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_malloc_every_philo(t_dinner *dinner, int i)
{
	dinner->philos[i] = (t_philos *)malloc(sizeof(t_philos));
	if (!dinner->philos[i])
	{
		ft_error("Malloc failed for every philo");
		free(dinner->philos);
		free(dinner);
		return (ERROR);
	}
	dinner->philos[i]->dinner = dinner;
	return (SUCCESS);
}

void	ft_eating_routine(t_philos *philo)
{
	char	c;

	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(&philo->dinner->mtx_forks[philo->left_fork]);
		pthread_mutex_lock(&philo->dinner->mtx_forks[philo->right_fork]);
		ft_printf_mtx(EAT, philo->dinner, philo->index + 1);
		c = 'l';
	}
	else
	{
		pthread_mutex_lock(&philo->dinner->mtx_forks[philo->right_fork]);
		pthread_mutex_lock(&philo->dinner->mtx_forks[philo->left_fork]);
		ft_printf_mtx(EAT, philo->dinner, philo->index + 1);
		c = 'r';
	}
	usleep(philo->dinner->time_to_eat);
	if (c == 'l')
	{
		pthread_mutex_unlock(&philo->dinner->mtx_forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->dinner->mtx_forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->dinner->mtx_forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->dinner->mtx_forks[philo->right_fork]);
	}
}

void	ft_sleeping_thinking(t_philos *philo)
{
	int		time_to_think;

	ft_printf_mtx(SLEEP, philo->dinner, philo->index + 1);
	usleep(philo->dinner->time_to_sleep);
	ft_printf_mtx(THINK, philo->dinner, philo->index + 1);
	time_to_think = philo->dinner->time_to_eat - philo->dinner->time_to_sleep;
	if (time_to_think > 0)
		usleep(time_to_think);
}

void	*ft_routine(void *arg)
{
	t_philos	*philo;
	philo = (t_philos *)arg;

	pthread_mutex_lock(&philo->dinner->mtx_printf);
	pthread_mutex_unlock(&philo->dinner->mtx_printf);

	if (philo->dinner->nb_of_philos == 1)
	{
		ft_printf_mtx(DIE, philo->dinner, philo->index + 1);
		return (NULL);
	}
	int i  = 0;
	while (i < 3)
	{
		if (philo->index % 2 == 0) //even numbers. Half of philos can eat without problem
		{
			ft_eating_routine(philo);
			ft_sleeping_thinking(philo);
		}
		else
		{
			ft_sleeping_thinking(philo);
			ft_eating_routine(philo);
		}
		i++;
	}
	return (arg);
}

int	ft_create_threads(t_philos *philo)
{
	philo->dead = false;
	if (pthread_create(&philo->thread_id, NULL, (void *)ft_routine, (void *)philo) != 0)
	{
		printf("Failed to create a thread for %zu philo\n", philo->index);
		return (ERROR);
	}
	return (SUCCESS);
}
int	ft_join_threads(t_philos *philo)
{
	if (pthread_join(philo->thread_id, NULL) != 0)
	{
		printf("Failed to join a thread for %zu philo\n", philo->index);
		return (ERROR);
	}
	return (SUCCESS);
}

void	ft_init_index_philo_forks(t_dinner *dinner, size_t i)
{
	dinner->philos[i]->index = i;
	dinner->philos[i]->left_fork = i;
	if (i == dinner->nb_of_philos - 1) //last philo
		dinner->philos[i]->right_fork = 0;
	else
		dinner->philos[i]->right_fork = i + 1;
}

int	ft_create_philos(t_dinner *dinner)
{
	size_t	i;

	i = 0;
	if (ft_malloc_array_of_philos(dinner) == 1)
		return (ERROR);
	while (i < dinner->nb_of_philos)
	{
		if (ft_malloc_every_philo(dinner, i) == 1)
			return (ERROR);
		ft_init_index_philo_forks(dinner, i);
		
		pthread_mutex_lock(&dinner->mtx_printf);
		
		if (ft_create_threads(dinner->philos[i]) == 1)
		{
			ft_stop_created_threads(dinner->philos, i + 1);
			ft_free_array(dinner->philos, dinner->philos[i]->index + 1);
			free(dinner);
			return (ERROR);
		}	

		gettimeofday(&dinner->start_time, NULL);	
		pthread_mutex_unlock(&dinner->mtx_printf);
		
		i++;
	}
	i = 0;
	while (i < dinner->nb_of_philos)
	{
		if (ft_join_threads(dinner->philos[i]) == 1)
		{
			ft_free_array(dinner->philos, dinner->philos[i]->index + 1);
			free(dinner);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_philo(int ac, char **av)
{
	t_dinner	*dinner;

	dinner = NULL;
	if (ft_init_dinner(&dinner, ac, av) == 1) //malloc dinner struct, init argv info, init mutex
		return (ERROR);
	if (ft_create_philos(dinner) == 1)
		return (ERROR);
	ft_destroy_initialized_mtx(dinner->mtx_forks, dinner->nb_of_philos);
	pthread_mutex_destroy(&dinner->mtx_printf);
	free(dinner->mtx_forks);
	ft_free_array(dinner->philos, dinner->nb_of_philos);
	free(dinner);
	return (SUCCESS);
}

int	main(int ac, char** av)
{
	if (ac != 5 && ac != 6)
	{
		ft_error("Write the correct number of arguments, please");
		return (ERROR);
	}
	if (ft_isdigit(ac, av) != 0)
	{
		ft_error("Only positive numbers are accepted as arguments");
		return (ERROR);
	}
	if (ft_MAX(ac, av) != 0)
		return (ERROR);
	if (ft_philo(ac, av) == 1)
		return (ERROR);
	return (SUCCESS);
}
