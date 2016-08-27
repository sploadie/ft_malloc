/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:31:08 by tanguy            #+#    #+#             */
/*   Updated: 2016/08/27 21:34:05 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	print_hex(long num, int depth)
{
	if (depth == 0)
	{
		write(1, "0x", 2);
		return ;
	}
	print_hex(num >> 4, depth - 1);
	num -= (num >> 4) << 4;
	if (num < 10)
		num += '0';
	else
		num += 55;
	write(1, &num, 1);
}

static void	print_title(char *str, long addr)
{
	ft_putstr(str);
	ft_putstr(" : ");
	print_hex(addr, 9);
	write(1, "\n", 1);
}

static long	print_alloc(t_link *node)
{
	long	size;

	print_hex((long)(node + 1), 9);
	ft_putstr(" - ");
	print_hex((long)(node->end), 9);
	ft_putstr(" : ");
	size = (char*)node->end - (char*)node - sizeof(t_link);
	ft_putnbr(size);
	ft_putstr(" octets\n");
	return (size);
}

static long	print_malloc(t_link *node)
{
	long	total;

	total = 0;
	while (node->next != NULL)
	{
		node = node->next;
		total += print_alloc(node);
	}
	return (total);
}

void		show_alloc_mem(void)
{
	t_link	*node;
	long	total;

	total = 0;
	node = alloc_data()->tny;
	print_title("TINY", (long)node);
	total += print_malloc(node);
	node = alloc_data()->med;
	print_title("SMALL", (long)node);
	total += print_malloc(node);
	node = alloc_data()->lrg;
	print_title("LARGE", (long)node);
	total += print_malloc(node);
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putstr(" octets\n");
}
