/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domy <domy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:06:48 by domy              #+#    #+#             */
/*   Updated: 2023/02/21 15:35:08 by domy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void adjustmat(t_data *data)
{
	int i;
	int x;
	int sp;
	int len;
	
	sp = 0;
	i = 0;
	len  = 0;
	while (data->mat[i])
	{
		x = 0;
		while (data->mat[i][x])
		{
			if (data->mat[i][x] == ' ')
				sp++;
			else 
				break;
			x++;
		}
		x = 0;
		if (sp != 0)
		{
			len = ft_strlen(data->mat[i]) - 1;
			while (len > 0)
			{
				data->mat[i][x] = data->mat[i][x + sp];
				x++;
				len--;
			}
			data->mat[i][x] = '\0';
		}
		i++;
	}
}
