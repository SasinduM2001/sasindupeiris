/*

 * File:A#6 (Strings)
 * Author: Sasindu Malwatthage (0303270m@acadiau.ca)
 * Date: 2023/11/20
 * Purpose: This program has let user to select whatever file want. Then open it and count number of words in it, frequency of characters, print reverse of characters each word, let user to search whatever needed, search for any palindrom.
 * There are 6 functions to do these calculations. Each function calculate and produce output as mentioned above. 

*/


//started code- 2023/11/17-3pm
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int frequency(FILE *filehandle);
int wordcount(FILE *filehandle);
int reversesame(FILE *filehandle);
int substring(FILE *filehandle);
int reverse(FILE *filehandle);
char search[15];

int spacecounter;
int wordcounter;

int space;
int main(int argc,char *argv[]){



    FILE *filehandle;
    filehandle= fopen(argv[1],"r");//importing text file

    if(filehandle==NULL)
    {
        printf("Text file open error!!!");
        return 1;//exit with fail
    }
int wcf=wordcount(filehandle);//putting function to a single variable to make easy to call
//calling function
printf("Total of words in the text file is: %d\n",wcf);

for(int j=1;j<30;j++)//seperating outputs
printf("-");
printf("\n");


rewind(filehandle);
int frq=frequency(filehandle);
//calling frequency function
printf("%d\n",frq);


//reverse
rewind(filehandle);
int rev=reverse(filehandle);
rev;

for(int i=1;i<30;i++)
printf("-");//seperating outputs
printf("\n");




//reverse same
rewind(filehandle);
int revsame= reversesame(filehandle);
revsame;


for(int p=1;p<30;p++)//seperating outputs
printf("-");
printf("\n");

//search in file

rewind(filehandle);
int sub=substring(filehandle);
sub;




    fclose(filehandle);//closing file
   return 0;
}






//finished this function-2023/11/18-10am
int wordcount(FILE *filehandle){
    int character;
	int wordcounter=0;
	int word=0;
    while((character=fgetc(filehandle))!=EOF)//reading till end of the file
    {
   if(isspace(character)||character=='\n'||character==','||character=='.')//filtering spaces
	{word=0;}//if character is a space, it count as 0
	 else if(!word)
	 {
	  word=1;//if character is not a space, it count as 1
	  wordcounter=wordcounter+word;//add that value to counter
	 }
}
return wordcounter;
}



//started this function 2023/11/18-10am
int frequency(FILE *filehandle) {
    char character;
    int letter[26] = {0};//array of 26 letters in english
    while ((character = fgetc(filehandle)) != EOF) {
        if (isalpha(character)) {//filtering alphabetic letters
            character = tolower(character);//converting all letters to simple
            letter[character - 'a']++;
        }
    }

    printf("%-10s%-10s\n", "Letter", "Count");//top rows
    for (int i = 0; i < 30; i++) printf("*");//seperating output
    printf("\n");

    for (int i = 0; i < 26; i++) {//printing output of frequency
        printf("%-10c%-10d\n", 'a' + i, letter[i]);
    }
    return 0;
}





//substring search
int substring(FILE *filehandle)
{
  char word[15];
 char *result;

printf("Enter word to search:\n");
        scanf("%14s",search);
         while(fscanf(filehandle,"%14s",word)!=EOF)
                {
                result=strstr(word,search);
	if(result!=NULL)
                {printf("search found!!!\n");
		return 1;
		}}
                printf("Search not found!!!\n");
 return 0;}





//2023/11/19-11 pm-2am
int reverse(FILE *filehandle) {
char word[20];

printf("Reverse of text: \n");
printf("Reverse: ");
 while (fscanf(filehandle,"%19s",word) != EOF) 
{
 int len = strlen(word);
int left = 0;
int right = len - 1;

	while (left < right)
	{
	char temp = word[left];
        word[left] = word[right];
        word[right] = temp;
        left++;
        right--;}

printf(" %s", word);

}
printf(" \n");
    return 0;
}

//2023-11/20-8.45 am-10.00 am
int reversesame(FILE *filehandle)
{
	char word[20];
	while(fscanf(filehandle,"%19s",word)!=EOF)//putting words in text to word string(1 space for null character)
	{

	 int i=0;
	 int h=strlen(word)-1;
	 while(h>i)
	  { if(word[i++]==word[h--])//if original word = reversed word
	 	 printf("%s is a palindrome.. \n",word);
	
}}
printf("No Palindrome words!!!\n");


	

	return 0;
}




