//Andrew Syverson | Memory Game

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>

//Declare all functions
easyMode();
mediumMode();
hardMode();
menu();
letterA();
letterB();
letterC();
letterD();
LetterE();
letterF();
letterG();
letterH();
letterI();
letterJ();
letterK();
num1();
num2();
num3();
num4();
num5();
num6();
num7();
num8();
num9();
menu1();
menu2();
menu3();
void setConsoleSize();
char login();


//main driver function definition
int main() {
	//Set the text color to purple
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	//Prompt the user to login with email and password  - and verify
	login();


	//Start the game
	menu();



}


//Set the console size to be a little larger to fit all of the ascii art for the start up message
void setConsoleSize(int width, int height) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
	COORD size = { width, height };
	SetConsoleScreenBufferSize(hConsole, size);
	SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

//Login function
char login() {
	//Declare variables
	int n = 1;
	char enteredEmail[100] = "";
	char enteredPassword[100] = "";
	char correctEmail[100] = "Asyverson@my.gcu.edu";
	char correctPassword[100] = "Password";
	//Loop that repeats unless the correct email and password is enterered
	while (n = 1) {
		//Prompt the user to enter email and scan input
		printf("\nEnter Email: ");
		scanf_s("%s", &enteredEmail, 100);
		//Prompt the user to enter the password and scan input
		printf("\nEnter Password: ");
		scanf_s("%s", &enteredPassword, 100);
		printf("checking...");
		Sleep(1000);
		//check input using strcmp if correct break the loop
		if (strcmp(enteredEmail, correctEmail) == 0 & strcmp(enteredPassword, correctPassword) == 0) {
			printf("\ninput is correct");
			system("cls");
			break;
		}
		//if incorrect repeat the loop and tell the user to try again
		else {
			printf("\nIncorrect email or password :(\n");
			Sleep(500);
			system("cls");
		}
	}
}



//Main game driving function
menu() {
	//Declare varaibles needed l for infinite while loop - char modeSelect to store user input - char modeE,M,H for mode selection
	char modeSelect[2] = "";
	int l = 1;
	char modeE[] = "E";
	char modeM[] = "M";
	char modeH[] = "H";

	//Tells user to put the console in full screen so ascii start message fully displays
	printf("\nFor the best experience please put the console in full screen.");
	//Wait 2 seconds
	Sleep(2000);
	//clear the screen
	system("cls");

	//Call menu1 - displays ascii start up message
	menu1();
	Sleep(1000);
	system("cls");
	//set the console size to larger for the next message
	setConsoleSize(600, 200);
	menu2();
	Sleep(1000);
	system("cls");
	menu3();
	Sleep(1000);
	system("cls");
	//Now that the start up message has been displayed print the menu
	printf("                                                     Welcome to the Memory Game");
	printf("\n-----------------------------------------------------------------------------------------------------------------------------------");
	printf("\nSELECT MODE!");
	printf("\n-----------------------------------------------------------------------------------------------------------------------------------");
	printf("\n|1. Easy - Enter 'E'|");
	printf("\n|-------------------|--------------------------------------------------------------------------------------------------------------");
	printf("\n|2. Medium Enter 'M'|");
	printf("\n|-------------------|--------------------------------------------------------------------------------------------------------------");
	printf("\n|3. Hard Enter 'H'|");
	printf("\n|-----------------|----------------------------------------------------------------------------------------------------------------");
	

	//infinite loop to keep the game running and sanitize input
	while (l = 1) {
		printf("\n\nEnter Mode 'E' 'M' 'H': ");
		//Scan users input for mode
		scanf_s("%s", modeSelect, 3);
		//if input does match a game mode E enter easyMode();
		if (strcmp(modeSelect, modeE)== 0) {
			printf("Mode E entered");
			printf("\nMake sure to turn caps lock on!");
			Sleep(1000);
			printf("\n\nGood Luck!");
			Sleep(1000);
			system("cls");
			easyMode();
		}
		//if input does match a game mode M enter mediumMode();
		else if (strcmp(modeSelect, modeM) == 0) {
			printf("Mode M entered");
			printf("\nMake sure to turn caps lock on!");
			Sleep(1000);
			printf("\n\nGood Luck!");
			Sleep(1000);
			system("cls");
			mediumMode();
		}
		//if input does match a game mode H enter hardMode();
		else if (strcmp(modeSelect, modeH) == 0) {
			printf("Mode H entered");
			printf("\nMake sure to turn caps lock on!");
			Sleep(1000);
			printf("\nGood Luck");
			Sleep(1500);
			system("cls");
			hardMode();
		}
		//if input does not match a valid game mode restart and make them enter valid game mode
		else {
			printf("INVALID - Enter valid mode");
			Sleep(500);
		}

	}
}
//Generate a random character for easy mode index 
char getRandomChar() {
	//generate a random int 0-6
	int randomIndex = rand() % 6;
	//if randomly generated int is 1-3 return a random character A through D
	if (randomIndex < 4) {
		return 'A' + randomIndex;
	}
	else {
		//if randomly generated int is 4-6 return a random num 1-2
		return '1' + (randomIndex - 4);
	}
}

void displayArray(char* array, int length) {
	for (int i = 0; i < length; i++) {
		printf("%c ", array[i]);
	}
}

easyMode() {
	//Input variables for fail
	char yRestart[5] = "Yes";
	char yesRestart[5] = "YES";
	char yMenu[8] = "menu";
	char yesMenu[8] = "MENU";
	srand(time(NULL));

	int minLength = 1;  // Initial length of the array

	while (1) {
		// Dynamically allocate memory for the array
		char* randomArray = (char*)malloc((minLength + 1) * sizeof(char)); // +1 for null terminator

		// Generating random characters for the array
		for (int j = 0; j < minLength; j++) {
			randomArray[j] = getRandomChar();
		}
		//Iterating through the array and printing the correct ascii character for the character in the array
		for (int x = 0; x < minLength; x++) {
			if (randomArray[x] == 'A') {
				letterA();
				Sleep(1500);
				system("cls");

			}
			else if (randomArray[x] == 'B') {
				letterB();
				Sleep(1500);
				system("cls");

			}
			else if (randomArray[x] == 'C') {
				letterC();
				Sleep(1500);
				system("cls");

			}
			else if (randomArray[x] == 'D') {
				letterD();
				Sleep(1500);
				system("cls");

			}
			else if (randomArray[x] == '1') {
				num1();
				Sleep(1500);
				system("cls");

			}
			else if (randomArray[x] == '2') {
				num2();
				Sleep(1500);
				system("cls");

			}
			else if (randomArray[x] == '3') {
				num3();
				Sleep(1500);
				system("cls");

			}

		}
		randomArray[minLength] = '\0'; // Null-terminate the string


		// Prompt the user for input
		printf("Enter the %d characters you saw: ", minLength);
		char userInput[20]; // Assuming the user won't input more than 20 characters
		scanf_s("%19s", userInput, 20); // Read up to 19 characters to prevent buffer overflow

		// Check if the user input matches the generated array
		//set match to 1
		int match = 1;
		//iterate through the generated array character by character
		for (int i = 0; i < minLength; i++) {
			//compare each character of the generated and inputted array to see if they do not match
			if (userInput[i] != randomArray[i]) {
				//if they don't match set match to 0 and break
				match = 0;
				break;
			}
		}
		//define restart string
		char restart[10];
		//This will only run if match still = 1 and passed the first if check
		if (match) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			printf("Correct!\n");
			Sleep(1000);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			minLength++; // Increase the array length
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			printf("Incorrect. Total score: %d\n", minLength);
			//Display the correct array
			printf("The correct string was: ");
			displayArray(randomArray, minLength);
			printf("\nWant to try again? Type 'yes' to restart - Type 'menu' to return to the menu: ");
			scanf_s("%s", restart, 10);
			if (strcmp(restart, yRestart) == 0) {   //Check if user wants to restart this level check for all input yes and menu all lowercase and all uppercase
				minLength = 1; // Reset array length to minimum
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("Restarting Easy Mode");
			}
			else if (strcmp(restart, yesRestart) == 0) {
				minLength = 1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("Restarting Easy Mode");
			}
			else if (strcmp(restart, yMenu)) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("Returning to Menu");
				menu();
			}
			else if (strcmp(restart, yesMenu)) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("Returning to Menu");
				menu();
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				//anything else returns to menu
				printf("INVALID INPUT...RETURNING TO MENU");
				menu();
			}

		}

		// Free the dynamically allocated memory
		free(randomArray);
	}
}
//Randomly generate character for medium index
char getRandomCharM() {
	//generate random int 0 - 15
	int randomIndex = rand() % 15;
	//if random int is 0-10 return random char A - K
	if (randomIndex < 11) {
		return 'A' + randomIndex;
	}
	else {
		//if random int is 11-15 return random num 1-4
		return '1' + (randomIndex - 11);
	}
}

//medium Mode udf
mediumMode() {
	//Input variables for fail
	char yRestart[5] = "Yes";
	char yesRestart[5] = "YES";
	char yMenu[8] = "menu";
	char yesMenu[8] = "MENU";
	srand(time(NULL));

	int minLength = 1;  // Initial length of the array

	while (1) {
		// Dynamically allocate memory for the array
		char* randomArray = (char*)malloc((minLength + 1) * sizeof(char)); // +1 for null terminator

		// Generating random characters for the array
		for (int j = 0; j < minLength; j++) {
			randomArray[j] = getRandomCharM();
		}
		//Iterate through the array and print the respective ascii art for each char in the array
		for (int x = 0; x < minLength; x++) {
			if (randomArray[x] == 'A') {
				letterA();
				Sleep(1000);
				system("cls");

			}
			else if (randomArray[x] == 'B') {
				letterB();
				Sleep(1000);
				system("cls");

			}
			else if (randomArray[x] == 'C') {
				letterC();
				Sleep(1000);
				system("cls");

			}
			else if (randomArray[x] == 'D') {
				letterD();
				Sleep(1000);
				system("cls");
			}
			else if (randomArray[x] == 'E') {
				letterE();
				Sleep(1000);
				system("cls");
			}
			else if (randomArray[x] == 'F') {
				letterF();
				Sleep(1000);
				system("cls");
			}
			else if (randomArray[x] == 'G') {
				letterG();
				Sleep(1000);
				system("cls");
			}
			else if (randomArray[x] == 'H') {
				letterH();
				Sleep(1000);
				system("cls");
			}
			else if (randomArray[x] == 'I') {
				letterI();
				Sleep(1000);
				system("cls");
			}
			else if (randomArray[x] == 'J') {
				letterJ();
				Sleep(1000);
				system("cls");
			}
			else if (randomArray[x] == 'K') {
				letterK();
				Sleep(1000);
				system("cls");
			}
			else if (randomArray[x] == '1') {
				num1();
				Sleep(1000);
				system("cls");

			}
			else if (randomArray[x] == '2') {
				num2();
				Sleep(1000);
				system("cls");

			}
			else if (randomArray[x] == '3') {
				num3();
				Sleep(1000);
				system("cls");

			}
			else if (randomArray[x] == '4') {
				num4();
				Sleep(1000);
				system("cls");
			}

		}
		randomArray[minLength] = '\0'; // Null-terminate the string

		// Display the array on the screen for 1 second
		//displayArray(randomArray, minLength);

		// Prompt the user for input
		printf("Enter the %d characters you saw: ", minLength);
		char userInput[20]; // Assuming the user won't input more than 20 characters
		scanf_s("%19s", userInput, 20); // Read up to 19 characters to prevent buffer overflow

		// Check if the user input matches the generated array
		int match = 1;
		for (int i = 0; i < minLength; i++) { //Iterate through each entered character and make sure they match
			if (userInput[i] != randomArray[i]) { //if they don't match - match = 0;
				match = 0;
				break;
			}
		}
		char restart[10];
		//match still equals 1
		if (match) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			printf("Correct!\n");
			Sleep(1000);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			minLength++; // Increase the array length
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			printf("Incorrect. Total score: %d\n", minLength);
			//Display the correct array
			printf("The correct string was: ");
			displayArray(randomArray, minLength);
			printf("\nWant to try again? Type 'yes' to restart - Type 'menu' to return to the menu: ");
			scanf_s("%s", restart, 10);
			if (strcmp(restart, yRestart) == 0) {   //Check if user wants to restart this level check for all input yes and menu all lowercase and all uppercase
				minLength = 1; // Reset array length to minimum
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("Restarting Easy Mode");
			}
			else if (strcmp(restart, yesRestart) == 0) {
				minLength = 1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("Restarting Medium Mode");
			}
			else if (strcmp(restart, yMenu)) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("Returning to Menu");
				menu();
			}
			else if (strcmp(restart, yesMenu)) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("Returning to Menu");
				menu();
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				//anything else returns to menu
				printf("INVALID INPUT...RETURNING TO MENU");
				menu();
			}

		}

		// Free the dynamically allocated memory
		free(randomArray);
	}
}

char getRandomCharH() {
	//generate random int 0 - 20
	int randomIndex = rand() % 20;
	//if random int is 0-10 return random char A - K 11
	if (randomIndex < 11) {
		return 'A' + randomIndex;
	}
	else {
		//if random int is 11-15 return random num 1-9
		return '1' + (randomIndex - 11);
	}
}

//medium Mode udf
hardMode() {
	//Input variables for fail
	char yRestart[5] = "Yes";
	char yesRestart[5] = "YES";
	char yMenu[8] = "menu";
	char yesMenu[8] = "MENU";
	srand(time(NULL));

	int minLength = 1;  // Initial length of the array

	while (1) {
		// Dynamically allocate memory for the array
		char* randomArray = (char*)malloc((minLength + 1) * sizeof(char)); // +1 for null terminator

		// Generating random characters for the array
		for (int j = 0; j < minLength; j++) {
			randomArray[j] = getRandomCharH();
		}
		//Iterate through the array and print the respective ascii art for each char in the array
		for (int x = 0; x < minLength; x++) {
			if (randomArray[x] == 'A') {
				letterA();
				Sleep(500);
				system("cls");

			}
			else if (randomArray[x] == 'B') {
				letterB();
				Sleep(500);
				system("cls");

			}
			else if (randomArray[x] == 'C') {
				letterC();
				Sleep(500);
				system("cls");

			}
			else if (randomArray[x] == 'D') {
				letterD();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == 'E') {
				letterE();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == 'F') {
				letterF();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == 'G') {
				letterG();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == 'H') {
				letterH();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == 'I') {
				letterI();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == 'J') {
				letterJ();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == 'K') {
				letterK();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == '1') {
				num1();
				Sleep(500);
				system("cls");

			}
			else if (randomArray[x] == '2') {
				num2();
				Sleep(500);
				system("cls");

			}
			else if (randomArray[x] == '3') {
				num3();
				Sleep(500);
				system("cls");

			}
			else if (randomArray[x] == '4') {
				num4();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == '5') {
				num5();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == '6') {
				num6();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == '7') {
				num7();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == '8') {
				num8();
				Sleep(500);
				system("cls");
			}
			else if (randomArray[x] == '9') {
				num9();
				Sleep(500);
				system("cls");
			}

		}
		randomArray[minLength] = '\0'; // Null-terminate the string

		// Display the array on the screen for 1 second
		//displayArray(randomArray, minLength);

		// Prompt the user for input
		printf("Enter the %d characters you saw: ", minLength);
		char userInput[20]; // Assuming the user won't input more than 20 characters
		scanf_s("%19s", userInput, 20); // Read up to 19 characters to prevent buffer overflow

		// Check if the user input matches the generated array
		int match = 1;
		for (int i = 0; i < minLength; i++) { //Iterate through each entered character and make sure they match
			if (userInput[i] != randomArray[i]) { //if they don't match - match = 0;
				match = 0;
				break;
			}
		}
		char restart[10];
		//match still equals 1
		if (match) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			printf("Correct!\n");
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			system("cls");
			minLength++; // Increase the array length
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			printf("Incorrect. Total score: %d\n", minLength);
			//Display the correct array
			printf("The correct string was: ");
			displayArray(randomArray, minLength);
			printf("\nWant to try again? Type 'yes' to restart - Type 'menu' to return to the menu: ");
			scanf_s("%s", restart, 10);
			if (strcmp(restart, yRestart) == 0) {   //Check if user wants to restart this level check for all input yes and menu all lowercase and all uppercase
				minLength = 1; // Reset array length to minimum
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("Restarting Easy Mode");
			}
			else if (strcmp(restart, yesRestart) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				minLength = 1;
				printf("Restarting Medium Mode");
			}
			else if (strcmp(restart, yMenu)) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("Returning to Menu");
				menu();
			}
			else if (strcmp(restart, yesMenu)) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("Returning to Menu");
				menu();
			}
			else {
				//anything else returns to menu
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("INVALID INPUT...RETURNING TO MENU");
				menu();
			}

		}

		// Free the dynamically allocated memory
		free(randomArray);
	}
}



letterA(){
		printf("\n\n");
        printf("\n               AAA               ");
        printf("\n              A:::A              ");
        printf("\n             A:::::A             ");
        printf("\n            A:::::::A            ");
        printf("\n           A:::::::::A           ");
		printf("\n          A:::::A:::::A          ");
        printf("\n         A:::::A A:::::A         ");
        printf("\n        A:::::A   A:::::A        ");
        printf("\n       A:::::A     A:::::A       ");
        printf("\n      A:::::AAAAAAAAA:::::A      ");
        printf("\n     A:::::::::::::::::::::A     ");
        printf("\n    A:::::AAAAAAAAAAAAA:::::A    ");
        printf("\n   A:::::A             A:::::A   ");
        printf("\n  A:::::A               A:::::A  ");
        printf("\n A:::::A                 A:::::A ");
        printf("\nAAAAAAA                   AAAAAAA\n\n");
                              
                         
}

letterB() {
	printf("\n\n");
	printf("\nBBBBBBBBBBBBBBBBB   ");
	printf("\nB::::::::::::::::B  ");
	printf("\nB::::::BBBBBB:::::B ");
	printf("\nBB:::::B     B:::::B");
	printf("\n  B::::B     B:::::B");
	printf("\n  B::::B     B:::::B");
	printf("\n  B::::BBBBBB:::::B ");
	printf("\n  B:::::::::::::BB  ");
	printf("\n  B::::BBBBBB:::::B ");
	printf("\n  B::::B     B:::::B");
	printf("\n  B::::B     B:::::B");
	printf("\n  B::::B     B:::::B");
	printf("\nBB:::::BBBBBB::::::B");
	printf("\nB:::::::::::::::::B ");
	printf("\nB::::::::::::::::B  ");
	printf("\nB::::::::::::::::B  ");
	printf("\nBBBBBBBBBBBBBBBBB   ");
}

letterC() {
	printf("\n\n");
	printf("\n        CCCCCCCCCCCCC");
	printf("\n     CCC::::::::::::C");
	printf("\n   CC:::::::::::::::C");
	printf("\n  C:::::CCCCCCCC::::C");
	printf("\n C:::::C       CCCCCC");
	printf("\nC:::::C              ");
	printf("\nC:::::C              ");
	printf("\nC:::::C              ");
	printf("\nC:::::C              ");
	printf("\nC:::::C              ");
	printf("\nC:::::C              ");
	printf("\n C:::::C       CCCCCC");
	printf("\n  C:::::CCCCCCCC::::C"); 
	printf("\n   CC:::::::::::::::C");
	printf("\n     CCC::::::::::::C");
	printf("\n        CCCCCCCCCCCCC");
}

letterD() {
	printf("\n\n");
	printf("\nDDDDDDDDDDDDD        ");
	printf("\nD::::::::::::DDD     ");
	printf("\nD:::::::::::::::DD   ");
	printf("\nDDD:::::DDDDD:::::D  ");
	printf("\n  D:::::D    D:::::D ");
	printf("\n  D:::::D     D:::::D");
	printf("\n  D:::::D     D:::::D");
	printf("\n  D:::::D     D:::::D");
	printf("\n  D:::::D     D:::::D");
	printf("\n  D:::::D     D:::::D");
	printf("\n  D:::::D     D:::::D");
	printf("\n  D:::::D    D:::::D ");
	printf("\nDDD:::::DDDDD:::::D  ");
	printf("\nD:::::::::::::::DD   ");
	printf("\nD::::::::::::DDD     ");
	printf("\nDDDDDDDDDDDDD        ");
}
letterE() {
	printf("\nEEEEEEEEEEEEEEEEEEEEEE");
	printf("\nE::::::::::::::::::::E");
	printf("\nE::::::::::::::::::::E");
	printf("\nEE::::::EEEEEEEEE::::E");
	printf("\n  E:::::E       EEEEEE");
	printf("\n  E:::::E             ");
	printf("\n  E::::::EEEEEEEEEE   ");
	printf("\n  E:::::::::::::::E   ");
	printf("\n  E:::::::::::::::E   ");
	printf("\n  E::::::EEEEEEEEEE   ");
	printf("\n  E:::::E             ");
	printf("\n  E:::::E       EEEEEE");
	printf("\nEE::::::EEEEEEEE:::::E");
	printf("\nE::::::::::::::::::::E");
	printf("\nE::::::::::::::::::::E");
	printf("\nEEEEEEEEEEEEEEEEEEEEEE");
}
letterF() {
	printf("\nFFFFFFFFFFFFFFFFFFFFFF");
	printf("\nF::::::::::::::::::::F");
	printf("\nF::::::::::::::::::::F");
	printf("\nFF::::::FFFFFFFFF::::F");
	printf("\n  F:::::F       FFFFFF");
	printf("\n  F:::::F             ");
	printf("\n  F::::::FFFFFFFFFF   ");
	printf("\n  F:::::::::::::::F   ");
	printf("\n  F:::::::::::::::F   ");
	printf("\n  F::::::FFFFFFFFFF   ");
	printf("\n  F:::::F             ");
	printf("\n  F:::::F             ");
	printf("\nFF:::::::FF          ");
	printf("\nF::::::::FF          ");
	printf("\nF::::::::FF           ");
	printf("\nFFFFFFFFFFF           ");
}
letterG() {
	printf("\n        GGGGGGGGGGGGG");
	printf("\n     GGG::::::::::::G");
	printf("\n   GG:::::::::::::::G");
	printf("\n  G:::::GGGGGGGG::::G");
	printf("\n G:::::G       GGGGGG");
	printf("\nG:::::G              ");
	printf("\nG:::::G              ");
	printf("\nG:::::G    GGGGGGGGGG");
	printf("\nG:::::G    G::::::::G");
	printf("\nG:::::G    GGGGG::::G");
	printf("\nG:::::G        G::::G");
	printf("\n G:::::G       G::::G");
	printf("\n  G:::::GGGGGGGG::::G");
	printf("\n   GG:::::::::::::::G");
	printf("\n     GGG::::::GGG:::G");
	printf("\n        GGGGGG   GGGG");
}
letterH() {
	printf("\nHHHHHHHHH     HHHHHHHHH");
	printf("\nH:::::::H     H:::::::H");
	printf("\nH:::::::H     H:::::::H");
	printf("\nHH::::::H     H::::::HH");
	printf("\n  H:::::H     H:::::H  ");
	printf("\n  H:::::H     H:::::H  ");
	printf("\n  H::::::HHHHH::::::H  ");
	printf("\n  H:::::::::::::::::H  ");
	printf("\n  H:::::::::::::::::H  ");
	printf("\n  H::::::HHHHH::::::H  ");
	printf("\n  H:::::H     H:::::H  ");
	printf("\n  H:::::H     H:::::H  ");
	printf("\nHH::::::H     H::::::HH");
	printf("\nH:::::::H     H:::::::H");
	printf("\nH:::::::H     H:::::::H");
	printf("\nHHHHHHHHH     HHHHHHHHH");
}
letterI() {
	printf("\nIIIIIIIIII");
	printf("\nI::::::::I");
	printf("\nI::::::::I");
	printf("\nII::::::II");
	printf("\n  I::::I  ");
	printf("\n  I::::I  ");
	printf("\n  I::::I  ");
	printf("\n  I::::I  ");
	printf("\n  I::::I  ");
	printf("\n  I::::I  ");
	printf("\n  I::::I  ");
	printf("\n  I::::I  ");
	printf("\nII::::::II");
	printf("\nI::::::::I");
	printf("\nI::::::::I");
	printf("\nIIIIIIIIII");
}
letterJ() {
	printf("\n          JJJJJJJJJJJ");
	printf("\n          J:::::::::J");
	printf("\n          J:::::::::J");
	printf("\n          JJ:::::::JJ");
	printf("\n            J:::::J  ");
	printf("\n            J:::::J  ");
	printf("\n            J:::::J  ");
	printf("\n            J:::::j  ");
	printf("\n            J:::::J  ");
	printf("\nJJJJJJJ     J:::::J  ");
	printf("\nJ:::::J     J:::::J  ");
	printf("\nJ::::::J   J::::::J  ");
	printf("\nJ:::::::JJJ:::::::J  ");
	printf("\n JJ:::::::::::::JJ   ");
	printf("\n   JJ:::::::::JJ     ");
	printf("\n     JJJJJJJJJ       ");
}
letterK() {
	printf("\nKKKKKKKKK    KKKKKKK");
	printf("\nK:::::::K    K:::::K");
	printf("\nK:::::::K    K:::::K");
	printf("\nK:::::::K   K::::::K");
	printf("\nKK::::::K  K:::::KKK");
	printf("\n  K:::::K K:::::K   ");
	printf("\n  K::::::K:::::K    ");
	printf("\n  K:::::::::::K     ");
	printf("\n  K:::::::::::K     ");
	printf("\n  K::::::K:::::K    ");
	printf("\n  K:::::K K:::::K   ");
	printf("\nKK::::::K  K:::::KKK");
	printf("\nK:::::::K   K::::::K");
	printf("\nK:::::::K    K:::::K");
	printf("\nK:::::::K    K:::::K");
	printf("\nKKKKKKKKK    KKKKKKK");
}

num1() {
	printf("\n\n");
	printf("\n  1111111   ");
	printf("\n 1::::::1   ");
	printf("\n1:::::::1   ");
	printf("\n111:::::1   ");
	printf("\n   1::::1   ");
	printf("\n   1::::1   ");
	printf("\n   1::::1   ");
	printf("\n   1::::l   ");
	printf("\n   1::::l   ");
	printf("\n   1::::l   ");
	printf("\n   1::::l   ");
	printf("\n111::::::111");
	printf("\n1::::::::::1");
	printf("\n1::::::::::1");
	printf("\n111111111111");

}

num2() {
	printf("\n\n");
	printf("\n 222222222222222    ");
	printf("\n2:::::::::::::::22  ");
	printf("\n2::::::222222:::::2 ");
	printf("\n2222222     2:::::2 ");
	printf("\n            2:::::2 ");
	printf("\n            2:::::2 ");
	printf("\n         2222::::2  ");
	printf("\n    22222::::::22   ");
	printf("\n  22::::::::222     ");
	printf("\n 2:::::22222        ");
	printf("\n2:::::2             ");
	printf("\n2:::::2             ");
	printf("\n2:::::2       222222");
	printf("\n2::::::2222222:::::2");
	printf("\n2::::::::::::::::::2");
	printf("\n22222222222222222222");

}

num3() {
	printf("\n\n");
	printf("\n 333333333333333   ");
	printf("\n3:::::::::::::::33 ");
	printf("\n3::::::33333::::::3");
	printf("\n3333333     3:::::3");
	printf("\n            3:::::3");
	printf("\n            3:::::3");
	printf("\n    33333333:::::3 ");
	printf("\n    3:::::::::::3  ");
	printf("\n    33333333:::::3 ");
	printf("\n            3:::::3");
	printf("\n            3:::::3");
	printf("\n            3:::::3");
	printf("\n3333333     3:::::3");
	printf("\n3::::::33333::::::3");
	printf("\n3:::::::::::::::33 ");
	printf("\n 333333333333333   ");
}
num4() {
	printf("\n       444444444  ");
	printf("\n      4::::::::4  ");
	printf("\n     4:::::::::4  ");
	printf("\n    4::::44::::4  ");
	printf("\n   4::::4 4::::4  ");
	printf("\n  4::::4  4::::4  ");
	printf("\n 4::::4   4::::4  ");
	printf("\n4::::444444::::444");
	printf("\n4::::::::::::::::4");
	printf("\n4444444444:::::444");
	printf("\n          4::::4  ");
	printf("\n          4::::4  ");
	printf("\n          4::::4  ");
	printf("\n        44::::::44");
	printf("\n        4::::::::4");
	printf("\n        4444444444");
}

num5() {
	printf("\n555555555555555555 ");
	printf("\n5::::::::::::::::5 ");
	printf("\n5::::::::::::::::5 ");
	printf("\n5:::::555555555555 ");
	printf("\n5:::::5            ");
	printf("\n5:::::5            ");
	printf("\n5:::::5            ");
	printf("\n5:::::5555555555   ");
	printf("\n5:::::::::::::::5  ");
	printf("\n555555555555:::::5 ");
	printf("\n            5:::::5");
	printf("\n            5:::::5");
	printf("\n5555555     5:::::5");
	printf("\n5::::::55555::::::5");
	printf("\n 55:::::::::::::55 ");
	printf("\n   55:::::::::55   ");
	printf("\n     555555555     ");

}

num6() {
	printf("\n        66666666   ");
	printf("\n       6::::::6    ");
	printf("\n      6::::::6     ");
	printf("\n     6::::::6      ");
	printf("\n    6::::::6       ");
	printf("\n   6::::::6        ");
	printf("\n  6::::::6         ");
	printf("\n 6::::::::66666    ");
	printf("\n6::::::::::::::66  ");
	printf("\n6::::::66666:::::6 ");
	printf("\n6:::::6     6:::::6");
	printf("\n6:::::6     6:::::6");
	printf("\n6::::::66666::::::6");
	printf("\n 66:::::::::::::66 ");
	printf("\n   66:::::::::66   ");
	printf("\n     666666666     ");
}

num7() {
	printf("\n77777777777777777777");
	printf("\n7::::::::::::::::::7");
	printf("\n7::::::::::::::::::7");
	printf("\n777777777777:::::::7");
	printf("\n           7::::::7 ");
	printf("\n          7::::::7  ");
	printf("\n         7::::::7   ");
	printf("\n        7::::::7    ");
	printf("\n       7::::::7     ");
	printf("\n      7::::::7      ");
	printf("\n     7::::::7       ");
	printf("\n    7::::::7        ");
	printf("\n   7::::::7         ");
	printf("\n  7::::::7          ");
	printf("\n 7::::::7           ");
	printf("\n77777777            ");
}

num8() {
	printf("\n     888888888     ");
	printf("\n   88:::::::::88   ");
	printf("\n 88:::::::::::::88 ");
	printf("\n8::::::88888::::::8");
	printf("\n8:::::8     8:::::8");
	printf("\n8:::::8     8:::::8");
	printf("\n 8:::::88888:::::8 ");
	printf("\n  8:::::::::::::8  ");
	printf("\n 8:::::88888:::::8 ");
	printf("\n8:::::8     8:::::8");
	printf("\n8:::::8     8:::::8");
	printf("\n8:::::8     8:::::8");
	printf("\n8::::::88888::::::8");
	printf("\n 88:::::::::::::88 ");
	printf("\n   88:::::::::88   ");
	printf("\n     888888888     ");

}

num9() {
	printf("\n     999999999     ");
	printf("\n   99:::::::::99   ");
	printf("\n 99:::::::::::::99 ");
	printf("\n9::::::99999::::::9");
	printf("\n9:::::9     9:::::9");
	printf("\n9:::::9     9:::::9");
	printf("\n 9:::::99999::::::9");
	printf("\n  99::::::::::::::9");
	printf("\n    99999::::::::9 ");
	printf("\n         9::::::9  ");
	printf("\n        9::::::9   ");
	printf("\n       9::::::9    ");
	printf("\n      9::::::9     ");
	printf("\n     9::::::9      ");
	printf("\n    9::::::9       ");
	printf("\n   99999999        ");
}

menu1() {
	printf("\nTTTTTTTTTTTTTTTTTTTTTTThhhhhhh                                 ");
	printf("\nT:::::::::::::::::::::Th:::::h                                 ");
	printf("\nT:::::::::::::::::::::Th:::::h                                 ");
	printf("\nT:::::TT:::::::TT:::::Th:::::h                                 ");
	printf("\nTTTTTT  T:::::T  TTTTTT h::::h hhhhh           eeeeeeeeeeee    ");
	printf("\n        T:::::T         h::::hh:::::hhh      ee::::::::::::ee  ");
	printf("\n        T:::::T         h::::::::::::::hh   e::::::eeeee:::::ee");
	printf("\n        T:::::T         h:::::::hhh::::::h e::::::e     e:::::e");
	printf("\n        T:::::T         h::::::h   h::::::he:::::::eeeee::::::e");
	printf("\n        T:::::T         h:::::h     h:::::he:::::::::::::::::e ");
	printf("\n        T:::::T         h:::::h     h:::::he::::::eeeeeeeeeee  ");
	printf("\n        T:::::T         h:::::h     h:::::he:::::::e           ");
	printf("\n      TT:::::::TT       h:::::h     h:::::he::::::::e          ");
	printf("\n      T:::::::::T       h:::::h     h:::::h e::::::::eeeeeeee  ");
	printf("\n      T:::::::::T       h:::::h     h:::::h  ee:::::::::::::e  ");
	printf("\n      TTTTTTTTTTT       hhhhhhh     hhhhhhh    eeeeeeeeeeeeee  ");
}

menu2() {
	printf("\nMMMMMMMM               MMMMMMMM                                                                                                       ");
	printf("\nM:::::::M             M:::::::M                                                                                                       ");
	printf("\nM::::::::M           M::::::::M                                                                                                       ");
	printf("\nM:::::::::M         M:::::::::M                                                                                                       ");
	printf("\nM::::::::::M       M::::::::::M    eeeeeeeeeeee       mmmmmmm    mmmmmmm      ooooooooooo   rrrrr   rrrrrrrrryyyyyyy           yyyyyyy");
	printf("\nM:::::::::::M     M:::::::::::M  ee::::::::::::ee   mm:::::::m  m:::::::mm  oo:::::::::::oo r::::rrr:::::::::ry:::::y         y:::::y ");
	printf("\nM:::::::M::::M   M::::M:::::::M e::::::eeeee:::::eem::::::::::mm::::::::::mo:::::::::::::::or:::::::::::::::::ry:::::y       y:::::y  ");
	printf("\nM::::::M M::::M M::::M M::::::Me::::::e     e:::::em::::::::::::::::::::::mo:::::ooooo:::::orr::::::rrrrr::::::ry:::::y     y:::::y   ");
	printf("\nM::::::M  M::::M::::M  M::::::Me:::::::eeeee::::::em:::::mmm::::::mmm:::::mo::::o     o::::o r:::::r     r:::::r y:::::y   y:::::y    ");
	printf("\nM::::::M   M:::::::M   M::::::Me:::::::::::::::::e m::::m   m::::m   m::::mo::::o     o::::o r:::::r     rrrrrrr  y:::::y y:::::y     ");
	printf("\nM::::::M    M:::::M    M::::::Me::::::eeeeeeeeeee  m::::m   m::::m   m::::mo::::o     o::::o r:::::r               y:::::y:::::y      ");
	printf("\nM::::::M     MMMMM     M::::::Me:::::::e           m::::m   m::::m   m::::mo::::o     o::::o r:::::r                y:::::::::y       ");
	printf("\nM::::::M               M::::::Me::::::::e          m::::m   m::::m   m::::mo:::::ooooo:::::o r:::::r                 y:::::::y        ");
	printf("\nM::::::M               M::::::M e::::::::eeeeeeee  m::::m   m::::m   m::::mo:::::::::::::::o r:::::r                  y:::::y         ");
	printf("\nM::::::M               M::::::M  ee:::::::::::::e  m::::m   m::::m   m::::m oo:::::::::::oo  r:::::r                 y:::::y          ");
	printf("\nMMMMMMMM               MMMMMMMM    eeeeeeeeeeeeee  mmmmmm   mmmmmm   mmmmmm   ooooooooooo    rrrrrrr                y:::::y           ");
	printf("\n                                                                                                                   y:::::y            ");
	printf("\n                                                                                                                  y:::::y             ");
	printf("\n                                                                                                                 y:::::y              ");
	printf("\n                                                                                                                y:::::y               ");
	printf("\n                                                                                                               yyyyyyy                ");
}

menu3() {
	printf("\n        GGGGGGGGGGGGG                                                              ");
	printf("\n     GGG::::::::::::G                                                              ");
	printf("\n   GG:::::::::::::::G                                                              ");
	printf("\n  G:::::GGGGGGGG::::G                                                              ");
	printf("\n G:::::G       GGGGGG  aaaaaaaaaaaaa      mmmmmmm    mmmmmmm       eeeeeeeeeeee    ");
	printf("\nG:::::G                a::::::::::::a   mm:::::::m  m:::::::mm   ee::::::::::::ee  ");
	printf("\nG:::::G                aaaaaaaaa:::::a m::::::::::mm::::::::::m e::::::eeeee:::::ee");
	printf("\nG:::::G    GGGGGGGGGG           a::::a m::::::::::::::::::::::me::::::e     e:::::e");
	printf("\nG:::::G    G::::::::G    aaaaaaa:::::a m:::::mmm::::::mmm:::::me:::::::eeeee::::::e");
	printf("\nG:::::G    GGGGG::::G  aa::::::::::::a m::::m   m::::m   m::::me:::::::::::::::::e ");
	printf("\nG:::::G        G::::G a::::aaaa::::::a m::::m   m::::m   m::::me::::::eeeeeeeeeee  ");
	printf("\n G:::::G       G::::Ga::::a    a:::::a m::::m   m::::m   m::::me:::::::e           ");
	printf("\n  G:::::GGGGGGGG::::Ga::::a    a:::::a m::::m   m::::m   m::::me::::::::e          ");
	printf("\n   GG:::::::::::::::Ga:::::aaaa::::::a m::::m   m::::m   m::::m e::::::::eeeeeeee  ");
	printf("\n     GGG::::::GGG:::G a::::::::::aa:::am::::m   m::::m   m::::m  ee:::::::::::::e  ");
	printf("\n        GGGGGG   GGGG  aaaaaaaaaa  aaaammmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee  ");
}
