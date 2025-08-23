/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:47:18 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/23 16:21:35 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eating_routine(t_philo *philo, int min, int max)
{
	if (pthread_mutex_lock(&philo->main->forks_mutex[min]) != SUCCESS)
		return (ERROR);
	if (ft_protected_write(philo, FORK) == ERROR)
		return (ERROR);
	if (pthread_mutex_lock(&philo->main->forks_mutex[max]) != SUCCESS)
		return (ERROR);
	if (ft_protected_write(philo, FORK) == ERROR)
		return (ERROR);
	philo->last_meal_time = ft_get_current_time();
	if (philo->last_meal_time == ERROR)
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

void	ft_init_last_meal_time(t_general *main)
{
	int	i;

	i = 0;
	while (main->philo && i < main->nb_of_philo)
	{
		main->philo[i].already_counted_not_hungry = false;
		main->philo[i].last_meal_time = main->start_of_simulation;
		i++;
	}
}

bool	ft_not_hungry(t_general *main, t_philo *philo)
{
	if (philo->has_eaten_times >= main->must_to_eat)
	{
		if (philo->already_counted_not_hungry == false)
			main->not_hungry_philo++;
		philo->already_counted_not_hungry = true;
	}
	if (main->not_hungry_philo >= main->nb_of_philo)
	{
		ft_stop_flag_is_true(philo);
		return (true);
	}
	return (false);
}
