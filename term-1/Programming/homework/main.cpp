#include "header.h"

int main()  
{
	char* text = getInput();
	char* lastWord = getLastWord(text);

	char currWord[BUFF_SIZE] = "";
	bool isFirstWord = true;
	int currWordLen = 0;
	for (int i = 0; i < BUFF_SIZE; ++i) {
		if (text[i] == ' ' && currWord[0] != '\0')
		{
			currWord[currWordLen] = '\0';
			if (!strEq(currWord, lastWord) && eachLetterAppearsAtLeastTwice(currWord)) 
			{
				if (isFirstWord)
					isFirstWord = false;
				else
					_putch(' ');
				strPrint(currWord);
			}

			// Reset curr word
			currWord[0] = '\0';
			currWordLen = 0;
		}
		else if (text[i] != ' ')
			currWord[currWordLen++] = text[i];
	}

	// Don't forget to free memory
	delete[] text;
	delete[] lastWord;
}