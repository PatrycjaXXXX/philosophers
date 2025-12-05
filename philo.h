/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:35:57 by psmolich          #+#    #+#             */
/*   Updated: 2025/12/05 16:13:55 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define FAIL 1
# define SUCCESS 0

# define TRUE 1
# define FALSE 0

# define INTMAX_LENGTH 10

# define DEAD 0
# define FORK 1
# define EATS 2
# define SLEEPS 3
# define THINKS 4

# include <stdint.h> // int64_t
# include <pthread.h> // pthread_mutex_t

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
	int				id;
	pthread_t		philo;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	int				meals_eaten;
	int				alive;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	t_rules			rules;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_mutex_t	write;
	pthread_mutex_t	read;
}	t_table;

// UTILS
int		ft_atoi(char *str);
int		ft_isdigit(char c);
int		ft_strlen(char *s);

void	ft_error(int code);

int		get_rules(int ac, char **av, t_rules *rules);
int		all_alive(t_table table);
int		smb_still_needs_to_eat(t_table table);
void	status_msg(int status, int id, pthread_mutex_t	msg);

#endif