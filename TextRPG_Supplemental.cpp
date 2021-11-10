// TextRPG_Supplemental.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Enemy.h"
#include "Player.h"

using namespace std;

void test() {
  Player player;
  cout << player.getsound() << endl;
  cout << player.gethealth() << endl;
  Player player2(5, 1, "Jeff", "AHH!");
  cout << player2.getsound() << endl;
  cout << player2.gethealth() << endl;
  Enemy enemy;
  cout << player2.getsound() << endl;
  cout << player2.gethealth() << endl;
  cout << enemy.getsound() << endl;
  cout << enemy.gethealth() << endl;
}

int main() {
  cout << "Do you want to play." << endl;
  cout << "0: Play\n1: Exit" << endl;
  int option;
  cin >> option;

  bool start = true;
  while (start) {
    switch (option) {
      case 0:
        test();
        cout << "\nDo you want to play again\n0: Play\n1: Exit" << endl;
        cin >> option;
        break;
      case 1:
        cout << "Darn. See you later." << endl;
        start = false;
        return 0;
      default:
        cout << "Incorrect Input, try again" << endl;
        cin >> option;
    }
  }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add
//   Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project
//   and select the .sln file
