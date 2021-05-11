#include "get_next_line.h"

static int	ft_writetotail(char *buffer, char **tail)
{
	char	*temp1;

	temp1 = *tail;
	*tail = ft_strjoin(*tail, buffer);
	if (!*tail)
		return (-1);
	if (temp1)
		free(temp1);
//	if (ft_strlen(temp1) != 0)
//	free(temp1);
	return (0);
}

static int	ft_cleantail(char **line, char **tail)
{
	char	*temp1;

	if (!*tail)
	{
		///error todo: lol kek cheburek
		*line = ft_strdup("");
		return (0); /// EOF
	}
	temp1 = *tail;
	*line = ft_strdup(*tail);
	if (!*line)
		return (-1);
	free(temp1);
	return (0);
}

static int	ft_getfromtail(char **line, char **tail)
{
	size_t		len;
	char		*temp;
	char		*n;

	len = 0;
	temp = *tail;
	n = ft_strchr(*tail, '\n');
	n++;
	while (temp[len] != '\n')
		len++;
	*line = ft_substr(*tail, 0, len);
	if (!*line)
		return (-1);
	*tail = ft_strdup(n);
	if (!*tail)
		return (-1);
	free(temp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*tail = NULL;
	int			status;
	ssize_t		bytes;

	if (!fd || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1) // check line == NULL /*todo: !fd < 0*/
		return (-1);
	status = 0;
	while (!tail || (!ft_strchr(tail, '\n')  && !status))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (-1);
		if (bytes == 0)
		{
			status = ft_cleantail(line, &tail);
			return (status);
		}
		buffer[bytes] = '\0';
		status = ft_writetotail(buffer, &tail);
	}
	if (ft_strchr(tail, '\n'))
		status = ft_getfromtail(line, &tail);
	return (status);
}
