/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:34:17 by psmolich          #+#    #+#             */
/*   Updated: 2025/11/27 14:04:02 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	non_digit_or_too_long(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) || j > INTMAX_LENGTH)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// static int	check_rules(t_rules rules)
// {
// 	if (rules.nbr_of_philos <= 0)
// 		return (FAIL);
// 	return (SUCCESS);
// }

int	get_rules(int ac, char **av, t_rules *rules)
{
	if (ac < 5 || ac > 6)
		return (ft_error(1), FAIL);
	if (non_digit_or_too_long(ac, av))
		return (ft_error(2), FAIL);
	rules->nbr_of_philos = ft_atoi(av[1]);
	rules->t_die = (int64_t)ft_atoi(av[2]);
	rules->t_eat = (int64_t)ft_atoi(av[3]);
	rules->t_sleep = (int64_t)ft_atoi(av[4]);
	if (ac == 6)
		rules->must_eat = ft_atoi(av[5]);
	else
		rules->must_eat = -1;
	// if (check_rules(*rules) == FAIL)
	// 	return (ft_error(1), FAIL);
	return (SUCCESS);
}
