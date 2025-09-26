/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodatarace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:25:17 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/26 16:37:28 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

typedef struct {
	int counter;
	pthread_mutex_t lock;
} Shared;

void* increment(void* arg) {
	Shared* data = (Shared*)arg;
	for (int i = 0; i < 1000000; i++) {
		pthread_mutex_lock(&data->lock);
		data->counter++;
		pthread_mutex_unlock(&data->lock);
	}
	return NULL;
}

int main() {
	Shared data = {0, PTHREAD_MUTEX_INITIALIZER};
	pthread_t t1, t2;

	pthread_create(&t1, NULL, increment, &data);
	pthread_create(&t2, NULL, increment, &data);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("Counter = %d\n", data.counter);
	return 0;
}
