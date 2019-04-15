/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 06:29:23 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/09 15:34:21 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		size_str;
	int		i;

	size_str = 0;
	while (dest[size_str] != '\0')
		size_str++;
	i = 0;
	while ((src[i] != '\0') && (i < nb))
	{
		dest[size_str + i] = src[i];
		i++;
	}
	dest[size_str + i] = '\0';
	return (dest);
}
