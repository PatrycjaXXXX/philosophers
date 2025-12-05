/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:10:13 by psmolich          #+#    #+#             */
/*   Updated: 2025/12/05 16:11:16 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h> //printf

void	status_msg(int status, int id, pthread_mutex_t	msg)
{
	pthread_mutex_lock(&msg);
	if (status == DEAD)
		printf("timestamp %i died\n", id);
	if (status == FORK)
		printf("timestamp %i has taken a fork\n", id);
	if (status == EATS)
		printf("timestamp %i is eating\n", id);
	if (status == SLEEPS)
		printf("timestamp %i is sleeping\n", id);
	if (status == THINKS)
		printf("timestamp %i is thinking\n", id);
	pthread_mutex_unlock(&msg);
}
