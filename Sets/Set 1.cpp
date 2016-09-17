/* Thinula De Silva
Set 1 Programs
Sept 22, 2015
TEJ3M1 - 00
*/

#include <iostream>

using namespace std;

/************************************** the kilo method ****************************************************/
void kilo(int kB) {
     
     cout << "\nThe file can store " <<1024*kB << " characters.\n\n";
     cout << "This program has terminated.";
     system("PAUSE");
}
/************************************** the rectangle method ****************************************************/
void rectangle(int len, int wid) {
     
     cout << "\n\nThe perimeter of the rectangle is " << 2*(len+wid) <<endl;
     cout << "The area of the rectangle is " << len*wid <<endl;
     cout << "This program has terminated.";
     system("PAUSE");
}
/************************************** the eggs method ****************************************************/
void eggs (int egg) {
     
     cout << "This is " << egg/12 << " whole dozens and " << egg%12 << " extra eggs.\n\n";
     cout << "Nice doing business with you.\n";
	 cout << "Have a nice day!\n\n";
	 cout << "Take care of those chickens!";
     system("PAUSE");	    
}

/************************************** the main method ****************************************************/
int main () {
    
    int choice = 1;
    int kB, len, wid, egg;
	
	cout << "Welcome to Set 1! \nThis program has many subprograms.\n";
	cout << "To select the subprogram you would like to view, \nenter the character indicated below. \n\n";
	
	cout << "1 - Kilobytes \n";
	cout << "2 - Rectangles \n";
	cout << "3 - Eggs \n";
	cout << "0 - Leave \n\n";
	cout << "Please enter the number related to the program you want to run: ";
	cin >> choice;
	system("cls");
	
	while (choice != 0) {
          
		if (choice == 1) {
                   
			cout << "How many kBs are in the file? ";
			cin >> kB;
			kilo(kB);
		}
		else if (choice == 2) {
             
			cout << "What is the length of the rectangle? ";
			cin >> len;
			cout << "What is the width of the rectangle? ";
			cin >> wid;
			rectangle(len, wid);
		}
		else {
			cout << "How many eggs are in this order? ";
			cin >> egg;
			eggs(egg);
		}
		system("cls");
        cout << "1 - Kilobytes \n";
	    cout << "2 - Rectangles \n";
	    cout << "3 - Eggs \n";
	    cout << "0 - Leave \n\n";
		cout << "Please enter the number related to the program you want to run: ";
		cin >> choice;
		system("cls");	
	}
	if (choice == 0){
		cout << "Hope you enjoyed Set 1 and stay tuned for Set 2! \n";
		cout << "Goodbye and have a nice day!\n\n";
		system("PAUSE");	
	}
	return 0;
}
