/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_more.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:24:29 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/26 19:42:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_if_one_philo(t_general *main, int min)
{
	if (main->nb_of_philo == 1)
	{
		pthread_mutex_unlock(&main->forks_mutex[min]);
		usleep(main->time_to_die * 1000);
		return (true);
	}
	return (false);
}

int	ft_change_last_meal_time(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->main->food_status_mutex) != SUCCESS)
		return (ERROR);
	philo->last_meal_time = ft_get_current_time();
	if (philo->last_meal_time == ERROR)
		return (ERROR);
	if (pthread_mutex_unlock(&philo->main->food_status_mutex) != SUCCESS)
		return (ERROR);
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int	ft_change_has_eaten_times(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->main->food_status_mutex) != SUCCESS)
		return (ERROR);
	philo->has_eaten_times++;
	if (pthread_mutex_unlock(&philo->main->food_status_mutex) != SUCCESS)
		return (ERROR);
	if (ft_time_to_eat(philo) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
