/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:16:50 by psmolich          #+#    #+#             */
/*   Updated: 2025/11/27 14:03:11 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_error(int code)
{
	char	*err_msg[17];

	err_msg[0] = "Error: memory allocation failed";
	err_msg[1] = "Error: invalid arguments.\n"
		"Usage: ./philo number_of_philosophers time_to_die time_to_eat "
		"time_to_sleep [number_of_times_each_philosopher_must_eat]";
	err_msg[2] = "Error: invalid arguments.\n"
		"All arguments must be properly formatted "
		"and must be non-negative integers.";
	err_msg[3] = "";
	err_msg[4] = "";
	err_msg[5] = "";
	err_msg[6] = "";
	err_msg[7] = "";
	err_msg[8] = "";
	err_msg[9] = "";
	err_msg[10] = "";
	err_msg[11] = "";
	err_msg[12] = "";
	err_msg[13] = "";
	err_msg[14] = "";
	err_msg[15] = "";
	err_msg[16] = "";
	// w przyszłości użyć mutexa do pisania
	printf("%s\n", err_msg[code]);
}
