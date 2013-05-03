/*
** common.c for malloc in /Users/scalp/projs/c/malloc
**
** Made by anthony scalisi
** <scalisia@gmail.com>
**
** Started on  Wed May  1 20:09:40 2013 anthony scalisi
** Last update Fri May  3 13:45:28 2013 anthony scalisi
*/

#include	"malloc.h"

int		size_chunk(int size)
{
  int		power;

  size += 8;
  for (power = 16; power < size; )
    power += DEFAULT_CHUNK_SIZE;
  return (power);
}
