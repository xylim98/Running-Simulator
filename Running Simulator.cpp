// Running Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <ctime>
#include<windows.h>
using namespace std;


int calcPositionA(int randomNum, int position) {
    if (randomNum >= 1 && randomNum <= 5) {
        cout << " Sprint (+3)\n";
        position += 3;
    }
    else if (randomNum >= 6 && randomNum <= 7) {
        cout << " Jog (+1)\n";
        position += 1;
    }
    else if (randomNum >= 8 && randomNum <= 10) {
        cout << " Walk (-6)\n";
        position -= 6;
    }
    return position < 0 ? 0 : position;
}

int calcPositionB(int randomNum, int position) {
    if (randomNum >= 1 && randomNum <= 3) {
        cout << " Fast Sprint (+5)\n";
        position += 5;
    }
    else if (randomNum >= 4 && randomNum <= 5) {
        cout << " Run (+3)\n";
        position += 3;
    }
    else if (randomNum == 6) {
        cout << " Walk (-2)\n";
        position -= 2;
    }
    else if (randomNum >= 7 && randomNum <= 8) {
        cout << " Crawl (-4)\n";
        position -= 4;
    }
    else if (randomNum >= 9 && randomNum <= 10){
        cout << " Sleep (No movement)\n";
    }
    return position < 0 ? 0 : position;
}

void printTrack(int positionA, int positionB) {
    for (int i = 0; i <= 60; i++) {
        if (i == positionA && i == positionB) {
            cout << " GOTCHA! |";
        }
        else if (i == positionA) {
            cout << " 1 |";
        }
        else if (i == positionB) {
            cout << " 2 |";
        }
        else {
            cout << "   |";
        }

        if (i == 60 && positionA > 60) {
            cout << " 1 |";
        } else if (i == 60 && positionB > 60) {
            cout << " 2 |";
        }
    }
}


int main()
{
    int cycleTick;
    cout << "Seconds to next cycle: ";
    cin >> cycleTick;

    cout << "\n3..\n";
    Sleep(1000);
    cout << "2..\n";
    Sleep(1000);
    cout << "1..\n";
    Sleep(1000);
    cout << "\nBANG!!!\n";
    cout << "\nAND AWAY.. THEY GO... !\n\n";
    
    int positionA =0, positionB = 0;
    do {
        srand((unsigned int)time(NULL));
        int randomA = rand() % 10 + 1;
        int randomB = rand() % 10 + 1;

        cout << "Random 1: " << randomA;
        positionA = calcPositionA(randomA, positionA);
        cout << "Random 2: " << randomB;        
        positionB = calcPositionB(randomB, positionB);

        cout << "Runner #1 Position: " << positionA << "\n";
        cout << "Runner #2 Position: " << positionB << "\n";

        printTrack(positionA, positionB);

        cout << "\n\n";
        Sleep(cycleTick * 1000);
    } while (positionA < 60 && positionB < 60);

    if (positionA >= 60 && positionB >= 60) {
        cout << "IT'S A TIE!";
    } else if (positionA >= 60) {
        cout << "RUNNER #1 WINS!";
    } else if (positionB >= 60) {
        cout << "RUNNER #2 WINS!";
    }    

    cout << "\n";
    system("pause");
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
