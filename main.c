#include <stdio.h>

int	main()
{
	char	cara = 'i';
	char	*str = "salut c'est moi";
	void	*ptr = str;
	int	ford = 42;
	unsigned	foru = 55;
	unsigned	forx = 15;
	unsigned	forX = 15;
	char	*str0 = NULL;
	void	*ptr0 = NULL;

	ft_printf("PREMIERE PARTIE\n\n");
	
	ft_printf("Ma fonction test suite :\n");
	ft_printf("%c\n%s\n%p\n%d\n%u\n%x\n%X\n%%", cara, str, ptr, ford, foru, forx, forX);
	printf("La vraie fonction test suite :\n");
	printf("%c\n%s\n%p\n%d\n%u\n%x\n%X\n%%", cara, str, ptr, ford, foru, forx, forX);
	
	ft_printf("\n\nDEUXIEME PARTIE\n\n");
	
	ft_printf("%d\n", ft_printf("moi + %s", str));
	printf("%d\n", printf("moi + %s", str));

	ft_printf("TROISIEME PARTIE\n\n");
	
	ft_printf("%s\n", str0);
	ft_printf("%p\n", ptr0);
	printf("%s\n", str0);
	printf("%p\n", ptr0);
}

