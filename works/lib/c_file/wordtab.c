#include "../h_file/mouli.h"

int		count_words(char *str, char sep)
{
  int		words;
  int		i;

  i = -1;
  words = 0;
  while (str[++i] != '\0')
    if ((str[i] != sep && str[i] != '\t') &&
	(str[i + 1] == sep || str[i + 1] == '\t' || str[i + 1] == '\0'))
      ++words;
  return (words);
}

int		my_wordlen(char *str, int *i, char sep)
{
  int		j;

  j = 0;
  while (str[++*i] != '\0')
    if (str[*i] != sep && str[*i] != '\t')
      {
	++j;
	if (str[*i + 1] == sep || str[*i + 1] == '\t' || str[*i + 1] == '\0')
	  return (j);
      }
  return (-1);
}

char		*my_wordcpy(char *tab, char *str, int *i, char sep)
{
  int		j;

  j = -1;
  while (str[++*i] != '\0')
    if (str[*i] != sep && str[*i] != '\t')
      {
	tab[++j] = str[*i];
	if (str[*i + 1] == sep || str[*i + 1] == '\t' || str[*i + 1] == '\0')
	  {
	    tab[++j] = '\0';
	    return (tab);
	  }
      }
  return (NULL);
}

char		**my_wordtab(char **tab, char *str, char sep)
{
  int		words;
  int		i;
  int		j;
  int		k;

  i = -1;
  j = -1;
  k = -1;
  if (str == NULL)
    return (NULL);
  words = count_words(str, sep);
  if ((tab = malloc(sizeof(char *) * (words + 1))) == NULL)
    return (NULL);
  while (++i < words)
    {
      if ((tab[i] = malloc(sizeof(char) * (my_wordlen(str, &j, sep) + 1)))
	  == NULL)
	return (NULL);
      tab[i] = my_wordcpy(tab[i], str, &k, sep);
    }
  tab[i] = NULL;
  return (tab);
}
