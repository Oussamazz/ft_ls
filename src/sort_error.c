
#include "../includes/ft_ls.h"

char	**get_errors(char **arr, int no_paths, t_arg **tab)
{
	int			i;
	int			j;
	char		**ret;
	char		*err_msg;
	struct stat sb;

	i = 0;
	j = 0;
	if (!(ret = (char **)ft_memalloc(sizeof(*ret) * (no_paths + 1))))
		return (NULL);
	while (i < no_paths)
	{
		if (lstat(arr[i], &sb) == -1)
		{
			err_msg = strerror(errno);
			ret[j] = ft_strjoin_four("ft_ls: ", arr[i], ": ", err_msg);
			j++;
		}
		i++;
	}
	ret[j] = NULL;
	return (ret);
}
