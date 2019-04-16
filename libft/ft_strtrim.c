/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 04:55:20 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/10 05:49:39 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*pt;

	if (!s)
		return (0);
	len = ft_strlen(s);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (!s[i])
		return (ft_strnew(0));
	j = len - 1;
	while (j < len && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	pt = ft_strsub(s, i, j - i + 1);
	return (pt);
}
