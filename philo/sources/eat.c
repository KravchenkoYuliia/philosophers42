/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:47:18 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/26 19:43:31 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_taking_forks(t_philo *philo, int min, int max)
{
	if (pthread_mutex_lock(&philo->main->forks_mutex[min]) != SUCCESS)
		return (ERROR);
	if (ft_protected_write(philo, FORK) == ERROR)
	{
		pthread_mutex_unlock(&philo->main->forks_mutex[min]);
		return (ERROR);
	}
	if (ft_if_one_philo(philo->main, min) == true)
		return (ERROR);
	if (ft_check_stop_flag(philo->main) != SUCCESS
		|| pthread_mutex_lock(&philo->main->forks_mutex[max]) != SUCCESS)
	{
		pthread_mutex_unlock(&philo->main->forks_mutex[min]);
		return (ERROR);
	}
	if (ft_protected_write(philo, FORK) == ERROR)
	{
		pthread_mutex_unlock(&philo->main->forks_mutex[min]);
		pthread_mutex_unlock(&philo->main->forks_mutex[max]);
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_eating_routine(t_philo *philo, int min, int max)
{
	if (ft_taking_forks(philo, min, max) == ERROR)
		return (ERROR);
	if (ft_change_last_meal_time(philo) == ERROR)
	{
		pthread_mutex_unlock(&philo->main->forks_mutex[min]);
		pthread_mutex_unlock(&philo->main->forks_mutex[max]);
		return (ERROR);
	}
	if (ft_change_has_eaten_times(philo) == ERROR)
	{
		pthread_mutex_unlock(&philo->main->forks_mutex[min]);
		pthread_mutex_unlock(&philo->main->forks_mutex[max]);
		return (ERROR);
	}
	if (pthread_mutex_unlock(&philo->main->forks_mutex[min]) != SUCCESS)
	{
		pthread_mutex_unlock(&philo->main->forks_mutex[max]);
		return (ERROR);
	}
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
		main->philo[i].has_eaten_times = 0;
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
		return (true);
	return (false);
}
