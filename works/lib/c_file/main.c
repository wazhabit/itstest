#include "../h_file/mouli.h"

char *my_addchar(char c, char *s)
{
  char *r;
  int i;

  i = 0;
  r = malloc(my_strlen(s) + 2 * sizeof(char));
  r[my_strlen(s) + 1] = '\0';
  while (s[i])
    {
      r[i] = s[i];
      i++;
    }
  r[i] = c;
  return (r);
}

char *getnextline(int fd)
{
  char *line;
  char reads;
  int end;
  int i;

  i = 0;
  end = 0;
  line = malloc(1 * sizeof(char));
  line[0] = '\0';
  while (end != 1)
    {
      read(fd, &reads, 1);
      if (reads == '\n' || reads == EOF)
	end = 1;
      else
	line = my_addchar(reads, line);
      if (reads == EOF && i == 0)
	return (NULL);
      i++;
    }
  return (line);
}

int main(int argc, char **argv)
{
  int fd;
  char *s;

  fd = open(argv[1], O_RDONLY);
  s = getnextline(fd);
  close(fd);
}
