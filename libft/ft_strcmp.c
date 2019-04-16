/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:28:33 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/09 15:32:58 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *str1, const char *str2)
{
	int				i;
	int				c;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	c = 0;
	st1 = (unsigned char *)str1;
	st2 = (unsigned char *)str2;
	while ((st1[i] || st2[i]) && c == 0)
	{
		c = st1[i] - st2[i];
		i++;
	}
	return (c);
}
