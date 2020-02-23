/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:02:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/10/29 14:40:34 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

static char	*ft_strtrim_helper(char const *s1, int start, int end)
{
	int		i;
	int		j;
	char	*str_trimmed;
	int		str_trimmed_length;

	str_trimmed_length = end - start + 1;
	if (!(str_trimmed = (char *)malloc(str_trimmed_length + 1)))
		return (NULL);
	i = start;
	j = 0;
	while (i <= end)
	{
		str_trimmed[j] = s1[i];
		j++;
		i++;
	}
	str_trimmed[j] = '\0';
	return (str_trimmed);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		s1_length;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	i = -1;
	while (is_set(set, s1[++i]))
		if (s1[i + 1] == '\0')
			return (ft_calloc(1, 1));
	start = i;
	s1_length = ft_strlen(s1) - 1;
	while (s1_length && is_set(set, s1[s1_length]))
		s1_length--;
	end = s1_length;
	return (ft_strtrim_helper(s1, start, end));
}
