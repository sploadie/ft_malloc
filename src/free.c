/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:31:08 by tanguy            #+#    #+#             */
/*   Updated: 2016/08/27 10:15:13 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	free(void *ptr)
{
	t_link *node;
	t_link *tmp;

	node = alloc_data()->tny;
	while (node->next != NULL)
	{
		if (ptr == node->next + 1)
			return (void)(node->next = node->next->next);
		node = node->next;
	}
	node = alloc_data()->med;
	while (node->next != NULL)
	{
		if (ptr == node->next + 1)
			return (void)(node->next = node->next->next);
		node = node->next;
	}
	node = alloc_data()->lrg;
	while (node->next != NULL)
	{
		if (ptr == node->next + 1)
		{
			tmp = node->next->next;
			munmap(node->next, (char*)node->next->end - (char*)node->next);
			return (void)(node->next = tmp);
		}
		node = node->next;
	}
}
