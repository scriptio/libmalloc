/*
** realloc.h for malloc in /Users/scalp/projs/c/malloc
**
** Made by anthony scalisi
** <scalisia@gmail.com>
**
** Started on  Wed May  1 20:09:40 2013 anthony scalisi
** Last update Fri May  3 13:45:28 2013 anthony scalisi
*/

#include	<strings.h>
#include	"malloc.h"

extern chunks_t	*start_mem;
extern chunks_t	*current_mem;
extern chunks_t	*end_mem;

void		*realloc(void *ptr, unsigned int size)
{
  chunks_t	*temp;
  void		*nptr;
  int		nsize;

  if (ptr == NULL)
      return (malloc(size));
  if (size == 0)
    {
      free(ptr);
      return (NULL);
    }
  nptr = malloc(size);
  nsize = size_chunk(size);
  temp = (chunks_t *) ((char *) ptr - DEFAULT_CHUNK_SIZE);
  if ((unsigned int) nsize <= temp->size)
    return (ptr);
  bcopy(ptr, nptr, temp->size);
  free(ptr);
  return (nptr);
}
