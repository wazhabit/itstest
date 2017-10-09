#include "../h_file/mouli.h"

DIR* open_directory(const char *path)
{
  DIR* open;
  if ((open = opendir(path)) == NULL)
    return (NULL);
  else
    return (open);
}

int try_name_syntaxe(char *s)
{
  int i;

  i = 0;
  while (s[i])
    {
      if (i == 0)
	{
	  if (s[i] < 65 || s[i] > 90)
	    return (1);
	}
      else
	{
	  if (s[i] < 97 || s[i] > 122)
	    return (1);
	}
      i++;
    }
  return (0);
}

int try_syntaxe_file(char **tab, char **syntaxe)
{
  int i;
  int j;
  int k;

  i = 0;
  j = 0;
  k = 0;
  while (tab[i + 1])
    {
      if (i < 2)
	{
	  if (try_name_syntaxe(tab[i]) == 1)
	    return (1);
	}
      else
	{
	  if (my_strcmp(tab[i], syntaxe[i - 2]) == 1)
	    return (1); 
	}
      i++;
    }
  return (0);
}

char *result_to_str(char *s, char *name, char *s2)
{
  char *res;

  res = malloc(1 * sizeof(char));
  res[0] = '\0';
  res = my_add_str_to_str(res, s);
  res = my_add_str_to_str(res, " ");
  res = my_add_str_to_str(res, name);
  res = my_add_str_to_str(res, " ");
  res = my_add_str_to_str(res, s2);
  my_putstr(res);
  return (res);
}

void move_my_file(char *path, char *name, char *valid)
{
  char *end_path;

  end_path = malloc(1);
  end_path[0] = '\0';
  end_path = my_add_str_to_str("mv ", path);
  end_path = my_add_str_to_str(end_path, name);
  end_path = my_add_str_to_str(end_path, " ");
  end_path = my_add_str_to_str(end_path, path);
  end_path = my_add_str_to_str(end_path, valid);
  system(end_path);
}

char *files_status(DIR* open, char **syntaxe, char *direct)
{
  struct dirent* file;
  char **tab_name;
  char *file_result;
  int i;
  FILE *result;

  i = 0;
  file = NULL;
  while((file = readdir(open)) != NULL)
    {
      if (my_strcmp(file->d_name, ".") == 1 && my_strcmp(file->d_name, "..") == 1
	  && my_strcmp(file->d_name, "valid") == 1 && my_strcmp(file->d_name, "unvalid"))
	{
	  tab_name = my_wordtab(tab_name, file->d_name, '_');
	  if (try_syntaxe_file(tab_name, syntaxe) == 1)
	    move_my_file(direct, file->d_name, "unvalid");
	  else
	    move_my_file(direct, file->d_name, "valid");
	  i++;
	}
    }
  if (i == 0)
    my_putstr("There is nothing in the direcotory .. \n");
}

void create_directory(char *path)
{
  char *valid;
  char *unvalid;

  valid = malloc(1);
  unvalid = malloc(1);
  valid[0] = '\0';
  unvalid[0] = '\0';
  valid = my_add_str_to_str("mkdir ", path);
  unvalid = my_add_str_to_str("mkdir ", path);
  valid = my_add_str_to_str(valid, "valid");
  unvalid = my_add_str_to_str(unvalid, "unvalid");
  system(valid);
  system(unvalid);
}

int start_function(char **argv)
{
  DIR* open;
  char **syntaxe;
  char *direct;

  create_directory(argv[1]);
  direct = malloc(1);
  direct[0] = '\0';
  syntaxe = my_wordtab(syntaxe, argv[2], '_');
  if ((open = open_directory((const char *)argv[1])) != NULL)
    {
      my_putstr("Directory is validate ! Good, continue !\n");
      files_status(open, syntaxe, argv[1]);
      my_putstr("Done !\n Go in the directory, there is 2 new folder !\n");
    }
  else
    my_putstr("Sorry student, directory unvalid .... !\n");
}

int main(int argc, char **argv)
{
  char **tab;

  system("clear");
  if (argc == 3)
    start_function(argv);
  else
    say_me_the_syntaxe_plz();
}
