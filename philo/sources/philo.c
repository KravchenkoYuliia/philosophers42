/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:25:06 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/20 18:32:00 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	ft_waiting_for_threads(t_general *main)
{
	int	i;

	i = 0;
	while (i < main->nb_of_philo)
	{
		if (pthread_join(main->philo[i].threads_id, NULL) != SUCCESS)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	ft_create_philos(t_general *main)
{
	int	i;

	i = 0;
	main->philo = calloc(sizeof(t_philo), main->nb_of_philo);
	if (!main->philo)
		return (ERROR);
	while (i < main->nb_of_philo)
	{
		main->philo[i].main = main;
		main->philo[i].index = i;
		if (pthread_create(&main->philo[i].threads_id,
					NULL, ft_routine, &main->philo[i]) != SUCCESS)
			return (ERROR);
		i++;
	}
	if (ft_waiting_for_threads(main) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	ft_init(char **av, t_general **main)
{
	*main = calloc(sizeof(t_general), 1);
	if (!main)
		return (ERROR);
	(*main)->stop = false;
	(*main)->nb_of_philo = ft_atoi(av[1]);
	(*main)->time_to_die = ft_atoi_unsigned_longlong(av[2]);
	(*main)->time_to_eat = ft_atoi_unsigned_longlong(av[3]);
	(*main)->time_to_sleep = ft_atoi_unsigned_longlong(av[4]);
	if (av[5])
		(*main)->must_to_eat = ft_atoi(av[5]);
	if (ft_create_philos(*main) == ERROR)
	{
		free(*main);
		return (ERROR);
	}
	if (ft_init_mutex(*main) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
