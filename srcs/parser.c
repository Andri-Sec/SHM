#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "../includes/shm_scanner.h"

char	*ft_strcat_proc(char *str)
{
	t_lenstr	*len;
	char		*dst;
	size_t		i;
	size_t		j;

	len = (t_lenstr *)malloc(sizeof(t_lenstr));
	len->len_front = ft_strlen("/proc/");
	len->len_str = ft_strlen(str);
	len->len_end = ft_strlen("/maps");
	dst = (char *)malloc(sizeof(char *) * \
(len->len_front + len->len_end + len->len_str + 1));
	if (dst == NULL)
	{
		ft_free((void **)&len);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i < len->len_front)
	{
		*(dst + (j++)) = "/proc/"[i++];
	}
	i = 0;
	while (i < len->len_str)
	{
		*(dst + (j++)) = *(str + (i++));
	}
	i = 0;
	while (i < len->len_end)
	{
		*(dst + (j++)) = "/maps"[i++];
	}
	*(dst + j) = '\0';
	ft_free((void **)&len);
	return (dst);
}

void	ft_string_map(char **str_dst, char *src)
{
	size_t	size_all;
	size_t	size_str_dst;
	size_t	size_src;
	char	*tmp;

	if (src != NULL)
	{
		size_src = (ft_strlen(src) * sizeof(char));
		if (*str_dst == NULL)
		{
			size_str_dst = 0;
			size_all = size_src;
			*str_dst = (char *)malloc(size_all);
			if (*str_dst == NULL)
				return ;
			ft_strcpy_mem(str_dst, src);
		}
		else
		{
			size_str_dst = (ft_strlen(*str_dst) * sizeof(char));
			size_all = size_str_dst + size_src;
			tmp = realloc(*str_dst, size_all + 1);
			if (tmp == NULL)
				return ;
			*str_dst = tmp;
			ft_strcpy_mem(str_dst, src); 
		}
	}
	else
	{
		return ;
	}
}

char	*ft_parser_maps(char *text)
{
	size_t	count_read;
	char	*str_maps;
	t_proc	*cmpt;
	
	count_read = 0;
	str_maps = NULL;
	cmpt = (t_proc *) malloc(sizeof(t_proc));
	cmpt->path = ft_strcat_proc(text);
	cmpt->fd = open(cmpt->path, O_RDONLY);
	if (cmpt->fd == -1)
	{
		ft_free((void **)&cmpt->path);
		ft_free((void **)&cmpt);
		return (NULL);
	}
	while (1)
	{
		cmpt->status = read(cmpt->fd, cmpt->buff, 4096);
		if (cmpt->status == 0)
			break ;
		if (cmpt->status == -1)
		{
			ft_free((void **)&cmpt->path);
			ft_free((void **)&cmpt);
			return (NULL);
		}
		ft_string_map(&str_maps, cmpt->buff);
		count_read +=cmpt->status;
	}
	printf("-----------------------str_maps-------------\n");
	close(cmpt->fd);
	ft_free((void **)&cmpt->path);
	ft_free((void **)&cmpt);
	return (str_maps);
}
void	ft_linkparser(unsigned int pid)
{
	char	*ptr;
	char	*result;
	ptr = ft_itoa(pid);
	if (ptr == NULL)
		return ;
	result = ft_parser_maps(ptr);
	printf("%s \n",result);
	ft_free((void **)&ptr);
	ft_free((void **)&result);
}
/*
int main()
{
	ft_linkparser(2477);
	return (0);
}
*/
