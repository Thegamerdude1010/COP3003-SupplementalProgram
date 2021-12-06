/** @file filename.cpp

 *  @brief Brief description of file.

 *

 *  Longer description of file.

 *

 *  @author Jacob Holmes

 *  @bug No known bugs.

 */

#include <array>
#include <functional>
#include <iostream>
#include <string>

#include "Enemy.h"
#include "Player.h"

using namespace std;

void input_test(int &option);

void run_game();

void battle_cry(Player p);

void charge_attack(Player &player);

// https://www.fluentcpp.com/2021/04/16/trailing-return-types/
auto spawn_small_enemy() -> Enemy;

auto spawn_big_enemy() -> Enemy;

auto spawn_boss() -> Enemy;

void encounter(Enemy enemy, Player &player);
void final_encounter(Enemy enemy, Player &player);

void end_game();

float damage(float h, float a);

int main() {
  cout << "Do you want to play." << endl;
  cout << "0: Play\n1: Exit" << endl;
  int option = -1;
  input_test(option);
  bool start = true;
  while (start) {
    switch (option) {
      case 0:
        run_game();
        cout << "\nDo you want to play again\n0: Play\n1: Exit" << endl;
        input_test(option);
        break;

      case 1:
        cout << "Darn. See you later." << endl;
        start = false;
        break;

      default:
        cout << "Incorrect Input, try again" << endl;
        input_test(option);
    }
  }
  noexcept(true);
  return 0;
}

// Function that runs the game.
void run_game() {
  string name;
  string sound;
  cout << "What is your name?" << endl;
  cin >> name;
  cout << "What is your battlecry?" << endl;
  cin >> sound;
  Player player(name, sound);
  cout << "\n"
       << player.get_name() << ":\n"
       << "Health: " << player.get_health()
       << ", Attack: " << player.get_attack() << endl;

  int option = -1;
  bool running = true;
  cout << "\nYou approach a gate. What do you do?" << endl;
  cout << "0: Look through the gate\n1: Open the gate\n2: look around" << endl;
  input_test(option);
  while (running) {
    switch (option) {
      case 0:
        cout << "\nAn enemy saw you and came through the gate!" << endl;
        encounter(spawn_small_enemy(), player);
        if (player.get_health() <= 0) {
          return;
        }
        cout << "\nYou now enter the gate." << endl;
        encounter(spawn_big_enemy(), player);
        if (player.get_health() <= 0) {
          return;
        }
        cout << "\nThe death of the enemy attracted the final boss!" << endl;
        final_encounter(spawn_boss(), player);
        if (player.get_health() <= 0) {
          return;
        }
        cout << "\nYou killed the boss! Look what's happening" << endl;
        end_game();
        running = false;
        break;
      case 1:
        cout << "\nYou enter the gate." << endl;
        encounter(spawn_big_enemy(), player);
        if (player.get_health() <= 0) {
          return;
        }
        cout << "\nKilling that enemy attracted the boss!" << endl;
        final_encounter(spawn_boss(), player);
        if (player.get_health() <= 0) {
          return;
        }
        cout << "\nYou killed the boss! Look what's happening" << endl;
        end_game();
        running = false;
        break;
      case 2:
        cout << "\nYou find a hole and enter it." << endl;
        cout << "\nYou fell into the bosses cave!" << endl;
        final_encounter(spawn_boss(), player);
        if (player.get_health() <= 0) {
          return;
        }
        cout << "\nYou killed the boss! Look what's happening" << endl;
        end_game();
        running = false;
        break;
      default:
        cout << "Incorrect Input, try again" << endl;
        input_test(option);
    }
  }
}

// Passing player by reference lets us adjust the values of our original object.
// The enemy can be passed by value because either the enemy dies or the game
// ends, so we don't have to modify the enemy.
// This is the general encounter.
void encounter(Enemy enemy, Player &player) {
  cout << "A " << enemy.get_name() << " appeared!" << endl;
  cout << "What will you do?" << endl;
  cout << "0: Attack\n1: Defend" << endl;
  int option = -1;
  bool alive = true;
  input_test(option);

  while (alive) {
    switch (option) {
      case 0:
        battle_cry(player);
        cout << "You succsesfully attacked the enemy" << endl;
        enemy.take_damage(enemy.get_health(), player.get_attack(), &damage);
        cout << "You did " << player.get_attack()
             << " damage. The enemy now has " << enemy.get_health()
             << " health." << endl;
        if (enemy.get_health() < 1) {
          alive = false;
        } else {
          cout << "0: Attack\n1: Defend" << endl;
          input_test(option);
        }
        break;
      case 1:
        cout << "You try and defend but you are not very good" << endl;
        // https://appdividend.com/2019/07/15/type-conversion-in-cpp-tutorial-with-example/
        player.take_damage(static_cast<float>(enemy.get_attack()));
        cout << "You took " << enemy.get_attack() << " damage. You now have "
             << player.get_health() << " health." << endl;
        if (player.get_health() < 1) {
          alive = false;
        } else {
          cout << "0: Attack\n1: Defend" << endl;
          input_test(option);
        }

        break;
      default:
        cout << "That wasn't an option!" << endl;
        cout << "The enemy took advantage of you and killed you" << endl;
        player.set_health(0);
        alive = false;
    }
  }
  if (enemy.get_health() <= 0) {
    cout << "You killed the enemy! Good Job!" << endl;
    cout << "You leveled up and increased your damage by 2.5 and health by 10!"
         << endl;
    const float newAttack = player.get_attack() + 2.5F;
    const float newHealth = player.get_health() + 10.0F;
    player.set_attack(newAttack);
    player.set_health(newHealth);
    cout << "\n"
         << player.get_name() << ":\n"
         << "Health: " << player.get_health()
         << ", Attack: " << player.get_attack() << endl;
  } else {
    cout << "Oh no! You died." << endl;
  }
}

// This is the final encounter.
void final_encounter(Enemy enemy, Player &player) {
  cout << "The " << enemy.get_name() << " appeared!" << endl;
  cout << "What will you do?" << endl;
  cout << "0: Attack\n1: Defend\n2: Charge Attack" << endl;
  int option = -1;
  bool alive = true;
  input_test(option);

  while (alive) {
    switch (option) {
      case 0:
        battle_cry(player);
        cout << "You succsesfully attacked the enemy" << endl;
        enemy.take_damage(enemy.get_health(), player.get_attack(), &damage);
        cout << "You did " << player.get_attack()
             << " damage. The enemy now has " << enemy.get_health()
             << " health." << endl;
        if (enemy.get_health() < 1) {
          alive = false;
        } else {
          cout << "0: Attack\n1: Defend\n2: Charge Attack" << endl;
          input_test(option);
        }
        break;
      case 1:
        cout << "You try and defend but you are not very good" << endl;
        player.take_damage(static_cast<float>(enemy.get_attack()));
        cout << "You took " << enemy.get_attack() << " damage. You now have "
             << player.get_health() << " health." << endl;
        if (player.get_health() < 1) {
          alive = false;
        } else {
          cout << "0: Attack\n1: Defend\n2: Charge Attack" << endl;
          input_test(option);
        }

        break;
      case 2:
        try {
          charge_attack(player);
        }
        // If the attack entered is too big, the setattack function throws an
        // int, which is caught here. This demonstrates exception handling.
        catch (int) {
          cout << "Uh oh! Your attack was to powerful and you blew up the "
                  "universe!"
               << endl;
          player.set_health(0);
          return;
        }
        cout << "You succsesfully attacked the enemy" << endl;
        enemy.take_damage(enemy.get_health(), player.get_attack(), &damage);
        if (enemy.get_health() < 0) {
          enemy.set_health(0);
        }
        cout << "You did " << player.get_attack()
             << " damage. The enemy now has " << enemy.get_health()
             << " health." << endl;
        if (enemy.get_health() < 1) {
          alive = false;
        } else {
          cout << "0: Attack\n1: Defend\n2: Charge Attack" << endl;
          input_test(option);
        }
        break;
      default:
        cout << "That wasn't an option!" << endl;
        cout << "The enemy took advantage of you and killed you" << endl;
        player.set_health(0);
        alive = false;
    }
  }
  if (enemy.get_health() <= 0) {
    cout << "You killed the enemy! Good Job!" << endl;
  } else {
    cout << "Oh no! You died." << endl;
  }
}

// Shows Polymorphism and Iterators on aggregates
void end_game() {
  // https://www.codesdope.com/cpp-stdarray/
  // The magic number warning is left because I want 10 and only 10 of each
  // object.
  array<Character *, 10> character;
  array<Enemy *, 10> enemy;

  for (int i = 0; i < 10; i++) {
    character[i] = enemy[i] = new Enemy(10, 4, "Enemy", "AAAA");
  }

  for (int i = 0; i < 10; i++) {
    character[i]->kill();
  }
}

// Demonstrating a friend function. Friend functions are allowed to access
// private members of a class.
void battle_cry(Player p) { cout << p.battle_cry << endl; }

// This allows the user to set their own attack.
void charge_attack(Player &player) {
  float a;
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
  }
  // I have this set up to catch a string if cin fails when someone does not
  // enter an integer.
  catch (const string &e) {
    cout << e << "\nYou can't enter that silly! Now the game is over." << endl;
  }

  player.set_attack(a);
}

// Spawn an enemy. These functions are here so the code does not have to be
// repeated.
auto spawn_small_enemy() -> Enemy {
  Enemy smallenemy(10.0f, 5, "Goblin", "RAHH!");
  return smallenemy;
}

auto spawn_big_enemy() -> Enemy {
  Enemy bigenemy(30.0f, 10, "Hobgoblin", "GHAAARRRRR!");
  return bigenemy;
}

auto spawn_boss() -> Enemy {
  Enemy bossenemy(100.0f, 20, "Goblin King", "ROOOAAAAAARRR!");
  return bossenemy;
}

// Function passed as parameter to demonstrate the concept.
float damage(float h, float a) { return h - a; }

// Demonstrates exception handling. Source included.
void input_test(int &option) {
  try {
    cin >> option;
    // Source:
    // https://stackoverflow.com/questions/11523569/how-can-i-avoid-char-input-for-an-int-variable
    if (cin.fail()) {
      cin.clear();                // clears cin
      cin.ignore(INT_MAX, '\n');  // ignores input
      option = -1;
      constexpr double d = 1.1;
      throw d;
    }
  }  // while I am not catching an exception, C++ allows you to throw any
     // object, so I threw a double in this case.
  catch (double) {
    cout << "You didn't enter a number! You can't do that!" << endl;
  }
}