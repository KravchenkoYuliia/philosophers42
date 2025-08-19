/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:12:15 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/19 19:22:40 by yukravch         ###   ########.fr       */
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

int	ft_av1_check(char *av1)
{
	int	i;

	i = ft_atoi(av1);
	if (i < 0)
	{
		ft_error("INT MAX is exceeded");
		return (ERROR);
	}
	else if (i == 0)
	{
		ft_error("Put at least one philo");
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_av2_av3_av4_check(char **av)
{
	int		i;
	unsigned long	temp;

	i = 2;
	while (i < 5)
	{
		temp = ft_atoi_unsigned_longlong(av[i]);
		if (temp == 0)
		{
			ft_error("Don't be greedy, put something more");
			return (ERROR);
		}
		else if (temp > SIGNED_LONG_LONG)
		{
			ft_error("Long long is exceeded... Impressive");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_av5(char *av5)
{
	int	i;

	i = ft_atoi(av5);
	if (i == 0)
	{
		ft_error("Why put 0?");
		return (ERROR);
	}
	else if (i < 0)
	{
		ft_error("INT MAX is exceeded");
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_limits(char **av)
{
	if (ft_av1_check(av[1]) == ERROR)
		return (ERROR);
	else if (ft_av2_av3_av4_check(av) == ERROR)
		return (ERROR);
	if (av[5] && ft_av5(av[5]) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
