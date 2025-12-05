/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:31 by psmolich          #+#    #+#             */
/*   Updated: 2025/12/05 16:14:59 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_the_table(t_table *table, int sets)
{
	int	i;

	while (sets--)
		pthread_mutex_destroy(&(table->forks[sets]));
	i = 0;
	while (i < table->rules.nbr_of_philos)
	{
		pthread_join(table->philos[i].philo, NULL);
		i++;
	}
	free(table->forks);
	free(table->philos);
	pthread_mutex_destroy(&(table->msg));
	pthread_mutex_destroy(&(table->write));
	pthread_mutex_destroy(&(table->read));
}
