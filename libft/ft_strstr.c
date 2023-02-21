/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:41:57 by rpoggi            #+#    #+#             */
/*   Updated: 2021/10/12 09:42:32 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	it;
	int	is;

	is = 0;
	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (str[is] != '\0')
	{
		it = 0;
		while (str[is + it] != '\0' && str[is + it] == to_find[it])
		{
			if (to_find[it + 1] == '\0')
			{
				return (&str[is]);
			}
			it++;
		}
		is++;
	}
	return (0);
}
