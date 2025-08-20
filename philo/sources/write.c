/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:39:25 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/20 18:29:50 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

int	ft_protected_write(t_general *main, char *msg)
{
	int	length;

	length = ft_strlen(msg);
	if (pthread_mutex_lock(&main->write_mutex) != SUCCESS)
		return (ERROR);
	write(1, msg, length);
	if (pthread_mutex_unlock(&main->write_mutex) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
