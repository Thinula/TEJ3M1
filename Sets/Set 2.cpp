/* Thinula De Silva
Set 2 Programs
Oct 28, 2015
TEJ3M1 - 00
*/
#include <stdio.h> 
#include <cstdlib> 
#include <windows.h>
#include <iostream> 

using namespace std;

/************************************** While Loop method ****************************************************/
void whileLoop()
{
	int A = 11;
	
	while (A < 10) {
		cout << A << endl;
		A++;
	}
	cin.get();
}
/************************************** For Loop method ****************************************************/
void forLoop()
{	
	for (int x = 1; x < 10; x*= 2) {
        cout << x << endl;
    }
    cin.get();
}
/************************************** Do While Loop method ****************************************************/
void doWhileLoop()
{
     int x = 4;
     do {
         x ++;
         cout << x << "\n";
     } while (x > 2);
	 cin.get();
}
/************************************** controlling output method ****************************************************/
void controlOutput()
{
	int mark, total;
	float percent;
	
	cout.setf(ios::fixed);
	cout.precision(1);
	
	system("cls");
	
	cout << "What mark did you get?";
	cin >> mark; cout.width(23);
	cout << "What was it out of?      ";
	cin >> total;
	
	percent = mark*100.0/total;
	
	cout << "\n Your mark is " << percent << "%";
	
	cout.width(30); cout << "Goodbye! \n\n";
	system("PAUSE");
}
/************************************** the gotoxy method ****************************************************/
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
/************************************** the main method ****************************************************/
int main()
{
	
	int choice = -1;
	
	cout << "Welcome to Set 2! \nThis program has many subprograms.\n";
	cout << "To select the subprogram you would like to view, \nenter the character indicated below. \n\n";
	
	cout << "1 - While Loop \n";
	cout << "2 - For Loop \n";
	cout << "3 - Do While Loop \n";
	cout << "4 - Controlling Your Output \n";
	cout << "5 - Go To xy \n";
	cout << "0 - Leave \n\n";
	cout << "Please enter the number related to the program you want to run: ";
	cin >> choice;
	system("cls");
	
	while (choice != 0) {
          
		if (choice == 1) {
            whileLoop();
		}
		else if (choice == 2) {
            forLoop();
		}
		else if (choice == 3) {
             doWhileLoop();
        }
        else if (choice == 4) {
             controlOutput();
        }     
		else {
			gotoxy(80,1);
	        cout << "I am over here!";
		}
		system("cls");
        cout << "1 - While Loop \n";
	    cout << "2 - For Loop \n";
	    cout << "3 - Do While Loop \n";
	    cout << "4 - Controlling Your Output \n";
	    cout << "5 - Go To xy \n";
	    cout << "0 - Leave \n\n";
	    cout << "Please enter the number related to the program you want to run: ";
		cin >> choice;
		system("cls");	
	}
	if (choice == 0){
		cout << "Hope you enjoyed Set 2 and stay tuned for Set 3! \n";
		cout << "Goodbye and have a nice day!\n\n";
		system("PAUSE");	
	}
	return 0;
}
