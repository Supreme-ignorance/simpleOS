#include "translator.h"
#include "Device_Driver.h"


#define LARGE_A 		65
#define SMALL_A 		97

#define ALPHABET_SIZE 	26


char* letters[][ALPHABET_SIZE] = {
		{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
		".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
		"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."},

		{"z", "Y", "x", "W", "v", "U", "T", "¤©", "r",
		"Q", "p", "0", "n", "M", "l", "k", "j", "I",
		"¤¿¤Ó", "g", "F", "E", "d", "C", "b", "4"},

		{"¾Æ", "¤²-", "¤¶-", "¤§-", "¤Ó¤Ó", "¾Æ¤½", "¤¸-", "¤À¤º", "¤¿¤Ó¤·",
		"¤¸¤Ã", "¤»¤·", "¤©", "¤±", "¤·¤¤", "¤¤¤¤", "¤¼", "¤¾¤©", "¤»¤»",
		"–í", "¤¼¤¼", "¤Ð¤Ì", "¤³", "¤¨", "¤µ¤µ", "¤¿¤Ç", "¾Æ"},

		{"0x61", "0x62", "0x63", "0x64", "0x65", "0x66", "0x67", "0x68", "0x69",
		"0x6a", "0x6b", "0x6c", "0x6d", "0x6e", "0x6f", "0x70", "0x71", "0x72",
		"0x73", "0x74", "0x75", "0x76", "0x77", "0x78", "0x79", "0x7a"},
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
