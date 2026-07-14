// argv[1]
// argv[i]


/*
    primeiro fazer validacao para varios args ex. ./push_swap -1 2 3 4 5 6
    depois fazer para so um arg ex. ./push_swap "1 2 3 4 5 6"

            ITS PSEUDO CODIGO TIMEEEEEEEEEEEEEEEEEEEEEEEEEE


            negative and/or positive numbers
                without any duplicate

        IF ARGS == "./push_swap" "1 2 3 4 5 6"
        que 'e igual a:
            argc == 2
                vai fazer algo que nao 'e para agora
        
        IF NOT THAT AND ARGC > 2
            WILLLL CHECK THE STINGS FOR JUST NUMBERSSSS

            string = "+12"
            if primeira posicao da string == + ou a - i++;
            depois se voltar a aparecer algum + ou - 'e erro

        podes ter uma funcao que valida uma string e essa funcao 'e chamada uma ver por cada argumento
        ex:
        while i < argc
        {
            funcao(argv[i]);
            i++;
        }

*/

/*
    funcao para verificar se a string que receber
    e ver se so tem +- e numeros e verificar se o + e - esta na localizacao correta
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//begining of split
static int	words_enumerator(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*word_splitter(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *) malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**revolucion(char **words, int j)
{
	while (j >= 0)
	{
		free(words[j]);
		j--;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**words;

	i = 0;
	j = 0;
	words = (char **) malloc(sizeof(char *) * (words_enumerator(s, c) + 1));
	if (!words || !s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			words[j] = word_splitter(&s[i], c);
			if (!words[j])
				return (revolucion(words, j));
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	words[j] = 0;
	return (words);
}
// end of split
int check_string(char *str)
{
    int i = 0;

    // if (!str)
    //     return (write(1, "empty", 5), 0);
    printf ("str: %s\n", str);
    if (str[i] == '-' || str[i] == '+')
        i++;    
    while (str[i] != '\0')
    {
        if (str[i] > 47 && str[i] < 58)
            i++;
        else
            return ((write(1, "not numeric", 11), 0));
    }
    return (1);
}
void    free_split(char **numbers)
{
    int i = 0;
    while (numbers[i])
    {
        free(numbers[i]);
        i++;
    }
    free(numbers);
}

int check_split(char *str)
{
    char **numbers;
    numbers = ft_split(str, ' ');
    int i = 0;
    if (numbers[i] == NULL)
        return (printf("error\n"), free_split(numbers), 0);
    while (numbers[i] != NULL)
    {
            if (check_string(numbers[i]) == 0)
                return (printf("error\n"), free_split(numbers), 0);
            i++;
    }
    return (free_split(numbers), 1);
}

int main(int arc, char **arv)
{
    int i = 1;

    if (arc < 2)
        return (0);
    if (arc == 2)
    {
       if (check_split(arv[i]) == 0)
            return (0);
    }
    if (arc > 2)
    {
        while (i < arc){
            printf("i: %d | argc: %d\n", i, arc);
            if (check_string(arv[i]) == 0)
                return (0);
            i++;
        }
    }        
}
// deals with empty strings/spaces, non numeric chars, signal in wrong place,one or multiple arguments;
// missing duplicate values, bigger than a 32 bits int