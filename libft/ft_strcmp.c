/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:05:28 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/28 18:06:44 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (*u1 && *u2)
	{
		if (*u1 != *u2)
			return (*u1 - *u2);
		u1++;
		u2++;
	}
	return (*u1 - *u2);
}
