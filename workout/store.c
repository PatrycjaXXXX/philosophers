/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:33:31 by psmolich          #+#    #+#             */
/*   Updated: 2025/11/27 15:10:09 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	store = 0;

void	*producer_routine(void *arg)
{
int				i;
pthread_mutex_t	*lock;

lock = (pthread_mutex_t *)arg;
i = 0;
while (i < 50)
{
pthread_mutex_lock(lock);
store++;
i++;
pthread_mutex_unlock(lock);
usleep(10000);
}
return (NULL);
}

void	*consumer_routine(void *arg)
{
	int				i;
	pthread_mutex_t	*lock;

	lock = (pthread_mutex_t *)arg;
	i = 0;
	while (i < 50)
	{
	pthread_mutex_lock(lock);
	if (store > 0)
	{
	store--;
	i++;
	}
	pthread_mutex_unlock(lock);
	usleep(10000);
	}
	return (NULL);
}

void	error_routine(void)
{
// some cleanup
return ;
}

int	main(void)
{
pthread_t		producer1;
pthread_t		producer2;
pthread_t		producer3;
pthread_t		consumer1;
pthread_t		consumer2;
pthread_mutex_t	lock;

pthread_mutex_init(&lock, NULL);
if (pthread_create(&producer1, NULL, producer_routine, &lock))
error_routine();
if (pthread_create(&producer2, NULL, producer_routine, &lock))
error_routine();
if (pthread_create(&producer3, NULL, producer_routine, &lock))
error_routine();
if (pthread_create(&consumer1, NULL, consumer_routine, &lock))
error_routine();
if (pthread_create(&consumer2, NULL, consumer_routine, &lock))
error_routine();
pthread_detach(producer1);
pthread_join(producer2, NULL);
pthread_join(producer3, NULL);
pthread_join(consumer1, NULL);
pthread_join(consumer2, NULL);
pthread_mutex_destroy(&lock);
printf("Final stock value: %i\n", store);
}
