/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:02:37 by ahajji            #+#    #+#             */
/*   Updated: 2022/10/30 16:03:01 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*con[OPEN_MAX];
	char		*ptr;
	int			r;

	r = 1;
	ptr = calloc(1, 1);
	if (con[fd])
		ptr = ft_strjoin(con[fd], ptr);
	while (r)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (NULL);
		buf[r] = '\0';
		ptr = ft_strjoin(ptr, buf);
		if (new_line(ptr))
			break ;
	}
	con[fd] = get_last_line(ptr);
	return (get_line(ptr));
}
