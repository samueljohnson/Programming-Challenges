#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* erase all content of number after getting any comma or space.*/
int ValidateNumber(char *, char *);

/* convert digits to text in English by specifying
the input parameter*/
void NumberToText(char *, char *); 

//int main()
//{
    //char number[100]; // original number
    //char only_number[100];// only number no extra characters
    //char outputString[2048]; // text holder
	//printf("\nEnter the Number :");
	////scanf("%[^\n]",number);
	//gets(number);
	//fflush(stdin);
	//if(strlen(number) > 66 || strlen(number) == 0)
		//printf("Invalid length of numbers!\n");
	//else 
	//{
		//if(ValidateNumber(number, only_number)) 
		//{
			//NumberToText(only_number, outputString);
			////printf("Number in Text : %s\n",outputString);
			//puts(outputString);
		//}
		//else
			//printf("\n\nInvalid Number !!!\n");
	//}
	//return 0;
//}
/* End of main() */

void NumberToText(char *only_number, char *outputString)
{
    char one_array[10][11] = {
        " ","one ", "two ", "three ", "four ", "five ","six ", "seven ", "eight ", "nine "
	};
    char ten_array[10][11] = {
		"ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", 
		"seventeen ", "eighteen ", "nineteen "
	};
    char twenty_array[10][11] = {
        " "," ","twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "
	};
	char big_unit_array[22][20] = {"vigintillion","novemdecillion","octodecillion","septendecillion",
		                           "sexdecillion","quindecillion","quattuordecillion","tredecillion",
								   "duodecillion","undecillion","decillion","nonillion","octillion",
								   "septillion","sextillion","quintillion","quadrillion","trillion ", 
								   "billion ", "million ", "thousand ", "hundred "};
	const int MaxUnit = 21;
	char tempString[150][20];
	//E.g. 1,234,567,890,123
	int i; //for only_number
	int j; //for tempString
	int rem;
	int sizeofNumber = strlen(only_number);
	int tflag = 0;
	for(i=0,j=0; i<sizeofNumber; i++) 
	{
		rem = (sizeofNumber-i)%3;
		if(!rem)
			tflag = 0;
		if(only_number[i] != '0') 
		{
			if(rem == 1) //in oneth position
			{
                strcpy(tempString[j++],one_array[only_number[i]-48]);
				tflag = 1;
			}
			else if(rem == 2) 
			{ //in tenth position
                if(only_number[i] == '1')
					strcpy(tempString[j++],ten_array[only_number[++i]-48]);
                else
					strcpy(tempString[j++],twenty_array[only_number[i]-48]);
				tflag = 1;
            }
            else if(rem == 0) 
			{// in hundredth position
				strcpy(tempString[j++],one_array[only_number[i]-48]);
				strcpy(tempString[j++],big_unit_array[MaxUnit]);
				tflag = 1;
			}
		}
		if(tflag)
		{
			switch(sizeofNumber-i) 
			{
				//select which big_unit_array to be placed behind the number
			case 64: strcpy(tempString[j++],big_unit_array[MaxUnit-21]); break;
			case 61: strcpy(tempString[j++],big_unit_array[MaxUnit-20]); break;
			case 58: strcpy(tempString[j++],big_unit_array[MaxUnit-19]); break;
			case 55: strcpy(tempString[j++],big_unit_array[MaxUnit-18]); break;
			case 52: strcpy(tempString[j++],big_unit_array[MaxUnit-17]); break;
			case 49: strcpy(tempString[j++],big_unit_array[MaxUnit-16]); break;
			case 46: strcpy(tempString[j++],big_unit_array[MaxUnit-15]); break;
			case 43: strcpy(tempString[j++],big_unit_array[MaxUnit-14]); break;
			case 40: strcpy(tempString[j++],big_unit_array[MaxUnit-13]); break;
			case 37: strcpy(tempString[j++],big_unit_array[MaxUnit-12]); break;
			case 34: strcpy(tempString[j++],big_unit_array[MaxUnit-11]); break;
			case 31: strcpy(tempString[j++],big_unit_array[MaxUnit-10]); break;
			case 28: strcpy(tempString[j++],big_unit_array[MaxUnit-9]); break;
			case 25: strcpy(tempString[j++],big_unit_array[MaxUnit-8]); break;
			case 22: strcpy(tempString[j++],big_unit_array[MaxUnit-7]); break;
			case 19: strcpy(tempString[j++],big_unit_array[MaxUnit-6]); break;
			case 16: strcpy(tempString[j++],big_unit_array[MaxUnit-5]); break;
			case 13: strcpy(tempString[j++],big_unit_array[MaxUnit-4]); break;
			case 10: strcpy(tempString[j++],big_unit_array[MaxUnit-3]); break;
			case 7 : strcpy(tempString[j++],big_unit_array[MaxUnit-2]); break;
			case 4 : strcpy(tempString[j++],big_unit_array[MaxUnit-1]); break;
			}
		}
	}
	j--; 
	//to minus an extra increment of j
	//paste text from tempString to outputString
	strcpy(outputString,tempString[0]);
	for(i=1; i<=j; i++)
		strcat(outputString, tempString[i]);
}
/* End of NumberToText() */

int ValidateNumber(char *number, char *only_number)
{
    char tempString[100]={'\0'};
    int i,j;
    int len = strlen(number);
    for(i=0, j=0; i<len; i++)
	{
		if(isdigit(number[i]))
			tempString[j++] = number[i];
		else
			break;
	}
	strcpy(only_number,tempString);
	return j;
}
/* End of ValidateNumber() */
