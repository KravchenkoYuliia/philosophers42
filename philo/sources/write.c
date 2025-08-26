/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:39:25 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/26 17:44:24 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

void	ft_get_txt_to_write(char write_it[20], int action)
{
	if (action == FORK)
		ft_strcpy(write_it, "has taken a fork");
	else if (action == EAT)
		ft_strcpy(write_it, "is eating");
	else if (action == SLEEP)
		ft_strcpy(write_it, "is sleeping");
	else if (action == THINK)
		ft_strcpy(write_it, "is thinking");
	else if (action == DIE)
		ft_strcpy(write_it, "died");
	else
		write_it[0] = '\0';
}

int	ft_protected_write(t_philo *philo, int action)
{
	long long	timestamp;
	char		write_it[20];

	timestamp = ft_count_time_from_the_start(philo->main);
	if (timestamp == ERROR)
		return (ERROR);
	ft_get_txt_to_write(write_it, action);
	if (action != DIE && ft_check_stop_flag(philo->main) != SUCCESS)
		return (ERROR);
	if (pthread_mutex_lock(&philo->main->write_mutex) != SUCCESS)
		return (ERROR);
	printf("%lld %d %s\n", timestamp, philo->index + 1, write_it);
	if (action != DIE)
	{
		if (pthread_mutex_unlock(&philo->main->write_mutex) != SUCCESS)
			return (ERROR);
	}
	return (SUCCESS);
}
