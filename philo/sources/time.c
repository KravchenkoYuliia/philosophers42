/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:34:45 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/26 19:01:48 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != SUCCESS)
		return (ERROR);
	return ((long long)time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	ft_count_time_from_the_start(t_general *main)
{
	long long		current_time;
	long long		result;
	struct timeval	time;

	if (gettimeofday(&time, NULL) != SUCCESS)
		return (ERROR);
	current_time = (long long)time.tv_sec * 1000 + time.tv_usec / 1000;
	result = current_time - main->start_of_simulation;
	return (result);
}

int	ft_time_to_eat(t_philo *philo)
{
	t_time	eat;

	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (ERROR);
	eat.current_time = ft_get_current_time();
	if (eat.current_time == ERROR)
		return (ERROR);
	eat.deadline = eat.current_time + philo->main->time_to_eat;
	eat.time_left = SIGNED_LONG_LONG;
	if (ft_protected_write(philo, EAT) == ERROR)
		return (ERROR);
	while (eat.time_left > 0)
	{
		eat.current_time = ft_get_current_time();
		if (eat.current_time == ERROR)
			return (ERROR);
		eat.time_left = eat.deadline - eat.current_time;
		if (eat.time_left <= 0)
			break ;
		if (ft_check_stop_flag(philo->main) != SUCCESS)
			return (ERROR);
		if (usleep(ft_min(eat.time_left * 1000, 500)) != SUCCESS)
			return (ERROR);
	}
	return (SUCCESS);
}
