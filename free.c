/*
** free.c for malloc in /Users/scalp/projs/c/malloc
**
** Made by anthony scalisi
** <scalisia@gmail.com>
**
** Started on  Wed May  1 20:09:40 2013 anthony scalisi
** Last update Fri May  3 13:45:28 2013 anthony scalisi
*/

#include	"malloc.h"

extern void	*h_free[HASH_FREE];

void		free(void *ptr)
{
  chunks_t	*fchunks;
  int		pos;

  fchunks = (void *) ((char *) ptr - DEFAULT_CHUNK_SIZE);
  pos = fchunks->size % HASH_FREE;
  if (h_free[pos] == NULL)
    {
      h_free[pos] = (void *) fchunks;
      fchunks->previous = NULL;
    }
  else
    {
      chunks_t	*temp_chunks;

      for (temp_chunks = h_free[pos]; temp_chunks->next != NULL;
	   temp_chunks = temp_chunks->next)
	;
      temp_chunks->next = fchunks;
      fchunks->previous = temp_chunks;
    }
  fchunks->next = NULL;
}
