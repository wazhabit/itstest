int my_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int my_tablen(char **t)
{
  int i;

  i = 0;
  while(t[i])
    i++;
  return (i);
}

int my_count_char_in_str(char c, char *str)
{
	int res;
	int i;
	
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == c)
			res++;
		i++;
	}
	return (res);
}
