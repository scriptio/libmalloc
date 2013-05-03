/*
** malloc.h for malloc in /Users/scalp/projs/c/malloc
**
** Made by anthony scalisi
** <scalisia@gmail.com>
**
** Started on  Wed May  1 20:09:40 2013 anthony scalisi
** Last update Fri May  3 13:45:28 2013 anthony scalisi
*/

#ifndef __MY_MALLOC__
#define __MY_MALLOC__

#include	<unistd.h>

#define B10 "0123456789"
#define B16 "0123456789ABCDEF"
#define DEFAULT_MEM_SIZE 4096
#define DEFAULT_CHUNK_SIZE 4
#define HASH_FREE 128
#define __UNUSED__ __attribute__ ((unused))

typedef	struct		chunks_s
{
  size_t		size;
  struct chunks_s	*previous;
  struct chunks_s	*next;
}			chunks_t;

void	*malloc(unsigned int size);
void	free(void *ptr);
void	*realloc(void *ptr, unsigned int size);
void	show_alloc_mem();
int	size_chunk(int size);
void	init_hash();
void	my_putnbr_base(long nbr, char *base);
void	my_putstr(char *str);
void	my_putchar(char c);

#endif
