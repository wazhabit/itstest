#include "../h_file/mouli.h"

void my_putchar(char c)
{
  write(1, &c, 1);
}

void my_putstr(char *str)
{
  int i;
  
  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void my_puttab(char **tab)
{
  int i;
  
  i = 0;
  while(tab[i + 1] != 0)
    {
      my_putstr("Tableau au rang : ");
      my_putnbr(i);
      my_putchar(' ');
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}

int	my_putnbr(int nb)
{
  int	mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
          nb = (nb - mod) / 10;
	  my_putnbr(nb);
	  my_putchar(48 + mod);
        }
      else
        my_putchar(48 + nb % 10);
    }
}

void say_me_the_syntaxe_plz()
{
  my_putstr("You might give me the 2 arguments I need, you know ..\n\n");
  my_putstr("\tTo recapitulate, my syntaxe is :\n\t./moulinette\tname_of_directory_needed\tname_of_the_basic_file\n\n");
  my_putstr("\t\tName of the directory is something like : ITS1_PC-FUNDAMENTALS\n");
  my_putstr("\t\tName of the basic files is something like : ITS_PC-FUNDAMENTALS.txt\n\n");
  my_putstr("\t\tFor the name I will detect the firstname/lastname alone ;) like : Jean_Bernard_\n\n");
  my_putstr("\t\tDo not forget that : I Just look if the name is include in a <-> z AND A <-> Z and if the syntaxe is correct !!\n");
  my_putstr("\t\tso not that : écrire\n");
  my_putstr("I'll work with a unzip directory !\n");
}

