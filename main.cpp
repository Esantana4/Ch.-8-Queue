/*
 Erik Santana
 10/23/23
 CPMR 131 - Professor Q

 Credit:
 Part 1:
 Part 2:
 Part 3:
 */

#include "input.h"
#include<queue>
using namespace std;

void mainMenu();

int main()
{
    mainMenu();

    return 0;
}

// Pre-Condition: NA
// Post-Condition: no return. Main menu
void mainMenu()
{


    cout << endl;
    cout << "\tCMPR131 - Chapter 8: Applications using Queues by Erik Santana (10 / 20/ 23)";
    cout << "\n\t" << string(80, char(205)) << endl;
    cout << "\t1> Simulation of War (card game) using deque STL" << endl;
    cout << "\t2> Simulation of an emergency room (ER) using priority queue STL" << endl;
    cout << "\t3> Simulation of checkout lines at CostCo using multiple queues STL" << endl;
    cout << "\n\t" << string(80, char(169));
    cout << "\n\t0 > exit" << endl;
    cout << "\n\t" << string(80, char(205)) << endl;

    // get user input/option of main menu
    int option = inputInteger("\n\tOption: ", 0, 3);

    // loop through main menu until user exits
    do
    {
        switch (option)
        {
            case 0: exit(1); break;
            case 1:
            {
                system("cls");  
                break;
            }
            case 2:
            {
                system("cls");  
                break;
            }
            case 3:
            {
                system("cls");  
                break;
            }
        }
        system("pause");
        // new line
        cout << "\n";

    } while (true);
}