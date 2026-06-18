#ifndef SHM_SCANNER_H
# define SHM_SCANNER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/types.h>

typedef struct s_segment
{
	unsigned long	start;
	unsigned long	end;
	char			perms[5];
	char			name[256];
}	t_segment;

typedef struct s_task
{
	unsigned char	*pattern;
	t_segment		segment;
	size_t			pattern_len;
	int				is_hex;
}	t_task;

typedef struct s_match
{
	unsigned long	address;
	char			segment_name[256];
	int				pid;
}	t_match;

typedef struct s_task_queue
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	t_task			*task;
	size_t			size;
	size_t			index;
}	t_task_queue;

typedef struct s_context
{
	pthread_mutex_t	result_mutex;
	t_match			*results;
	int				pid;
	char			*pattern;
	int				is_hex;
	int				num_threads;
	char			*filter_perms;
	size_t			result_count;
}	t_context;

typedef struct s_lenstr
{
	size_t	len_front;
	size_t	len_end;
	size_t	len_str;
}	t_lenstr;

typedef struct s_proc
{
	ssize_t	status;
	char 			*path;
	char				buff[4096];
	int					fd;
}	t_proc;

// utils.c
size_t	ft_strlen(char *str);
void	ft_print_form(void);
void	ft_free(void **data);
ssize_t	ft_findstr(char *s1, char *s2);
int		ft_atoi(char *str);
//parser.c
char	*ft_strcat_proc(char *str);
void 	ft_string_map(char **str_dst, char *src);
char	*ft_parser_maps(char *text);
void	ft_linkparser(unsigned int pid);
//component.c
void	ft_strcpy_mem(char **dst, char *src);
char	*ft_strdup(char *src);
//static	int	ft_intlen(unsigned int nbr);
char	*ft_itoa(unsigned int nbr);
#endif
