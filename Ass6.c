#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int wordCount(FILE *fileHandle);
int characterFrequency(FILE *fileHandle);
char reverse(FILE *fileHandle);
int wordReversal(FILE *fileHandle);
int main(int argc,char *argv[])

{

        FILE *fileHandle;

        if ((fileHandle = fopen(argv[1], "r")) == NULL)
        {
            printf(stderr, "Cant open file %s\n", argv[1]);
	    return EXIT_FAILURE;
       }


	 wordCount(fileHandle);

	 rewind(fileHandle);

	characterFrequency(fileHandle);

	rewind(fileHandle);

	wordReversal(fileHandle);

	fclose(fileHandle);
return 0;
}

int wordCount(FILE *fileHandle)
{
char word;
int count;
	while ((word = fgetc(fileHandle)) != EOF)
	{
	if(isspace(word))
	count++;
	}
	printf("Count of words is: %d\n",count);
return 0;
}


int characterFrequency(FILE *fileHandle)
{

	int array[256] = {0}; //Assuming the alphabet

	char word;
	while((word = fgetc(fileHandle)) != EOF)
	{
		array[word]++;
	}

	printf("character frequency: \n");
	for(int i = 0; i<256; i++)
	{
		if(array[i]>0 && isprint(i))
		{
			printf("%c: %d\n", i, array[i]);
		}
	}
return 0;
}
int wordReversal(FILE *fileHandle){
	printf("reverse of words: ");

	int len;
	int start,end;
	char temp;
	char word[100];
	while(fscanf(fileHandle,word)!=EOF)
	{
	len=strlen(word);
	start=0;
	end=len-1;
	while(start<end)
	{
 	temp=word[start];
	word[start]=word[end];
	word[end]=temp;
	start++;
	end--;}
	printf(" %s",word);}
	printf("\n");
	return 0;
}

