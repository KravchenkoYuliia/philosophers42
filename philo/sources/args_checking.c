/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:12:15 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/19 16:43:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int ac, char **av)
{
	int	arg;
	int	i;

	arg = 1;
	while (av[arg] && arg < ac)
	{
		i = 0;
		while (av[arg][i])
		{
			if(!(av[arg][i] >= '0' && av[arg][i] <= '9'))
			{
				return (ERROR);
			}
			i++;
		}
		arg++;
	}
	return (SUCCESS);
}

