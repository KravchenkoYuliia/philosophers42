/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:23:29 by yukravch          #+#    #+#             */
/*   Updated: 2025/05/06 17:27:42 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

// return 1 = error
// return 0 = success

/*
void	*ft_routine(void * philo)
{
	t_philo *philo_2 = (t_philo *)philo;
	printf("I'm philo #%zu doing my routine\n", philo_2->count_philo);
	if (pthread_mutex_lock(philo_2->lock) == 0)
		printf("Philosopher #%zu is eating\n", philo_2->count_philo);
	
	pthread_mutex_unlock(philo_2->lock);
	return (NULL);

	 tu as en parametre le DINER tu dois proteger ton id philo 
	 mtx_lock -> i = id_philo -> mtx_unlock 

}

int	ft_create_philo(t_philo **philo)
{

	(*philo)->count_philo = 1;
	while ((*philo)->count_philo <= (*philo)->nb_of_philo) 
	{
		if (pthread_create(&(*philo)->philo, NULL, ft_routine, (void *)*philo) != 0)
		{
			ft_error("Failed to create thread", philo);
			return (1);
		}
		if (pthread_join((*philo)->philo, NULL) != 0)
		{
			ft_error("Failed to join thread", philo);
			return (1);
		}
		write(1, "Good\n", 5);
		(*philo)->count_philo++;
	}
	return (0);
}

int	ft_create_diner(t_diner *diner)
{
	int	i;

	i = 0;
	while (i < diner->nb_of_philo)
		pthread_create(&diner, NULL, ft_routine, (void *)diner->philos[i++]);
	i = 0;
	while (i < diner->nb_of_philo)
		pthread_join(diner->philos[i++], NULL);
	return (0);
	 free des mutex + ce qu'il y a free 
}
*/

int     ft_init_dinner(t_dinner **dinner, int ac, char **av)
{
        *dinner = (t_dinner *)malloc(sizeof(t_dinner));
        if (!*dinner)
        {
                ft_error("Malloc failed in init dinner");
                return (1);
        }
        (*dinner)->nb_of_philos = ft_atoi(av[1]);
        (*dinner)->time_to_die = ft_atoi(av[2]);
        (*dinner)->time_to_eat = ft_atoi(av[3]);
        (*dinner)->time_to_sleep = ft_atoi(av[4]);
        if (ac == 6)
                (*dinner)->nb_of_times_philo_must_eat = ft_atoi(av[5]);
        if(pthread_mutex_init(&(*dinner)->mtx_init, NULL) != 0)
        {
                ft_error("Failed to initialize mutex");
		free(*dinner);
                return (1);
        }
        return (0);
}

int	ft_malloc_array_of_philos(t_dinner **dinner)
{
	(*dinner)->philos = (t_philos **)malloc((sizeof(t_philos *)) * ((*dinner)->nb_of_philos));
	if (!(*dinner)->philos)
	{
		ft_error("Malloc failed for array of philos");
		free(*dinner);
		return (1);
	}
	return (0);
}

int	ft_malloc_every_philo(t_dinner **dinner, int i)
{
	(*dinner)->philos[i] = (t_philos *)malloc(sizeof(t_philos));
	if (!(*dinner)->philos[i])
	{
		ft_error("Malloc failed for every philo");
		free((*dinner)->philos);
		free(*dinner);
		return (1);
	}
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philos *philo;

	philo = (t_philos *)arg;
	printf("Hello from philosopher #%zu\n", philo->index);
	return (arg);
}

int	ft_create_threads(t_philos *philo)
{
	philo->stop_threads = false;
	if (pthread_create(&philo->thread_id, NULL, (void *)ft_routine, (void *)philo) != 0)
	{
		printf("Failed to create a thread for %zu philo\n", philo->index);
		philo->stop_threads = true;
		return (1);
	}
	return (0);
}
int	ft_join_threads(t_philos *philo)
{
	if (pthread_join(philo->thread_id, NULL) != 0)
	{
		printf("Failed to join a thread for %zu philo\n", philo->index);
		return (1);
	}
	return (0);
}

int	ft_create_philos(t_dinner **dinner)
{
	size_t	i;

	i = 0;
	if (ft_malloc_array_of_philos(dinner) == 1)
		return (1);
	while (i < (*dinner)->nb_of_philos)
	{
		if (ft_malloc_every_philo(dinner, i) == 1)
			return (1);
		(*dinner)->philos[i]->index = i;
		if (ft_create_threads((*dinner)->philos[i]) == 1)
		{
			ft_stop_created_threads((*dinner)->philos, i + 1);
			ft_free_array((*dinner)->philos, (*dinner)->philos[i]->index + 1);
			free(*dinner);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < (*dinner)->nb_of_philos)
	{
		if (ft_join_threads((*dinner)->philos[i]) == 1)
		{
			ft_free_array((*dinner)->philos, (*dinner)->philos[i]->index + 1);
			free(*dinner);
			return (1);
		}
		i++;
	}
	return (0);
}
int	ft_philo(int ac, char **av)
{
	t_dinner	*dinner;

	dinner = NULL;
	if (ft_init_dinner(&dinner, ac, av) == 1) //malloc dinner struct, init argv info, init mutex
		return (1);
	if (ft_create_philos(&dinner) == 1)
		return (1);
	ft_free_array(dinner->philos, dinner->nb_of_philos);
	pthread_mutex_destroy(&dinner->mtx_init);
	free(dinner);
	return (0);
}

int	main(int ac, char** av)
{
	if (ac != 5 && ac != 6)
	{
		ft_error("Write the correct number of arguments, please");
		return (1);
	}
	if (ft_isdigit(ac, av) != 0)
	{
		ft_error("Only positive numbers are accepted as arguments");
		return (1);
	}
	if (ft_MAX(ac, av) != 0)
		return (1);
	if (ft_philo(ac, av) == 1)
		return (1);
	return (0);
}
