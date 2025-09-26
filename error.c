/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:16:50 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/26 13:05:52 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_error(int code)
{
	char	*err_msg[17];

	err_msg[0] = "Wrong number of arguments";
	err_msg[1] = "Argument cannot be a negative number";
	err_msg[2] = "";
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
	err_msg[13] = "General error: memory allocation failed";
	err_msg[14] = "";
	err_msg[15] = "";
	err_msg[16] = "";
	printf("Error\n%s\n", err_msg[code]);
}