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

int numInput;

/* Definitions in the build of inpout32.dll are:            */
/*   short _stdcall Inp32(short PortAddress);               */
/*   void _stdcall Out32(short PortAddress, short data);    */

/* prototype (function typedef) for DLL function Inp32: */

     typedef short (_stdcall *inpfuncPtr)(short portaddr);
     typedef void (_stdcall *oupfuncPtr)(short portaddr, short datum);

#define PPORT_BASE 0x378
// Prototypes for Test functions
void test_read8(void);
void test_write(void);
void test_write_datum(short datum);

/* After successful initialization, these 2 variables
   will contain function pointers.
 */
     inpfuncPtr inp32fp;
     oupfuncPtr oup32fp;
/* Wrapper functions for the function pointers
    - call these functions to perform I/O.
 */
     short  Inp32 (short portaddr)
     {
          return (inp32fp)(portaddr);
     }

     void  Out32 (short portaddr, short datum)
     {
          (oup32fp)(portaddr,datum);
     }

/************************************** the counter method ****************************************************/
void counter()
{
     system("cls");
     
     for(int A = 1; A < 256; A++) {
      	cout << A << endl;
        Sleep(10);
        Out32(PPORT_BASE,in);     
     	getch();
     }
     
     cout << "Press any key to count back. " << endl;
     getch();
     
     for(int A = 255; A > 0; A--) {
    	cout << A << endl;
        Sleep(10);
        Out32(PPORT_BASE,in);     
     	getch();
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
			Out32(PPORT_BASE,in);     
     		getch();     
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
			Out32(PPORT_BASE,in);     
     		getch();      
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
				Out32(PPORT_BASE,in);     
     			getch();      
           }
           
           for(int A = 64; A > 0; A /= 2) {
                cout << A << " ";
                Sleep(50);     
				Out32(PPORT_BASE,in);     
     			getch();  
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
	Out32(PPORT_BASE,in);     
    getch();
}

/************************************** the menu method ****************************************************/
void menu() {
	
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
	return 0;
}
/************************************** the main method ****************************************************/   
int main(void)
{
     HINSTANCE hLib;
     short x;
     int i;
     /* Load the library */
     hLib = LoadLibrary("inpout32.dll");
     if (hLib == NULL) {
          fprintf(stderr,"LoadLibrary Failed.\n");
          getch();
          return -1;                      }
    /* get the address of the function */
     inp32fp = (inpfuncPtr) GetProcAddress(hLib, "Inp32");
     if (inp32fp == NULL) {
          fprintf(stderr,"GetProcAddress for Inp32 Failed.\n");
          getch();
          return -1;
     }
     oup32fp = (oupfuncPtr) GetProcAddress(hLib, "Out32");
     if (oup32fp == NULL) {
          fprintf(stderr,"GetProcAddress for Oup32 Failed.\n");
          getch();
          return -1;
     }
    /*****  Write 0x75 to data register and verify */
     menu();
     Out32(PPORT_BASE,0);//This resets the 8 leds to off or zero
     FreeLibrary(hLib);
     return 0;
}
