#include "translator.h"
#include "Device_Driver.h"


#define LARGE_A 		65
#define SMALL_A 		97

#define ALPHABET_SIZE 	26


char* letters[][ALPHABET_SIZE] = {
		{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   // A-I
		".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
		"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}         // S-Z
};


void translation(char* res, char* input, int type)
{
	int i;
	int k;

	for (i = 0, k = 0; input[i]; i++, k++)
	{
		int asciiCode = asciiToInt(input[i]);

		if (asciiCode >= 0)
		{
			int j;
			for (j = 0; letters[type][asciiCode][j]; j++, k++)
			{
				res[k] = letters[type][asciiCode][j];
			}
			k--;
		}
		else
		{
			res[k] = input[i];
		}
	}
}

int asciiToInt(char input)
{
	int code = (int) input;

	if (code >= 65 && code < 91)
	{
		code -= 65;
	} else if (code >= 97 && code < 123)
	{
		code -= 97;
	} else
	{
		code = -1;
	}

	return code;
}

void initCharPointer(char* input)
{
	int i;

	for (i = 0; input[i]; i++)
	{
		input[i] = 0;
	}
}
