/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:35:00 by nbled             #+#    #+#             */
/*   Updated: 2023/02/22 23:52:55 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pile	*ft_lstnew(int value, char *str)
{
	t_pile	*n;

	n = malloc(sizeof(t_pile));
	if (!n)
		return (NULL);
	n->token = value;
	n->str = str;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}
