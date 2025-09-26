/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:35:54 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/26 13:12:42 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_rules(int ac, char **av, t_rules *rules)
{
	if (ac < 5 || ac > 6)
		return (ft_error(0), FAIL);
	rules->nbr_of_philos = ft_atoi(av[1]);
	rules->t_die = (int64_t)ft_atoi(av[2]);
	rules->t_eat = (int64_t)ft_atoi(av[3]);
	rules->t_sleep = (int64_t)ft_atoi(av[4]);
	if (rules->nbr_of_philos < 0
		|| rules->t_die < 0
		|| rules->t_eat < 0
		|| rules->t_sleep < 0)
		return (ft_error(1), FAIL);
	if (ac == 6)
	{
		rules->must_eat = ft_atoi(av[5]);
		if (rules->must_eat < 0)
			return (ft_error(1), FAIL);
	}
	else
		rules->must_eat = -1;
	return (SUCCESS);
}

int	populate_philos(t_philo **philos, t_rules rules)
{
	int	i;

	i = 0;
	while (i < rules.nbr_of_philos)
	{
		philo
		philos[i]->rules = rules;
		philos[i]->i = i;
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
	t_rules	rules;
	t_philo	*philos;

	rules = (t_rules){0};
	if (get_rules(ac, av, &rules) == FAIL)
		return (FAIL);
	philos = (t_philo *)malloc(sizeof(t_philo) * rules.nbr_of_philos);
	if (!philos)
		return (ft_error(13), FAIL);
	if (populate_philos(&philos, rules) == FAIL)
		return (FAIL);
	}