/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:35:57 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/26 12:50:24 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define FAIL -1
# define SUCCESS 1

# include <stdint.h> // int64_t

typedef struct s_rules {
	int		nbr_of_philos;
	int64_t	t_die;
	int64_t	t_eat;
	int64_t	t_sleep;
	int		must_eat;
}	t_rules;

typedef struct s_philo {
	t_rules	rules;
	int		i;
}	t_philo;

void	ft_error(int code);
int		ft_atoi(char *str);

#endif