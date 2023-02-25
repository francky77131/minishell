/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:35:44 by nbled             #+#    #+#             */
/*   Updated: 2022/09/20 01:35:59 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_pile **pile, t_pile *n)
{
	t_pile	*ptr;

	if (!pile || !n)
		return ;
	if (!(*pile))
	{
		*pile = n;
		return ;
	}
	ptr = *pile;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = n;
	n->prev = ptr;
}
