#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strdup(const char *s1);

#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif
