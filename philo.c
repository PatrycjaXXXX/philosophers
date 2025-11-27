/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:35:54 by psmolich          #+#    #+#             */
/*   Updated: 2025/11/27 15:59:41 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h> //free
#include <stdio.h> //printf
#include <unistd.h> //usleep

void	clean_the_table(t_table *table, int sets)
{
	while (sets--)
		pthread_mutex_destroy(&(table->forks[sets]));
	free(table->forks);
	free(table->philos);
	pthread_mutex_destroy(&(table->msg));
	pthread_mutex_destroy(&(table->write));
	pthread_mutex_destroy(&(table->read));
}

void	seat_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->rules.nbr_of_philos)
		pthread_mutex_init(&(table->forks[i++]), NULL);
	i = 0;
	while (i < table->rules.nbr_of_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].left_fork = table->forks[i];
		table->philos[i].right_fork = table->forks[(i + 1)
			% table->rules.nbr_of_philos];
		i++;
	}
}

void	status_msg(int status, int id, pthread_mutex_t	msg)
{
	pthread_mutex_lock(&msg);
	if (status == DEAD)
		printf("timestamp %i died", id);
	if (status == FORK)
		printf("timestamp %i has taken a fork", id);
	if (status == EATS)
		printf("timestamp %i is eating", id);
	if (status == SLEEPS)
		printf("timestamp %i is sleeping", id);
	if (status == THINKS)
		printf("timestamp %i is thinking", id);
	pthread_mutex_unlock(&msg);
}

int	all_alive(t_table table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(table.read));
	while (i < table.rules.nbr_of_philos)
	{
		if (!table.philos[i].alive)
			return (status_msg(DEAD, i, table.msg), 0);
		i++;
	}
	pthread_mutex_unlock(&(table.read));
	return (1);
}

void	*routine(void *arg)
{
	t_data	*data;
	t_table	table;

	data = (t_data *)arg;
	table = data->table;
	while (all_alive(table) && table.rules.must_eat)
	{
		usleep(10);
		status_msg(THINKS, 1, table.msg);
	}
	return (NULL);
}

// 1 - number_of_philosophers
// 2 - time_to_die
// 3 - time_to_eat
// 4 - time_to_sleep
// 5 - [number_of_times_each_philosopher_must_eat]
int	main(int ac, char **av)
{
	t_table	table;

	table.rules = (t_rules){0};
	if (get_rules(ac, av, &table.rules) == FAIL)
		return (FAIL);
	if (table.rules.nbr_of_philos == 0)
		return (SUCCESS);
	table.philos = malloc(sizeof(t_philo) * table.rules.nbr_of_philos);
	if (!table.philos)
		return (ft_error(0), FAIL);
	table.forks = malloc(sizeof(pthread_mutex_t) * table.rules.nbr_of_philos);
	if (!table.forks)
		return (ft_error(0), FAIL);
	pthread_mutex_init(&(table.msg), NULL);
	pthread_mutex_init(&(table.write), NULL);
	pthread_mutex_init(&(table.read), NULL);
	seat_philos(&table);
	return (clean_the_table(&table, table.rules.nbr_of_philos), SUCCESS);
}
