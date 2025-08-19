/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:25:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/19 16:45:42 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

#define UNSIGNED_LONG 4294967295

typedef enum e_index {
	SUCCESS,
	ERROR,
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_index;

/////////////libft

int	ft_strlen(char *str);

//////////////

int	ft_isdigit(int ac, char **av);
int	ft_MAX(int ac, char **av);


///////////////errors

void	ft_error(char *msg);

# endif
