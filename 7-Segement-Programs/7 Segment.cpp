 /* Thinula De Silva
January 19, 2015
 TEJ 3M1
 7 Segment Output*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

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
          return -1;
                      }
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
     FreeLibrary(hLib);
     return 0;
}
void menu(void) 
{
     short x;
     int i, y;

     i=PPORT_BASE;
     x=0x75;

     int choice, n, tens, ones, final;
     do
     {
          system("cls");
          cout << "1 - Output Number 0-99" << endl;
          cout << "2 - Count 0 - 99" << endl;
          cout << "3 - Count 0 - 99 by 3s" << endl;
          cout << "0 - Exit" << endl;
          cin >> choice;
          if (choice == 1) 
          {          
                system("cls");
				do 
				{
					cout << "Input any number from 0 to 99: ";
			    	cin >> n;
				} 
				while (n > 99 || n < 0);
				
				tens = n / 10;
				ones = n % 10;
				final = tens + (ones*16);
				system("cls");
                Out32 (i, final);
                cout << "The number " << n << " becomes " << final << "." << endl;
                system("PAUSE");     
          } 
		  else if (choice == 2)
          {
          		system("cls");
          		n = 0;
          		do
          		{
					tens = n / 10;
					ones = n % 10;
					final = tens + (ones*16);
					cout << n << endl;
					Out32 (i, final);
					Sleep(150);
					n++;
					if (n == 100) n = 0;
				} 
				while(!kbhit());
				cout << endl;
				system("PAUSE");
          } 
		  else if (choice == 3)
          {
          		system("cls");
          		n = 0;
          		do
          		{
					tens = n / 10;
					ones = n % 10;
					final = tens + (ones*16);
					cout << n << endl;
					Out32 (i, final);
					Sleep(150);
					n+=3;
					if (n > 99) 
						n = 0;
				}
				while(!kbhit());
				cout << endl;
				system("PAUSE");
          }
          cin.get();
          cout << endl; 
     } 
	 while (choice != 0);
     cout << endl;
     cout <<"Goodbye!!!";
     getch();
}

void test_write_datum(short datum) {
     short x;
     int i;

     i=PPORT_BASE;
     x = datum;

     /*****  Write the data register */
     Out32(i,x);

     printf("\nPort write to 0x%X, datum=0x%2X\n" ,i ,x);

     /***** And read back to verify  */
     x = Inp32(i);
     printf("Port read (%04X)= %04X\n",i,x);
     getch ();
}

