/* Thinula De Silva
8 LED V1 Program
November 27, 2015
TEJ3M1 - 00
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib> 
#include <vector> // used to output the string of the decimal representation

using namespace std;

/************************************** the counter method ****************************************************/
void counter()
{
     system("cls");
     
     for(int A = 1; A < 256; A++) {
      	cout << A << endl;
        Sleep(10);
     }
     
     cout << "Press any key to count back. " << endl;
     getch();
     
     for(int A = 255; A > 0; A--) {
    	cout << A << endl;
        Sleep(10);
     }
     
     cout << endl;
     cout << "Press any key to continue. " << endl;
     getch();     
}

/************************************** the PowerTwo method ****************************************************/
void PowerTwo()
{
     system("cls");
     
     while (!kbhit()) {
        for(int A = 1; A < 129; A *= 2) {
        	cout << A << " ";
            Sleep(50);       
        }
        cout << endl;
        Sleep(50);
     }
     
     cout << endl;
     cout << "And now, press any key to go in reverse..." << endl;
     getch();
     getch();
     cout << endl;
     
     while (!kbhit()) {
        for(int A = 128; A > 0; A /= 2) {
        	cout << A << " ";
            Sleep(50);       
        }
        cout << endl;
        Sleep(50);
     }
     
     cout << endl;
     cout << "And now, press any key to go forward and back~" << endl;
     getch();
     getch();
     cout << endl;
     
     while (!kbhit()) {
           for(int A = 1; A < 129; A *= 2) {
                   cout << A << " ";
                   Sleep(50);       
           }
           
           for(int A = 64; A > 0; A /= 2) {
                   cout << A << " ";
                   Sleep(50);       
           }
           cout << endl;
           Sleep(50);
     }
     
     cout << endl;
     
     cout << "Press any key to exit the method." << endl;
     getch();
     getch();   
}

/************************************** the ToBinary method ****************************************************/
void ToBinary()
{
    vector<string> outVector;	
  	int N, rem;
  	char buffer [33];
  	
  	cout << "Enter the number you want to convert to binary: ";
  	cin >> N;

	do { // algorithm to convert a number from decimal to binary
		
		rem = N % 2;
		
		itoa(rem,buffer,10);         // converts rem to base 10 as a string 
		outVector.push_back(buffer); // adds the converted string to outVector		
		
		N /= 2;
	}
	while (N != 0);
	
	for (int i = outVector.size()-1; i > -1; i --) // we added the elements in the reverse order, so we print in the reverse order
		cout << outVector[i]; // prints the converted string of digits
	cout << "\n";
}

/************************************** the main method ****************************************************/
int main() {
	
	int choice = 1;
	
	cout << "Welcome to the LED Program! \nThis program has one subprograms.\n";
	cout << "To select the subprogram you would like to view, \nenter the character indicated below. \n\n";
	cout << "If you would like to leave at any time, please enter 0. \n\n";
	
	cout << "1 - Counter to 255 \n";
	cout << "2 - Powers of Two \n";
	cout << "3 - Convert to Binary \n";
	cout << "0 - Leave \n\n";
	cout << "Please enter the number related to the program you want to run: ";
	cin >> choice;
	system("cls");
	
	while (choice != 0) {
          
		if (choice == 1)
			counter();
		else if (choice == 2)
			PowerTwo();
		else 
			ToBinary();
			
		system("PAUSE");	
		system("cls");\
		cout << "1 - Counter to 255 \n";
		cout << "2 - Powers of Two \n";
	    cout << "3 - Convert to Binary \n";
	    cout << "0 - Leave \n\n";
		cout << "Please enter the number related to the program you want to run: ";
		cin >> choice;
		system("cls");	
	}
	if (choice == 0){
		cout << "Hope you enjoyed the LED Program and stay tuned for our next one! \n";
		cout << "Goodbye and have a nice day!\n\n";
		system("PAUSE");	
	}
}


