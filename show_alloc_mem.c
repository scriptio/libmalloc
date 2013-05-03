/*
** show_alloc_mem.c for malloc in /Users/scalp/projs/c/malloc
**
** Made by anthony scalisi
** <scalisia@gmail.com>
**
** Started on  Wed May  1 20:09:40 2013 anthony scalisi
** Last update Fri May  3 13:45:28 2013 anthony scalisi
*/

#include	"malloc.h"

extern chunks_t	*start_mem;
extern chunks_t	*current_mem;
extern chunks_t	*end_mem;
extern void	*h_free[HASH_FREE];

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }

}

void	my_putnbr_base(long nbr, char *base)
{
  int	base_size;
  int	q;

  if (nbr < 0)
    {
      nbr *= -1;
      my_putchar('-');
    }
  for (base_size = 0; base[base_size] != 0; base_size++);
  if ((q = (nbr / base_size)) != 0)
    my_putnbr_base(q, base);
  my_putchar(base[nbr % base_size]);
}

void			show_alloc_mem()
{
  chunks_t		*pchunk;
  chunks_t		*fchunks;
  int			i;

  my_putstr("------------------------------------------\n");
  my_putstr("Star mem = ");
  my_putnbr_base((long) start_mem, B10);
  for (pchunk = start_mem;
       (void *) ((char *) pchunk) != current_mem;
       pchunk = (chunks_t *) ((char *) pchunk + pchunk->size))
    {
      my_putstr("\nDebut Maillon : ");
      my_putnbr_base((long) pchunk, B10);
      my_putstr("\nS Size : ");
      my_putnbr_base(pchunk->size, B10);
      my_putchar('\n');
      my_putstr("\nADDR send back to user: ");
      my_putnbr_base((long) ((char *) pchunk + DEFAULT_CHUNK_SIZE), B10);
    }
  my_putstr("\nCurrent mem = ");
  my_putnbr_base((long) current_mem, B10);
  my_putstr("\n->> FREE\n");
  for (i = 0; i < 128; i++)
    {
      if (h_free[i] != NULL)
	{
	  my_putstr("\nh_free[");
	  my_putnbr_base(i, B10);
	  my_putstr("]: ");
	  for (fchunks = (chunks_t *) h_free[i]; fchunks != NULL; fchunks = fchunks->next)
	    {
	      my_putnbr_base((long) fchunks, B10);
	      my_putstr(" - ");
	    }
	  my_putchar('\n');
	}
    }
  my_putstr("<<- END FREE\n");
  my_putstr("\n------------------------------------------\n");
}
