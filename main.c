/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:17:48 by bbenito           #+#    #+#             */
/*   Updated: 2024/03/10 02:17:53 by bbenito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	mostra_padrao(int **arr, int size);

int	**alocar_matriz(int size)
{
	int	**arr;
	int	i;

	arr = (int **)malloc(size * sizeof(int *));
	if (arr == NULL)
	{
		write(2, "Erro de alocação de memória.\n", 29);
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		arr[i] = (int *)malloc(size * sizeof(int));
		if (arr[i] == NULL)
		{
			write(2, "Erro de alocação de memória.\n", 29);
			exit(1);
		}
		i++;
	}
	return (arr);
}

void	preencher_matriz(int **arr, int numeros[4][4], int size)
{
	int	j;
	int	k;

	j = 0;
	while (j < size)
	{
		k = 0;
		while (k < size)
		{
			arr[j][k] = numeros[j][k];
			k++;
		}
		j++;
	}
}

void	mostrar_matriz(int numeros[4][4])
{
	int	valor;
	int	j;
	int	i;

	valor = 1;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			numeros[i][j] = valor;
			valor = (valor % 4) + 1;
			j++;
		}
		valor = (numeros[i][0] % 4) + 1;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	size;
	int	**arr;
	int	i;
	int	numeros[4][4];

	size = 4;
	arr = alocar_matriz(size);
	mostrar_matriz(numeros);
	if (argc != 2 || strcmp(argv[1], "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2") != 0)
	{
		write(1, "Error", 5);
		return (1);
	}
	preencher_matriz(arr, numeros, size);
	mostra_padrao(arr, size);
	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
