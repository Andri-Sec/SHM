#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../includes/shm_scanner.h"

void	ft_catcher(t_context **content, void *value, char *ar)
{
	t_context	*ctx;

	ctx = *content;
	if ((content == NULL) && (*content == NULL) && (ar == NULL))
		return ;
	if (ft_findstr(ar, "--target") == 0)
	{
		ctx->pid = ft_atoi((char *)value);
	}
	if (ft_findstr(ar, "--pattern") == 0)
	{
		ctx->pattern = (char *)value;
	}
	if (ft_findstr(ar, "--thread") == 0)
	{
		ctx->num_threads = ft_atoi((char *)value);
	}
	if (ft_findstr(ar, "--filter") == 0)
	{
		ctx->filter_perms = (char *) value;
	}
}

ssize_t	ft_verifier(t_context *content)
{
	if (!content->pid)
	{
		return (-1);
	}
	if (!content->pattern)
	{
		return (-1);
	}
	return (0);
}

int	main(int arc, char **arv)
{
	size_t		i;
	size_t		j;
	ssize_t		status;
	char		*table[4];
	t_context	*ctx_param;

	i = 1;
	ctx_param = (t_context *) malloc(sizeof(t_context));
	ctx_param->is_hex = 1;
	table[0] = "--target";
	table[1] = "--pattern";
	table[2] = "--thread";
	table[3] = "--filter";
	if (arc >= 3)
	{
		while (*(arv + i))
		{
			if (i < (size_t) arc)
			{
				j = 0;
				while (j < 5)
				{
					status = ft_findstr(*(arv + i), "--hex");
					if (status == 0)
					{
						ctx_param->is_hex = 0;
						i -= 1;
						printf("ok hex\n");
						break ;
					}
					else
					{
						status = ft_findstr(*(arv + i), *(table + j));
						if (status == 0)
						{
							ft_catcher(&ctx_param, *(arv + (i + 1)), table[j]);
							break ;
						}
					}
					j++;
				}
				i += 2;
			}
			else
				break ;
		}
		status = ft_verifier(ctx_param);
		if (status == 0)
		{
			printf("ok structure \n");
			ft_linkparser(ctx_param->pid);
		}
		else
		{
			printf("erreur structure\n");
			ft_print_form();
			return (status);
		}
	}
	else
	{
		printf("invalide arguments please verify your argument parameter\n");
		return (1);
	}
	
	printf("successfully \n");
	free(ctx_param);
	return (0);
}
