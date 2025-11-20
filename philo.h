/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:35:57 by psmolich          #+#    #+#             */
/*   Updated: 2025/11/20 18:38:29 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define FAIL 1
# define SUCCESS 0
# define UINT_LENGTH 10

# include <stdint.h> // int64_t
# include <stdio.h>

typedef struct s_rules
{
	int		nbr_of_philos;
	int64_t	t_die;
	int64_t	t_eat;
	int64_t	t_sleep;
	int		must_eat;
}	t_rules;

typedef struct s_philo
{
	t_rules	rules;
	int		i;
}	t_philo;

// UTILS
int		ft_atoi(char *str);
int		ft_isdigit(char c);
int		ft_stlen(char *s);

void	ft_error(int code);


#endif