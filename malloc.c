/*
** malloc.c for malloc in /Users/scalp/projs/c/malloc
**
** Made by anthony scalisi
** <scalisia@gmail.com>
**
** Started on  Wed May  1 20:09:40 2013 anthony scalisi
** Last update Fri May  3 13:45:28 2013 anthony scalisi
*/

#include	<string.h>
#include	"malloc.h"

chunks_t	*start_mem;
chunks_t	*current_mem;
chunks_t	*end_mem;
void		*h_free[HASH_FREE];

static void	replace_break()
{
  long		csize;
  long		esize;
  int		count;

  csize = (long) current_mem;
  esize = (long) end_mem;
  for (count = 0; esize <= csize; count++)
    esize += DEFAULT_MEM_SIZE;
  sbrk(count * DEFAULT_MEM_SIZE);
  end_mem = sbrk(0);
}

void		init_hash()
{
  int		i;

  for (i = 0; i < HASH_FREE; i++)
    h_free[i] = NULL;
}

void		*init_malloc(int c_size)
{
  start_mem = sbrk(DEFAULT_MEM_SIZE);
  end_mem = sbrk(0);
  current_mem = (void *) ((char *) start_mem + c_size);
  start_mem->size = c_size;
  init_hash();
  return ((void *) ((char *) start_mem + DEFAULT_CHUNK_SIZE));
}

void		*find_new_chunk(int c_size, int pos)
{
  chunks_t	*temp;

  for (temp = (chunks_t *) h_free[pos]; temp != NULL; temp = temp->next)
    if (temp->size == (unsigned int) c_size)
      {
	if (temp->previous == NULL && temp->next == NULL)
	  h_free[pos] = NULL;
	else if (temp->previous == NULL)
	  {
	    temp->next->previous = NULL;
	    h_free[pos] = (void *) temp->next;
	  }
	else if (temp->next == NULL)
	  temp->previous->next = NULL;
	else
	  {
	    temp->next->previous = temp->previous;
	    temp->previous->next = temp->next;
	  }
	return ((void *) ((char *)temp + DEFAULT_CHUNK_SIZE));
      }
  return (NULL);
}

void		*malloc(unsigned int size)
{
  int		c_size;
  int		pos;
  static int	pass = 0;
  chunks_t	*rchunk;

  c_size = size_chunk(size);
  if (pass++ == 0)
    return (init_malloc(c_size));
  else
    {
      pos = c_size % HASH_FREE;
      if (h_free[pos] != NULL)
	if ((rchunk = find_new_chunk(c_size, pos)) != NULL)
	  return (rchunk);
      current_mem->size = c_size;
      rchunk = (void *) ((char *) current_mem + DEFAULT_CHUNK_SIZE);
      current_mem = (void *) ((char *) current_mem + c_size);
      if ((char *) end_mem < (char *) current_mem)
	replace_break();
      return (rchunk);
    }
  return (NULL);
}
