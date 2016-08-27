/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:31:08 by tanguy            #+#    #+#             */
/*   Updated: 2016/08/27 16:29:11 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static int free_small(void *ptr, t_link *node)
{
	while (node->next != NULL)
	{
		if (ptr == node->next + 1)
		{
			node->next = node->next->next;
			return 1;
		}
		node = node->next;
	}
	return 0;
}

void	free(void *ptr)
{
	t_link *node;
	t_link *tmp;

	if (free_small(ptr, alloc_data()->tny) == 1)
		return;
	if (free_small(ptr, alloc_data()->med) == 1)
		return;
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
