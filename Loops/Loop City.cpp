# include <iostream>
# include <windows.h>
# include <conio.h>

using namespace std;


/************************************** the gotoxy method ****************************************************/
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void forloop ()
{
	for (int i = 0; i < 24; i ++) {
		cout << "I am over here!!!";
		gotoxy(i,i);
		Sleep(300);
	}
	cout << "I am over here!!!        ";
	for (int i = 22; i > 0; i --) {
		cout << "And I am here!!!";
		gotoxy(i+25,i);
		Sleep(300);
	}
}

void overhere() {

    int x = (rand()%10)+4;
    int i = 0;
    int y = 0;
    do {
        for (y = 0; y < 21; y++) {
            cout << "I am over here!!!";
            gotoxy(y,y);
            Sleep(25);
        }
        for (y = 20; y >= 0; y--) {
            cout << "I am over here!!!";
            gotoxy(40-y,y);
            Sleep(25);
        }
        for (y = 0; y < 21; y++) {
        	cout << "I am over here!!!";
        	gotoxy(40+y,y);
        	Sleep(25);
		}
		for (y = 20; y >= 0; y--) {
        	cout << "I am over here!!!";
        	gotoxy(80-y,y);
        	Sleep(25);
		}
		system("cls");
        i++;
    }
    while (i < x);
}

void random ()
{
	int numGen1, numGen2;
	while(!kbhit()) {
		numGen1 = (rand()%30)+1;
		numGen2 = (rand()%30)+1;
		gotoxy(numGen1, numGen2);
		cout << "I am over here!!!";
		Sleep(400);
		system("cls");
	}

}

int main() {

	int choice = -1;
	cout << "Welcome to Loop City! \nThis program has many subprograms.\n";
	cout << "To select the subprogram you would like to view, \nenter the character indicated below. \n\n";

	cout << "1 - GoToXY For Loop \n";
	cout << "2 - Overhere Slinky \n";
	cout << "3 - Overhere Random \n";
	cout << "0s - Leave \n\n";
	cout << "Please enter the number related to the program you want to run: ";
	cin >> choice;
	system("cls");

	while (choice != 0) {

		if (choice == 1) {
            forloop();
		}
		else if (choice == 2) {
            overhere();
		}
		else {
			random();
		}
		system("cls");
        cout << "1 - GoToXY For Loop \n";
	    cout << "2 - Overhere Slinky \n";
	    cout << "3 - Overhere Random \n";
	    cout << "0 - Leave \n\n";
	    cout << "Please enter the number related to the program you want to run: ";
		cin >> choice;
		system("cls");
	}
	if (choice == 0){
		cout << "Hope you enjoyed Loop City and stay tuned for Set 3! \n";
		cout << "Goodbye and have a nice day!\n\n";
		system("PAUSE");
	}
	return 0;
}
