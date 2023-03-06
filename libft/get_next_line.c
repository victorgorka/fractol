/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:01:33 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/18 19:25:38 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Recibe el buffer y copia todos los caracteres despues del primer salto de
//linea y lo devuelve con reserva de memoria
static void	ft_save_chars(char **buff, int len)
{
	char			*temp;
	unsigned int	i;

	temp = *buff;
	i = 0;
	while ((*buff)[i] != '\n' && (*buff)[i])
		i++;
	if ((*buff)[i] == '\n')
		i++;
	*buff = ft_strdup_gnl((*buff) + i);
	free(temp);
	if (!ft_strchr_gnl(*buff, '\n') && len == 0)
	{
		free(*buff);
		*buff = NULL;
	}
}

static char	*ft_get_line(const char *s1)
{
	char	*cpy;
	size_t	size;

	size = 0;
	while (s1[size] && s1[size] != '\n' )
		size++;
	if (s1[size] == '\n')
		size++;
	cpy = malloc((size + 1) * sizeof(char));
	if (cpy == 0)
		return (0);
	ft_memcpy_gnl(cpy, s1, size);
	cpy[size] = '\0';
	if (*cpy == 0)
	{
		free(cpy);
		return (NULL);
	}
	return (cpy);
}
//Funcion que lee el fichero hasta que encuentre un salto de linea, modifica
//buff con las nuevas lecturas

static int	ft_read_fd(int fd, char **buff)
{
	char	got[BUFFER_SIZE + 1];
	char	*temp;
	int		len;
	int		i;

	len = 1;
	i = 0;
	while (len > 0 && !ft_strchr_gnl(*buff, '\n'))
	{
		temp = *buff;
		len = read(fd, got, BUFFER_SIZE);
		if (len == -1 || len == 0)
			return (len);
		got[len] = '\0';
		*buff = ft_strjoin_gnl(*buff, got);
		while (i < BUFFER_SIZE)
			got[i++] = 0;
		i = 0;
		free(temp);
	}
	return (len);
}

char	*get_next_line(int fd)
{
	int			len;
	char		*line;
	static char	*buff;

	if (buff == 0)
	{
		buff = malloc(sizeof(char));
		buff[0] = '\0';
	}
	if (!ft_strchr_gnl(buff, '\n'))
		len = ft_read_fd(fd, &buff);
	if (!buff || len == -1 || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	line = ft_get_line(buff);
	ft_save_chars(&buff, len);
	return (line);
}
