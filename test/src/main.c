/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 12:39:44 by tanguy            #+#    #+#             */
/*   Updated: 2016/08/27 16:14:22 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_malloc.h"
#include <stdio.h>

#define M (1024 * 1024)
#include <string.h>
void print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	malloc(25);
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return 0;
}

// int	main()
// {
// 	char *addr;

// 	addr = malloc(16);
// 	free(NULL);
// 	free((void*)addr + 5);
// 	if (realloc((void*) + 5, 10) == NULL)
// 	{
// 		print("Bonjour\n");
// 	}
// 	return 0;
// }

// int	main()
// {
// 	char *addr1;
// 	char *addr2;
// 	char *addr3;

// 	addr1 = (char*)malloc(16 * M);
// 	strcpy(addr1, "Bonjour\n");
// 	print(addr1);
// 	addr2 = (char*)malloc(16 * M);
// 	addr3 = realloc(addr1, 128 * M);
// 	addr3[127 * M] = 42;
// 	print(addr3);
// 	return 0;
// }

// int	main()
// {
// 	int  i;
// 	char *addr;

// 	(void)addr;
// 	i = 0;
// 	while (i < 1024)
// 	{
// 		addr = (char*)malloc(1024);
// 		if (addr == NULL)
// 		{
// 			ft_putstr("NULL returned!\n");
// 			return 0;
// 		}
// 		addr[0] = 42;
// 		free(addr);
// 		i++;
// 	}
// 	return 0;
// }

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
