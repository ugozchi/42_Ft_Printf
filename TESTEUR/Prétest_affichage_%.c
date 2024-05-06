#include <stdio.h>

int	main()
{
	unsigned int	u = 50;
	char	c = 'Y';
	char	*str = "Coucou";
	void	*ptr = &u;
	int	d = 102.99;
	int	i = 100;
	unsigned int	x = 156;
	unsigned int	X = 156;
	unsigned long int	addresse = &u;
	 
	printf("%%c : %c\n", c);
	printf("%%s : %s\n", str);
	printf("%%p : %p\n", ptr);
	printf("Adresse de u : %lu\n", addresse);
	printf("%%d : %d\n", d);
	printf("%%i : %i\n", i);
	printf("%%u : %u\n", u);
	printf("%%x : %x\n", x);
	printf("%%X : %X\n", X);
	printf("%%% : %%\n");
	printf("COUCOU%");
	printf("%");
}
