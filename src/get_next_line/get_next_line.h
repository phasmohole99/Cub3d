/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:02:36 by moamzil           #+#    #+#             */
/*   Updated: 2023/07/30 12:20:14 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>

int		gnl_strchr(char *s, int c);
char	*keep_aftr_nw(char *safe);
char	*gnl_calloc(size_t count, size_t size);
char	*gnl_strjoin(char *buff, char *safe);
char	*gnl_substr(char *safe);
size_t	gnl_strlen_v2(char *buff);
size_t	gnl_strlen(char *buff, int option);
char	*get_next_line(int fd);

#endif
