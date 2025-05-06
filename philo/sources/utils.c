/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:34:08 by yukravch          #+#    #+#             */
/*   Updated: 2025/05/06 17:34:57 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_atoi(char *str)
{
	size_t		result;

	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

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
				return (1);
			}
			i++;
		}
		arg++;
	}
	return (0);
}

unsigned long long	ft_atoi_long(char *str)
{
	unsigned long long	result;

	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}

int	ft_MAX(int ac, char **av)
{
	int	arg;
	size_t	max_size_t;

	if (ft_atoi(av[1]) > 200)
	{
		ft_error("Number of philosophers can't exceed 200");
		return (1);
	}
	if (ft_atoi(av[1]) == 0)
	{
		printf("Add at least one philosopher\n");
		return (1);
	}
	arg = 2;
	max_size_t = 4294967295;
	while (av[arg] && arg < ac)
	{
		if (ft_atoi_long(av[arg]) > max_size_t)
		{
			ft_error("Don't exceed the size_t max in arguments");
			return (1);
		}
		arg++;
	}
	return (0);
}
