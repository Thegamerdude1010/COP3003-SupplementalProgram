// TextRPG_Supplemental.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Enemy.h"
#include "Player.h"

using namespace std;

void start_game();

void battle_cry(Player);

int main() {
  cout << "Do you want to play." << endl;
  cout << "0: Play\n1: Exit" << endl;
  int option;
  try {
    cin >> option;
    // Source:
    // https://stackoverflow.com/questions/11523569/how-can-i-avoid-char-input-for-an-int-variable
    if (cin.fail()) {
      cin.clear();                // clears cin
      cin.ignore(INT_MAX, '\n');  // ignores input
      option = -1;
      throw 1.1;
    }
  }  // while I am not catching am exception, C++ allows you to throw any
     // object, so I threw a double in this case.
  catch (double) {
    cout << "You didn't enter a number! You can't do that!" << endl;
  }
  bool start = true;
  while (start) {
    switch (option) {
      case 0:
        start_game();
        cout << "\nDo you want to play again\n0: Play\n1: Exit" << endl;
        cin >> option;
        break;

      case 1:
        cout << "Darn. See you later." << endl;
        start = false;
        break;

      default:
        cout << "Incorrect Input, try again" << endl;
        cin >> option;
    }
  }
  return 0;
}

void start_game() {
  string name;
  string sound;
  cout << "What is your name?" << endl;
  cin >> name;
  cout << "What is your battlecry?" << endl;
  cin >> sound;
  Player player(name, sound);
  battle_cry(player);

  int a;
  cout << "Charge attack: Enter the amount to attack!" << endl;

  try {
    cin >> a;
    // Source:
    // https://stackoverflow.com/questions/11523569/how-can-i-avoid-char-input-for-an-int-variable
    if (cin.fail()) {
      cin.clear();                // clears cin
      cin.ignore(INT_MAX, '\n');  // ignores input
      throw string("NOT AN INTEGER");
    }
    player.setattack(a);
  }
  // If the attack entered is too big, the setattack function throws an int,
  // which is caught here. This demonstrates exception handling.
  catch (int) {
    cout << "Uh oh! Your attack was to powerful and you blew up the universe!"
         << endl;
  }
  // I have this set up to catch a string if cin fails when someone does not
  // enter an integer.
  catch (string &e) {
    cout << e << "\nYou can't enter that silly! Now the game is over." << endl;
  }
}

void battle_cry(Player p) { cout << p.battle_cry << endl; }

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
