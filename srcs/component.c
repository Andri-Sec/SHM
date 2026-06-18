#include <limits.h>
#include "../includes/shm_scanner.h"

void	ft_strcpy_mem(char **dst, char *src)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(*dst);
	len_src = ft_strlen(src);
	if (!src)
		return ;
	i = 0;
	while (i < len_src)
	{
		*(*dst + (len_dst + i)) = src[i];
		i++;
	}
	*(*dst + (len_dst + len_src)) = '\0';
}

char	*ft_strdup(char *src)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (src == NULL)
		return (NULL);
	dst = (char *)malloc((strlen(src) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (src[i])
	{
		dst[i] = *(src + i);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	ft_intlen(unsigned int nbr)
{
	size_t i;

	i =	0;
	while (0 < nbr)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

char	*ft_itoa(unsigned int  nbr)
{
	char	*new;
	int	i;

	i = ft_intlen(nbr);
	if ( nbr == 0)
		return(ft_strdup("0"));
	//if (nbr >= 4294967295)
	//	return (NULL);
	new = malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	new[i] = '\0';
	i = i - 1;
	while (0 < nbr )
	{
		new[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	return(new);
}
