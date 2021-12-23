#include <stdio.h>
#include <stdlib.h>
#include "Strings_ex3.h"
#define TXT 1024
#define WORD 30

int main()
{
	char* word=(char*)malloc(WORD*sizeof(char));
	char* txt=(char*)malloc(TXT*sizeof(char));
		if(word==NULL||txt==NULL)
		{
			printf("Memory not allocated.\n");
		}
	int wlen=0;
	int textlen=0;
	int i=0;
	char c;
	int gem=0;
	scanf("%c",&c);
	while(c!=','&&c!='\t'&&c!='\n')
	{
		wlen++;
		*(word+i++)=c;
		scanf("%c",&c);		
	}
	i=0;
	scanf("%c",&c);
	while(c!='~')
	{
		*(txt+i++)=c;	
		scanf("%c",&c);
		textlen++;
	}
	gem=gema(word,wlen);
	printf("Gematria Sequences: ");
	Func1(txt,gem,textlen);
	char* azby1=(char*)malloc(wlen*sizeof(char));
	char* trans1=(char*)malloc(wlen*sizeof(char));
		if(azby1==NULL||trans1==NULL)
		{
			printf("Memory not allocated.\n");
		}
	azba(word,azby1,wlen);
	translate(azby1,trans1,wlen);
	printf("Atbash Sequences: ");
	Func2(txt,azby1,trans1,textlen,wlen);
	printf("Anagram Sequences: ");
	Func3(txt,word,wlen,textlen);
	free(word);
	free(txt);
	return 0;
}