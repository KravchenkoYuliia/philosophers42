/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:14:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/26 14:46:24 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_write_mutex(t_general *main)
{
	if (pthread_mutex_init(&main->write_mutex, NULL) != SUCCESS)
	{
		free(main->philo);
		free(main);
		//stop the threads;
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_forks_mutex(t_general *main)
{
	int	i;

	i = 0;
	main->forks_mutex = calloc(main->nb_of_philo, sizeof(pthread_mutex_t));
	if (!main->forks_mutex)
		return (ERROR);
	while (i < main->nb_of_philo)
	{
		if (pthread_mutex_init(&main->forks_mutex[i], NULL) != SUCCESS)
		{
			free(main->philo);
			free(main);
			//stop the threads;
			pthread_mutex_destroy(&main->write_mutex);
			//destroy all mutex before i
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_food_status_mutex(t_general *main)
{
	if (pthread_mutex_init(&main->food_status_mutex, NULL) != SUCCESS)
	{
		free(main->philo);
		free(main);
		//stop the threads;
		pthread_mutex_destroy(&main->write_mutex);
		//destroy all forks mutex
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_stop_flag_mutex(t_general *main)
{
	if (pthread_mutex_init(&main->stop_mutex, NULL) != SUCCESS)
	{
		free(main->philo);
		free(main);
		//ft_check_stop_flag(philo->main);
		pthread_mutex_destroy(&main->write_mutex);
		pthread_mutex_destroy(&main->food_status_mutex);
		//destroy all forks mutex
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_init_mutex(t_general *main)
{
	if (ft_write_mutex(main) == ERROR)
		return (ERROR);
	if (ft_forks_mutex(main) == ERROR)
		return (ERROR);
	if (ft_food_status_mutex(main) == ERROR)
		return (ERROR);
	if (ft_stop_flag_mutex(main) == ERROR)
		return (ERROR);
	if (ft_init_start_mutex(main) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
