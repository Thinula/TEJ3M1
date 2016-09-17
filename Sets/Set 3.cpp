/* Thinula De Silva
Set 3 Programs
Nov 18, 2015
TEJ3M1 - 00
*/
#include <iostream>
#include <cstdlib> 
#include <windows.h> 
#include <stdio.h>

using namespace std;

/************************************** the multiplier method ****************************************************/
void multiplier() {
	
	int A;
	cout << "multiplier : ";
	cin >> A;
	cout << "\n";
	
	for (int i = 1; i < 13; i++) {
		cout << A << " x " << i << " = " << A*i << endl;
	}
	system("PAUSE");	
}
/************************************** the fact method ****************************************************/
int fact (int k) {
	
	if (k == 0)
		return 1;
	else 
		return k*fact(k-1);
}
/************************************** the factDrive method ****************************************************/
void factDrive() {
	
	int A;
	cout << "Enter a nonnegative integer: ";
	cin >> A;
	
	if (A >=0 && A <= 12)
		cout << "\n\nThe factorial of " << A << " is " << fact(A) << endl;
	else {
		if (A < 0)
			cout << "\n\nPlease enter a nonnegative integer.";
		else
			cout << "\n\nThe result is too big to output.";
		cout << "\nThis program has terminated.";	
	}
	system("PAUSE");
}
/************************************** the bank method ****************************************************/
void bank(){
    
    int inv, mths;
    double bal1, ear, dep, intr;
    double bal2 = 0;
    
    cout << "Monthly Investment       : "; 
    cin >> inv;
    
    cout << "\nAnnual Interest Rate (%) : ";
    cin >> intr;
    
    intr = intr /= 100.00;
    
    cout << "\nTerms (Months)           : ";
    cin >> mths;
    
    cout << "\n\nStarting       Interest       Monthly       Ending";
    cout << "\nBalance         Earned        Deposit       Balance"; 
    cout << "\n--------       --------       --------      --------\n"; 
    
    for(int i = 0; i < mths; i++){ 
        
        bal1 = bal2; 
        ear = bal1 * (intr/12);
        dep = inv;
        bal2 = bal1 + ear + dep;
    
        cout.setf(ios::fixed); 
        cout.precision(2);
        
        cout.width(8);
        cout << bal1; // output results
        
        cout.width(7);
        cout << "";
        
        cout.width(8);
        cout << ear;
        
        cout.width(7);
        cout << "";
        
        cout.width(8);
        cout << dep;
        
        cout.width(7);
        cout << "";
        
        cout.width(8);
        cout << bal2;
        
        cout << endl;   
    }
    system("PAUSE");
    
}
/************************************** the HiLo method ****************************************************/
void HiLo () {
	
	int guess = 0;
	int rCount = 0;
	int numGen = (int) rand() % 99 + 1; // numGenerated gets a random value of 1 to 100
	
	do {
		cout << "Please enter your guess: ";
		cin >> guess;
		if (guess < numGen)
			cout << "The original number is higher!" << endl;
		else if (guess > numGen)
			cout << "The original number is lower!"<< endl;
		rCount ++;
	}
	while (guess != numGen);
	
	cout << "\nCorrect! You took " << rCount << " tries to guess the number! \n";
	system("PAUSE");
}
/************************************** the main method ****************************************************/
int main() {
	
	
	int choice = 1;
	
	cout << "Welcome to Set 3! \nThis program has many subprograms.\n";
	cout << "To select the subprogram you would like to view, \nenter the character indicated below. \n\n";
	
	cout << "1 - Multiplier \n";
	cout << "2 - Factorial \n";
	cout << "3 - Bank \n";
	cout << "4 - Higher or Lower \n";
	cout << "0 - Leave \n\n";
	cout << "Please enter the number related to the program you want to run: ";
	cin >> choice;
	system("cls");
	
	while (choice != 0) {
      
		if (choice == 1) 
            multiplier();
		else if (choice == 2) 
            factDrive();
        else if (choice == 3)
			bank();
		else
			HiLo();
			
		system("cls");
        cout << "1 - Multiplier \n";
	    cout << "2 - Factorial \n";
	    cout << "3 - Bank \n";
	    cout << "4 - Higher or Lower \n";
	    cout << "0 - Leave \n\n";
		cout << "Please enter the number related to the program you want to run: ";
		cin >> choice;
		system("cls");	
	}
	if (choice == 0){
		cout << "Hope you enjoyed the Set 3 and stay tuned for our next one! \n";
		cout << "Goodbye and have a nice day!\n\n";
		system("PAUSE");	
	}
	return 0;	
}

