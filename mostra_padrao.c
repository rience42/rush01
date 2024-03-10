/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:27:02 by bbenito           #+#    #+#             */
/*   Updated: 2024/03/09 23:27:05 by bbenito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	mostra_padrao(int **arr, int size)
{
	int		linha;
	int		col;
	char	num;

	linha = 0;
	while (linha < size)
	{
		col = 0;
		while (col < size)
		{
			num = arr[linha][col] + '0';
			write(1, &num, 1);
			if (col < size - 1)
			{
				write(1, " ", 1);
			}
			col++;
		}
		write(1, "\n", 1);
		linha++;
	}
}
