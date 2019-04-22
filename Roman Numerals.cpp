/****************
*				*
*	Baran Kaya	*
*	  -2019-	*
*****************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include <conio.h>

using namespace std;

// Function prototypes
void decimalToRoman(int);
void romanToDecimal(string roman);
int doesContain(int number, int decimal);

// Main function
int main(){
	
	int selection = 1;
	int number = 0;
	string numberStr{ 0 };
	string roman{ 0 };

	int currentCharacter;
	
	while(selection != 0){
		system("cls");
		
		cout << "Enter 1 to Number to roman Numeral," <<
		endl << "Enter 2 to roman Numeral to Number," <<
		endl << "Enter 0 to terminate: ";
		
		/*Sudden convert method in conio.h library
		currentCharacter = _getch();
		cout << (char)currentCharacter;*/
		
		// Get user's choice
		cin >> selection;
		
		if(selection == 0)
			return 0;
			
		else if(selection == 1){
			cout << "Enter a number: " << endl;
			
			// Reset current character for _getch function
			currentCharacter = '\0';

			// Finish with enter button
			while(currentCharacter != 13){
				// Reset the number in every loop
				number = 0;
				
				// Get inputs from user
				currentCharacter = _getch();
				
				// Convert string to integer
				numberStr += (int)currentCharacter;
				
				// It adds unneccesary character in the beginnig. Remove it
				if(numberStr[0] == '\0'){
					numberStr = numberStr.substr(1);
				}
				
				// Print user's input
				cout << numberStr << ": ";
				
				// Ascii to integer
				number += stoi(numberStr);
				//number += (int)currentCharacter - '0';
				
				// Call function, it prints its result
				decimalToRoman(number);
				cout << endl;
			}
		}
		
		else if(selection == 2){
			cout << "Enter a roman numeral: " << endl;
			
			// Reset current character for _getch function
			currentCharacter = '\0';

			// Finish with enter button
			while(currentCharacter != 13){
				// Get inputs from user
				currentCharacter = _getch();
				
				// Add new character into the roman string
				roman += (char)currentCharacter;
				
				// It adds unneccesary character in the beginnig. Remove it
				if(roman[0] == '\0'){
					roman = roman.substr(1);
				}
					
				// Print user's input
				cout << roman << ": ";
				
				// Call function, it prints its result
				romanToDecimal(roman);
				cout << endl;
			}

		}

		cout << endl;	
	}
	return 0;
}

// Decimal to romen number function
void decimalToRoman(int number){
	
	if(number >= 1000){
		int numberOfThousands = (number / 1000);
		
		for(int i=0; i<numberOfThousands; i++)
			cout << "C";
	}
	
	if(number >= 100){
		int numberOfHundreds = (number % 1000) / 100;
	
		for(int i=0; i<numberOfHundreds; i++)
			cout << "M";
	}
	
	if(number >= 10){
		int numberOfTens = (number % 100) / 10;
		
		if(numberOfTens >= 5){
			cout << "L";
			for(int i=0; i<(numberOfTens - 5); i++)
				cout << "X";
			
		}else{
			for(int i=0; i<numberOfTens; i++)
				cout << "X";
		}
	}

	switch(number % 10){
		case 1:
			cout << "I";
			break;
		case 2:
			cout << "II";
			break;
		case 3:
			cout << "III";
			break;
		case 4:
			cout << "IV";
			break;
		case 5:
			cout << "V";
			break;
		case 6:
			cout << "VI";
			break;
		case 7:
			cout << "VII";
			break;
		case 8:
			cout << "VIII";
			break;
		case 9:
			cout << "IX";
			break;
		default:
			cout << "_";
			break;
	}
		
}

// Roman number to decimal function
void romanToDecimal(string roman){
	
	int number = 0;
	int numOfIs = 0;	// User can use max 3 I characters
	int numOfVs = 0;	// User can use max 1 V character
	int lenght = roman.length();

	for(int i=0; i<lenght; i++){
		
		switch(roman[i]){
			case 'C':
			case 'c':
				number += 1000;
				break;
			case 'M':
			case 'm':
				number += 100;
				break;
			case 'L':
			case 'l':
				number += 50;
				break;
			case 'X':
			case 'x':
				number += 10;
				break;
			case 'V':
			case 'v':
				numOfVs++;
				// Check number of V's
				if(numOfVs > 1){
					cout << "Romen number cannot have more than 1 V.";
					return;
				}
				number += 5;		
				break;
			case 'I':
			case 'i':
				numOfIs++;
				// Check number of I's
				if(numOfIs > 3){
					cout << "Romen number cannot have more than 3 I.";
					return;
				}
				number += 1;
				// In case of IV and IX --> decrease the number by 2
				if(roman[i+1] == 'V' || roman[i+1] == 'v' || roman[i+1] == 'X' || roman[i+1] == 'x'){
					number -= 2;
				}
				break;
			default:
				cout << "Incorrect character in romen number" << endl;
				return;
		}		
	}	
	cout << number;	
}

// Check for 10x numbers. If it contains return number of decimal
int doesContain(int number, int decimal){
	int result = 0;
	
	if(number >= decimal){
		int numberOfDecimal = (number % (decimal * 10 )) / decimal;
		
		result += numberOfDecimal;
	}
	
	return result;
}


