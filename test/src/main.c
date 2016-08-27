/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 12:39:44 by tanguy            #+#    #+#             */
/*   Updated: 2016/08/27 10:38:28 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_malloc.h"
#include <stdio.h>

int	main()
{
	int  i;
	char *addr;

	(void)addr;
	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		if (addr == NULL)
		{
			ft_putstr("NULL returned!\n");
			return 0;
		}
		addr[0] = 42;
		free(addr);
		i++;
	}
	return 0;
}

// int	main()
// {
// 	ft_putstr("Malloc...\n");
// 	malloc(0);
// 	ft_putstr("Free...\n");
// 	free(NULL);
// 	ft_putstr("Realloc...\n");
// 	realloc(NULL, 0);
// 	ft_putstr("Show alloc mem...\n");
// 	show_alloc_mem();
// 	printf("Page Size: %d", getpagesize());
// 	return 0;
// }
