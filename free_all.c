/*==== HEADER ====*/

#include "ft_ls.h"
void	free_all(ll_list *cur)
{
	free(cur->filename);
	//	free(cur->perm);
	//free(cur->uid);
	free(cur->gid);
	free(cur);
}