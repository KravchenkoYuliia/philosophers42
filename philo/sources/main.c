/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:23:29 by yukravch          #+#    #+#             */
/*   Updated: 2025/05/02 12:46:21 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

// return 1 = error
// return 0 = success

int	ft_init(t_philo **philo, int ac, char **av)
{
	*philo = (t_philo *)malloc(sizeof(t_philo));
	if (!*philo)
	{
		ft_error("Malloc failed in init", NULL);
		return (1);
	}
	(*philo)->nb_of_philo = ft_atoi(av[1]);
	(*philo)->time_to_die = ft_atoi(av[2]);
	(*philo)->time_to_eat = ft_atoi(av[3]);
	(*philo)->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*philo)->nb_of_times_philo_must_eat = ft_atoi(av[5]);
	return (0);
}

void	*ft_routine(void * philo)
{
	t_philo *philo_2 = (t_philo *)philo;
	printf("I'm philo #%zu doing my routine\n", philo_2->count_philo);
	return (NULL);
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
	free(*philo);
	return (0);
}

int	ft_philo(int ac, char **av)
{
	t_philo	*philo = NULL;

	if (ft_init(&philo, ac, av) == 1)
		return (1);
	if (ft_create_philo(&philo) == 1)
		return (1);
	return (0);
}

int	main(int ac, char** av)
{
	if (ac != 5 && ac != 6)
	{
		ft_error("Write the correct number of arguments, please", NULL);
		return (1);
	}
	if (ft_isdigit(ac, av) != 0)
	{
		ft_error("Only positive numbers are accepted as arguments", NULL);
		return (1);
	}
	if (ft_MAX(ac, av) != 0)
		return (1);
	if (ft_philo(ac, av) == 1)
		return (1);
	return (0);
}
