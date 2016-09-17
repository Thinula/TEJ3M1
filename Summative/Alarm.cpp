#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime> // used for tracking current time
#include <vector> 

using namespace std; 

int numInput;
//int numInput(string str)
//{
//       cout << str;
//       int in;
//       
//       cin >> in;
//       return in;    
//}

/* Definitions in the build of inpout32.dll are:            */
/*   short _stdcall Inp32(short PortAddress);               */
/*   void _stdcall Out32(short PortAddress, short data);    */

/* prototype (function typedef) for DLL function Inp32: */

     typedef short (_stdcall *inpfuncPtr)(short portaddr);
     typedef void (_stdcall *oupfuncPtr)(short portaddr, short datum);

#define PPORT_BASE 0x378
#define PPORT_INP (PPORT_BASE+1)
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
     
void test_write_datum(short datum)
{
     short x;
     int i;

     i=PPORT_BASE;
     x = datum;

     /*****  Write the data register */
     Out32(i,x);

     //printf("\nPort write to 0x%X, datum=0x%2X\n" ,i ,x);

     /***** And read back to verify  */
     x = Inp32(i);
     //printf("Port read (%04X)= %04X\n",i,x);
}    
//*************************buttonDemo*********************
vector<int> buttonDemo(int H, int M) 
{
// This method is for converting user's inputs via buttons to a change in the alarm time
	
     int input = 0; //Declare variable
     vector<int> out; // the return vector
     
     cout << "Current alarm time is " << H << ":" << M << "." << endl;
     while (input != 112)
     {
   		input = Inp32(PPORT_INP);//Recieve input
    	Sleep(50);
    	
        if (input == 56) // if button 1 is pressed
        	H ++; // increment hours by 1
        	
        else if (input == 248) // if button 2 is pressed
        	H --; // decrement hours by 1
        	
        else if (input == 88) // if button 3 is pressed
        	M ++; // increment minutes by 1
        	
        else if (input == 104) // if button 4 is pressed
        	M --;
        		        
         else if (input == 184 || input == 72 || input == 152 || input == 8 || input == 168 || input == 200 || input == 136) // if at least buttons 1 and 2 are pressed together or at least buttons 3 and 4 are pressed together
         	cout << "Please try again. " << endl; // wants to increase then decrease at same time, so a contradiction
         	
        else if (input == 24) // if buttons 1 and 3 are pressed
        {
        	H ++; // increment hours by 1
        	M ++; // increment minutes by 1
		}
		
        else if (input == 40) // if buttons 1 and 4 are pressed
        {
        	H ++; // increment hours by 1
        	M --; // decrement minutes by 1
		}
		
        else if (input == 216) // if buttons 2 and 3 are pressed
        {
        	H --; // increment hours by 1
        	M ++; // decrement minutes by 1
		}	
		
        else if (input == 232) // if buttons 2 and 4 are pressed
        {
        	H --; // decrement hours by 1
        	M --; // decrement minutes by 1
		}
		
		else  // if one of the buttons pressed was 5
		{
			// The next following lines (lines 127-137) print the finalized alarm time
			cout << "The alarm time has been finalized to: ";
				
			if(H < 10) // if the hours is less than 10, print a 0 in front of it
				cout << "0";
	
			cout << H << ":";
    
			if(M < 10) // if the minutes is less than 10, print a 0 in front of it
				cout << "0";
    
			cout << M << ".\n";
			break;
		}
		
		H %= 24;
     	M %= 60;
     		
		// The next following lines (lines 145-155) print the currentalarm time
			cout << "Current alarm time: ";
				
			if(H < 10) // if the hours is less than 10, print a 0 in front of it
				cout << "0";
	
			cout << H << ":";
    
			if(M < 10) // if the minutes is less than 10, print a 0 in front of it
				cout << "0";
    
			cout << M << ".\n";
     }
     
     out.push_back(H); // add hours to the end of the out vector
     out.push_back(M); // add minutes to the end of the out vector (makes hours at the beginning)
     return out;
}
//************************ Alarm *********************
void alarm ()
{		
	// These two lines of codes calculates the current time in the computer system
	time_t now = time(0);
   	tm *ltm = localtime(&now);
   		
	int hour = ltm->tm_hour; // calculates the current hour (in 24-hour format)
	int min = ltm->tm_min; // calculates the current minute
	
	cout << "Welcome to the Alarm! \nClick the following buttons to do as described below:\n\n";
	cout << "1 - Increment hours by 1\n";
	cout << "2 - Decrement hours by 1\n";
	cout << "3 - Increment minutes by 1\n";
	cout << "4 - Decrement minutes by 1\n";
	cout << "5 - Set the alarm time and start program.\n";
	
	vector <int> alarm = buttonDemo(hour, min); // used for determining the alarm time
	hour = alarm.at(0); // takes the set alarm hour 
	min = alarm.at(1); // takes the set alaram minute
	
	now = time(0);
	ltm = localtime(&now);
	 
    int H = ltm->tm_hour;
	int M = ltm->tm_min;
	int S = ltm->tm_sec; // calculates the current second
	int tens, ones, seven, M_now;
	
	// The next following lines (lines 169-179) print the current time
	cout << "\nCurrent Time: ";
	
	if(H < 10) // if the hours is less than 10, print a 0 in front of it
		cout << "0";
	
	cout << H << ":";
    
	if(M < 10) // if the minutes is less than 10, print a 0 in front of it
		cout << "0";
    
	cout << M << endl;
	
	while (!(hour == H && min == M)) // loop as long as the current hour and current minute is not equal to the alarm hour and alarm minute
	{
        now = time(0);
   		ltm = localtime(&now);
   		
   		H = ltm->tm_hour;
   		M = ltm->tm_min;
        
        now = time(0);
   		ltm = localtime(&now);
   		
   		S = ltm->tm_sec; // calculates the current second
   		tens = S/10; // finds the tens digit of S
        ones = S % 10; // finds the ones digit of S
        seven = 16*tens+ones; // calcultates the number needed to send to the 7 Segment Displays
        Out32(PPORT_BASE,seven); // sends the "seven" variable to the 7 Segment Displays
        
        Sleep(1000); // waits for 1 second
        
        now = time(0);
        ltm = localtime (&now);
        
        M_now = ltm->tm_min; // calculates the new minute
        
        if (M_now != M) // if the new minute doesnt equal the old minute (i.e. a minute has passed), print the new time
        {
        	cout << "\nCurrent Time: ";
        	
	    	if(H < 10) 
				cout << "0";
				
	    	cout << H << ":";
	    	
        	if(M < 10) 
				cout << "0";
				
        	cout << M << endl;
		}

		// Calculates the current time to check if the while loop is still true
        now = time(0);
	    ltm = localtime(&now);
        H = ltm->tm_hour;
   		M = ltm->tm_min;
	}
	
	cout << "The Alarm has rung at " << hour << ":" << min << endl; // Prints the message that the alarm went off
	while (!kbhit())
	{
		Beep(100000,10); // Sounds the alarm
		tens = min/10;
		ones = min%10;
		seven = 16*tens+ones;
		Out32(PPORT_BASE,seven);
		Out32(PPORT_BASE,0);
		//cin.get();
	}
	
  	//system("PAUSE");
}
/************************************** the menu method ****************************************************/
void menu() {
	
	int choice = -1;
	
	cout << "Welcome to the Summative! \nThis program has several subprograms.\n";
	cout << "To select the subprogram you would like to view, \nenter the character indicated below. \n\n";
	cout << "If you would like to leave at any time, please enter 0. \n\n";
	
	cout << "1 - Alarm \n";
	cout << "2 - Stop Watch \n";
	cout << "5 - Leave \n\n";
	cout << "Please press the button related to the program you want to run: ";
	cin >> choice;
	system("cls");
	
	while (choice != 0) {
          
		if (choice == 1)
			alarm();
			
		system("PAUSE");	
		system("cls");
		
		cout << "1 - Alarm \n";
		cout << "2 - Stop Watch \n";
	    cout << "5 - Leave \n\n";
		cout << "Please press the button related to the program you want to run: ";
		cin >> choice;
		system("cls");	
	}
	if (choice == 0){
		cout << "Hope you enjoyed the Summative! This will be our last program! \n";
		cout << "Goodbye and have a nice day!\n\n";
		system("PAUSE");
	}
}
//*************************Main*********************     
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
