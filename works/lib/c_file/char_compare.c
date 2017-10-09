#include "../h_file/mouli.h"

int it_is_a_real_char(char c)
{
	int i;
	
	i = 0;
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	  return (0);
	else
	  return (1);
}

int my_strcmp(char *s1, char *s2)
{
  int i;

  i = 0;
  while (s1[i] || s2[i])
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  if (s1[i] == '\0' && s2[i] != '\0')
    return (1);
  if (s2[i] == '\0' && s1[i] != '\0')
    return (1);
  return (0);
}

int it_is_a_real_name(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
	{
		if (it_is_a_real_char(s[i]) == 1)
			return(1);
		else
			return(0);
	}
}
