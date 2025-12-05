/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continuation_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:12:13 by psmolich          #+#    #+#             */
/*   Updated: 2025/12/05 16:12:58 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_alive(t_table table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(table.read));
	while (i < table.rules.nbr_of_philos)
	{
		if (!table.philos[i].alive)
			return (pthread_mutex_unlock(&(table.read)),
				status_msg(DEAD, i, table.msg), FALSE);
		i++;
	}
	return (pthread_mutex_unlock(&(table.read)), TRUE);
}

int	smb_still_needs_to_eat(t_table table)
{
	int	i;
	int	nbr_fed;

	i = 0;
	pthread_mutex_lock(&(table.read));
	if (table.rules.must_eat == -1)
		return (pthread_mutex_unlock(&(table.read)), TRUE);
	while (i < table.rules.nbr_of_philos)
	{
		if (table.philos[i].meals_eaten < table.rules.must_eat)
			return (pthread_mutex_unlock(&(table.read)), TRUE);
		i++;
	}
	return (pthread_mutex_unlock(&(table.read)), FALSE);
}
