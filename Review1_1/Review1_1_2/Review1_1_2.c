#include <stdio.h>
#include <string.h>
void reverse_string(char *str, int s, int e)
{
	int i;
	char tmp;

	for(i = s; i <= e/2; i++)
	{
		tmp = str[i];
		str[i] = str[e-i];
		str[e-i] = tmp;
	}
}

int main()
{
	char str[100];

	printf("Enter any string: ");
	scanf("%s", str);

	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);
	return 0;
}