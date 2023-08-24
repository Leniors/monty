#include "monty.h"

/**
 * is_integer - checks if a string is an int
 */
bool is_integer(const char *str) {
	int i = 0;
	
	if (str == NULL || strlen(str) == 0)
	{
		return false;
	}
	
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			return false;
		}
		i++;
	}
	return true;
}
