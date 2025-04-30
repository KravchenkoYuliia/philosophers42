/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:22:29 by yukravch          #+#    #+#             */
/*   Updated: 2025/04/30 14:02:39 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


typedef struct s_routine{

	int*	new_i;
	pthread_mutex_t	*lock;
	int counter;
} t_routine;


void	*routine(void *bla)
{
	t_routine* rout = (t_routine *)bla;
	pthread_mutex_lock(rout->lock);
	printf("%d thread's started\n", rout->counter);
	printf("i = %d\n", *(rout->new_i));
	(*rout->new_i)++;
	free(rout->new_i);
	printf("%d thread's finished\n", rout->counter);
	pthread_mutex_unlock(rout->lock);
	free(bla);
	return (NULL);
}

int	main()
{
	pthread_t threads[10000];
	t_routine	*rout = NULL;
	pthread_mutex_t	lock;


	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		perror("mutex_init");
		return -1;
	}
	for (int i = 0; i < 10000; i++) {
		rout = malloc(sizeof(t_routine));
		if (!rout)
			return -1;
		rout->new_i = malloc(sizeof(int));
		if (!rout->new_i)
			return -1;
		*(rout->new_i) = i;
		rout->lock = &lock;
		rout->counter = i + 1;
    		if (pthread_create(&threads[i], NULL, (void*)routine, rout) != 0)
		{
			perror("thread create");
			return -1;
		}
	}
	// а join — вже в іншому циклі:
	for (int i = 0; i < 10000; i++) {
    	if (pthread_join(threads[i], NULL) != 0)
	{
		perror("thread_join");
		return -1;
	}
	}
	pthread_mutex_destroy(&lock);
}
