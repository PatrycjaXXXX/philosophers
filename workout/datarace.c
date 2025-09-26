/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datarace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:22:24 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/26 16:24:21 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

int counter = 0;

void*	increment(void* arg)
{
	for (int i = 0; i < 1000000; i++)
		counter++;
	return NULL;
}

int main(void)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, increment, NULL);
	pthread_create(&t2, NULL, increment, NULL);
	pthread_join(t2, NULL);
	pthread_join(t1, NULL);
	printf("Counter = %d\n", counter);
	return 0;
}
