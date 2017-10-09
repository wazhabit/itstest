#include "../h_file/mouli.h"

char *my_add_str_to_str(char *s1, char *s2)
{
  char *res;
  int taille;
  int i;
  int j;

  i = 0;
  j = 0;
  taille = my_strlen(s1) + my_strlen(s2) + 1;
  res = malloc(taille);
  while (s1[i])
    {
      res[i] = s1[i];
      i++;
    }
  while (s2[j])
    {
      res[i] = s2[j];
      j++;
      i++;
    }
  return (res);
}
