/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domy <domy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:45:47 by domy              #+#    #+#             */
/*   Updated: 2023/02/21 15:49:23 by domy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void re_sost_space(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->mat[i])
	{
		j = 0;
		while (data->mat[i][j])
		{
			if (data->mat[i][j] == data->ascii_s)
				data->mat[i][j] = ' ';
			j++;
		}
		i++;
	}
}

char  *sost_space(t_data *data, char *input)
{
	int i;
	int tmp;
	int y;

	tmp = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '"')
		{
			i++;
			while (input[i] != '"')
			{
				if (input[i] == ' ')
						input[i] = data->ascii_s;
					i++;
			}
		}
		i++;
	}
	return (input);
}

int	check_ascii(t_data *data, char *input)
{
	int i;
	int len;
    int sost;

	len = ft_strlen(input);
    sost = 33;
	i = 0;
	while (input[i])
	{
		data->ascii[i] = (int)input[i];
		i++;
	}
    i = 0;
    while (data->ascii[i] && len > 0)
    {
        if (data->ascii[i] == sost)
        {
            i = 0;
            sost++;
			len = ft_strlen(input);
        }
        else
		{
			i++;
			len--;
		}
    }
	return (sost);
}

void splitting(t_data *data, char *input)
{
	data->ascii_s = check_ascii(data, input);
	sost_space(data, input);
	data->mat = ft_split(input, ' ');
	adjustmat(data);
	re_sost_space(data);
}
