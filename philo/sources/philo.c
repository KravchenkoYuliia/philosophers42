/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:25:06 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/26 19:02:05 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_monitor(t_general *main)
{
	int			i;
	long long	current_time;

	while (1)
	{
		i = 0;
		if (usleep(1000) != SUCCESS)
			return (ERROR);
		current_time = ft_get_current_time();
		if (current_time == ERROR)
			return (ERROR);
		while (i < main->nb_of_philo)
		{
			if (ft_check_stop_flag(main) == STOP)
				return (SUCCESS);
			if (ft_monitor_checking(main, current_time, i))
				return (ERROR);
			i++;
		}
	}
	return (SUCCESS);
}

int	ft_waiting_for_threads(t_general *main)
{
	int	i;

	if (usleep(10000) != SUCCESS)
		return (ERROR);
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
	if (ft_start_of_simulation(main) == ERROR)
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
	(*main)->not_hungry_philo = 0;
	(*main)->time_to_die = ft_atoi_unsigned_longlong(av[2]);
	(*main)->time_to_eat = ft_atoi_unsigned_longlong(av[3]);
	(*main)->time_to_sleep = ft_atoi_unsigned_longlong(av[4]);
	if (av[5])
		(*main)->must_to_eat = ft_atoi(av[5]);
	else
		(*main)->must_to_eat = NOT_SPECIFIED;
	if (ft_init_mutex(*main) == ERROR)
		return (ERROR);
	(*main)->start = false;
	if (ft_create_philos(*main) == ERROR)
		return (ERROR);
	free((*main)->forks_mutex);
	free((*main)->philo);
	free(*main);
	return (SUCCESS);
}
