/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:35:54 by psmolich          #+#    #+#             */
/*   Updated: 2025/12/05 16:14:42 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h> //free
#include <stdio.h> //printf
#include <unistd.h> //usleep

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_table	table;

	philo = (t_philo *)arg;
	table = *(philo->table);
	while (all_alive(table) && smb_still_needs_to_eat(table))
	{
		usleep(100);
		status_msg(THINKS, philo->id, table.msg);
		philo->meals_eaten++;
	}
	return (NULL);
}

void	seat_philos(t_table *table)
{
	int		i;

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
		table->philos[i].meals_eaten = 0;
		table->philos[i].alive = 1;
		table->philos[i].table = table;
		i++;
	}
	i = 0;
	while (i < table->rules.nbr_of_philos)
	{
		pthread_create(&(table->philos[i].philo), NULL, philo_routine, &(table->philos[i]));
		i++;
	}
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
