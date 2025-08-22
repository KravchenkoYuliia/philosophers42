/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:01:15 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/22 18:01:53 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	if (ft_protected_write(philo, THINK) == ERROR)
		return (ERROR);
	if (philo->index % 2 == 0)
	{
		if (usleep(1000) != SUCCESS)
			return (ERROR);
	}
	return (SUCCESS);
}

int	ft_eating_routine(t_philo *philo, int min, int max)
{
	if (pthread_mutex_lock(&philo->main->forks_mutex[min]) != SUCCESS)
		return (ERROR);
	if (pthread_mutex_lock(&philo->main->forks_mutex[max]) != SUCCESS)
		return (ERROR);
	if (ft_protected_write(philo, EAT) == ERROR)
		return (ERROR);
	philo->has_eaten_times++;
	if (usleep(philo->main->time_to_eat * 1000) != SUCCESS)
		return (ERROR);
	if (pthread_mutex_unlock(&philo->main->forks_mutex[min]) != SUCCESS)
		return (ERROR);
	if (pthread_mutex_unlock(&philo->main->forks_mutex[max]) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int	ft_eat(t_philo *philo)
{
	int	right;
	int	left;

	right = philo->right_fork;
	left = philo->left_fork;
	if (right < left)
	{
		if (ft_eating_routine(philo, right, left) == ERROR)
			return (ERROR);
	}
	else
	{
		if (ft_eating_routine(philo, left, right) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
