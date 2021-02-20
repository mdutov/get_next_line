/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:18:19 by tcynthia          #+#    #+#             */
/*   Updated: 2021/01/28 14:46:48 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	char	*bgn;

	if (!s1 && !s2)
		return (NULL);
	dest = ft_newstr((s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0));
	if ((bgn = dest))
	{
		if (s1)
			while (*s1)
				*dest++ = *s1++;
		if (s2)
			while (*s2)
				*dest++ = *s2++;
		*dest = '\0';
	}
	return (bgn);
}

char	*ft_newstr(size_t size)
{
	void	*dest;

	if ((dest = malloc(sizeof(char) * (size + 1))))
		ft_memset(dest, 0, size);
	return ((char *)dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char *lasts;
	unsigned char *lastd;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (d == 0 && s == 0)
		return (NULL);
	if (n != 0)
	{
		if (d < s)
			while (n--)
				*d++ = *s++;
		else
		{
			lasts = s + (n - 1);
			lastd = d + (n - 1);
			while (n--)
				*lastd-- = *lasts--;
		}
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)s;
	i = n;
	if (i)
	{
		while (i--)
			*d++ = c;
	}
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = n;
	if (d == 0 && s == 0)
		return (NULL);
	while (i--)
		*d++ = *s++;
	return (dest);
}
