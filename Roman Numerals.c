#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void romannumerals(int);
void romantonumber(char* roman);

int main(){
	
	int selection = 1;
	int number;
	char roman[100] = { 0 };

	
	while(selection != 0){
		
		printf("Enter 1 to Number to roman Numeral,\nEnter 2 to roman Numeral to Number,\nEnter 0 to terminate: ");
		scanf("%d", &selection);
		
		if(selection == 0)
			return 0;
		else if(selection == 1){
			printf("Enter a number: \n");
			scanf("%d", &number);
			
			romannumerals(number);
		}
		
		else if(selection == 2){
			printf("Enter a roman numeral: \n");
			scanf("%s", roman);
			
			romantonumber(roman);
		}
		
		puts(" ");
	}
	
	return 0;
}

//Decimal to romen number
void romannumerals(int number){
	
	int i;
	
	if(number < 1000){
		int hundredn = (number%1000)/100;
		
		for(i=0; i<hundredn; i++)
			printf("M");
		
		int tenn = (number%100)/10;
		
		if(tenn >= 5){
			
			printf("L");
			for(i=0; i<(tenn-5); i++)
				printf("X");
			
		}else{
			
			for(i=0; i<tenn; i++)
				printf("X");
		}
	
	
	if(number % 10 == 1)
		printf("I");
	else if(number % 10 == 2)
		printf("II");
	else if(number % 10 == 3)
		printf("III");
	else if(number % 10 == 4)
		printf("IV");
	else if(number % 10 == 5)
		printf("V");
	else if(number % 10 == 6)
		printf("VI");
	else if(number % 10 == 7)
		printf("VII");
	else if(number % 10 == 8)
		printf("VIII");
	else if(number % 10 == 9)
		printf("IX");
	}
		
}

//Roman number to decimal
void romantonumber(char *roman){
	
	int i;
	int number = 0;
	int lenght = strlen(roman);

	for(i=0; i<lenght; i++){
		if(roman[i] == 'C' || roman[i] == 'c')
			number += 1000;
		else if(roman[i] == 'M' || roman[i] == 'm')
			number += 100;
		else if(roman[i] == 'L' || roman[i] == 'l')
			number += 50;
		else if(roman[i] == 'X' || roman[i] == 'x')
			number += 10;
		else if(roman[i] == 'V' || roman[i] == 'v')	
			number += 5;	
		else if(roman[i] == 'I' || roman[i] == 'i'){
			
			number += 1;
			
			if(roman[i+1] == 'V' || roman[i+1] == 'v' || roman[i+1] == 'X' || roman[i+1] == 'x')
				
				number -= 2;
		}
			
	}
	
	printf("%d\n", number);
	
}
