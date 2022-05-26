/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:52:08 by yelgharo          #+#    #+#             */
/*   Updated: 2022/05/25 17:08:19 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	moins;
	int	res;

	i = 0;
	moins = 0;
	res = 0;
	while ((str[i]) && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if ((str[i]) && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			moins++;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (moins % 2 == 0)
		return (res);
	return (res * -1);
}

t_philo	*ft_lstnew(int i, t_data *shared)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	pthread_mutex_init(&(new->fork), NULL);
	new->shared = shared;
	new->id = i;
	new->m_eaten = 0;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*t;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			t = *alst;
			while (t->next != NULL)
				t = t->next;
			t->next = new;
		}
	}
}
