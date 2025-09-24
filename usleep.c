/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:33:31 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/24 14:18:17 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h> //atoi
#include <stdint.h> // int64_t
#include <unistd.h> //usleep
#include <stdio.h> //printf

// void	ms_sleep(int64_t	miliseconds_to_sleep)
// {
// 	struct timeval	start;
// 	struct timeval	end;
// 	struct timeval	current;
	
// 	gettimeofday(&start, NULL);
// 	end = start;
// 	if (miliseconds_to_sleep >= 1000)
// 		end.tv_sec += miliseconds_to_sleep/1000;
// 	end.tv_usec += miliseconds_to_sleep % 1000 * 1000;
// 	while (1)
// 	{
// 		gettimeofday(&current, NULL);
// 		if(current.tv_sec >= end.tv_sec && current.tv_usec >= end.tv_usec)
// 			break;
// 	}
// }

// int	get_difference(struct timeval start, struct timeval end)
// {
// 	time_t		sec_diff;
// 	suseconds_t	usec_diff;

// 	sec_diff = end.tv_sec - start.tv_sec;
// 	usec_diff = end.tv_usec - start.tv_usec;
// 	return ((int)(sec_diff*1000*1000) + (int)(usec_diff));
// 	// return ((int)(sec_diff*1000) + (int)(usec_diff/1000));
// }

// int	main(int ac, char **av)
// {
// 	int				requestet_time;
// 	struct timeval	start;
// 	struct timeval	end;
// 	int				real_time;

// 	if (ac != 2)
// 		return (-1);
// 	requestet_time = atoi(av[1]);
// 	gettimeofday(&start, NULL);
// 	ms_sleep(requestet_time);
// 	gettimeofday(&end, NULL);
// 	real_time = get_difference(start, end);
// 	printf("requestet: %i, real: %i\n", requestet_time, real_time);
// }

int	get_difference(struct timeval start, struct timeval end)
{
	time_t		sec_diff;
	suseconds_t	usec_diff;

	sec_diff = end.tv_sec - start.tv_sec;
	usec_diff = end.tv_usec - start.tv_usec;
	return ((int)(sec_diff*1000*1000) + (int)(usec_diff));
	// return ((int)(sec_diff*1000) + (int)(usec_diff/1000));
}

int	main(int ac, char **av)
{
	int				requestet_time;
	struct timeval	start;
	struct timeval	end;
	int				real_time;

	if (ac != 2)
		return (-1);
	requestet_time = atoi(av[1]);
	requestet_time *= 1000;
	gettimeofday(&start, NULL);
	usleep(requestet_time);
	gettimeofday(&end, NULL);
	real_time = get_difference(start, end);
	printf("requestet: %i, real: %i\n", requestet_time, real_time);
}
