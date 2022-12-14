/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:42:12 by hterras           #+#    #+#             */
/*   Updated: 2022/09/22 13:45:41 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_info		t_info;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meal;
	long long		last_meal;
	t_info			*info;
}					t_philo;

typedef struct s_info
{
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				nte;
	int				status;
	int				all_eat;
	long long		start_time;
	t_philo			*philosopher;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_print;
}			t_info;

//UTILS
int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_exit(char *str);
void		print_wmutex(t_philo *p, char *str);
long long	get_time(void);
void		usleep2(t_info *p, long long time);

//INIT
int			philo_init(void);
t_info		*info_init(void);
int			init_mutex(t_info *p);

//PARSING
int			ft_check_nbr(t_info *philo);
int			ft_check_num(char	**argv);
int			ft_check(int argc, char **argv, t_info *philo);

//ROUTINE
void		*routine_philo(void *p);
void		eat(t_philo *p);
void		dead(t_info *p);

//CREATE DESTROY
int			create_philo(t_info *p);
int			destroy(t_info *info);

#endif