/** @file TextRPG_Supplemental.cpp
 *
 *  @brief Main file of the project.
 *
 *  This is the main file of the project. It holds the main function, and the
 functions that run the game. Most of the code is included in this file. LO4 and
 LO5 are included in the README.
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

/** @brief This function tests input.
 *
 *  When someone enters something, it may be wrong. This function tests if a
 * person enters an int. If they don't, it throws an exception. This allows the
 * program to ask for more input without crashing. It also demonstrates
 * exception handling.
 *
 *  @param int &option; passing an int by reference allows me to test input and
 * send the input back
 *  @return void
 */
void input_test(int &option);

/** @brief This function runs the game.
 *
 *  This function is the main part of the game. It handles the main logic and
 * pathways for the game.
 *
 *  @return void
 */
void run_game();

/** @brief Function for main menu.
 *
 *  This function handles the main menu. It allows the user to start a game or
 * exit the program. It repeates until the user exits the program.
 *
 *  @return void
 */
void start_game();

/** @brief Gets the player battle cry.
 *
 *  This function gets the players battle cry. It is a friend function of the
 * Player class.
 *
 *  @param Player p; an object of class player is passed in order to get the
 * battle cry.
 *  @return void
 */
void battle_cry(Player p);

/** @brief Allows user to enter a charge attack.
 *
 *  This function allows the user to enter their own attack number. It uses the
 * Player classes set_attack function.
 *
 *  @param Player player; A Player object is passed by references so the attack
 * can be modified.
 *  @return void
 */
void charge_attack(Player &player);

/** @brief Spawns a small enemy.
 *
 *  This function is included to shorten code. I do not have to create an object
 * everytime I need to, I just call this function. Uses trailing return type.
 *
 *  @return Return an object of class Enemy.
 */
// https://www.fluentcpp.com/2021/04/16/trailing-return-types/
auto spawn_small_enemy() -> Enemy;

/** @brief Spawns a big enemy.
 *
 *  This function is included to shorten code. I do not have to create an object
 * everytime I need to, I just call this function. Uses trailing return type.
 *
 *  @return An object of class Enemy
 */
auto spawn_big_enemy() -> Enemy;

/** @brief Spawns a boss.
 *
 *  This function is included to shorten code. I do not have to create an object
 * everytime I need to, I just call this function. Uses trailing return type.
 *
 *  @return An object of class Enemy
 */
auto spawn_boss() -> Enemy;

/** @brief Handles main encounters.
 *
 *  This function handles the main encounters. Users have the ability to attack
 * or defend. If they do not enter a correct input they die. Passing player by
 * reference lets us adjust the values of our original object. The enemy can be
 * passed by value because either the enemy dies or the game ends, so we don't
 * have to modify the enemy.
 *
 *  @param Enemy enemy; object of class Enemy
 *  @param Player player; Object of class player passed by reference
 *  @return void
 */
void encounter(Enemy enemy, Player &player);

/** @brief Handles the final encounter.
 *
 *  Handles the final encounter. The user gets three option, adding a charge
 * attack. The game ends when the enemy in this encounter is defeated.
 *
 *  @param Enemy enemy; object of class Enemy
 *  @param Player player; Object of class player passed by reference
 *  @return void
 */
void final_encounter(Enemy enemy, Player &player);

/** @brief Plays when the user beats the game.
 *
 *  This function was added to demonstrate iterators on aggregates and dynamic
 * dispatch (LO7 & LO3). It just displays some simple text at the end of the
 * game.
 *
 *  @return void
 */
void end_game();

/** @brief Calculates damage.
 *
 *  Simple function that calculates damage to demonstrate passin functions as
 * arguments (LO7).
 *
 *  @param float h; health variable
 *  @param float a; attack variable
 *  @return Returns a float, the result of h-a
 */
constexpr float damage(float h, float a);

/** @brief Main function.
 *
 *  This is the main function. All programs need a main function. It simply
 * calls the start_game function.
 *
 *  @return int; main is supposed to return an int.
 */
int main() {
  start_game();
  return 0;
}

void start_game() {
  std::cout << "Do you want to play." << std::endl;
  std::cout << "0: Play\n1: Exit" << std::endl;
  int option = -1;
  input_test(option);
  bool start = true;
  while (start) {
    switch (option) {
      case 0:
        run_game();
        std::cout << "\nDo you want to play again\n0: Play\n1: Exit"
                  << std::endl;
        input_test(option);
        break;

      case 1:
        std::cout << "Darn. See you later." << std::endl;
        start = false;
        break;

      default:
        std::cout << "Incorrect Input, try again" << std::endl;
        input_test(option);
    }
  }
}

void run_game() {
  std::string name;
  std::string sound;
  std::cout << "What is your name?" << std::endl;
  std::cin >> name;
  std::cout << "What is your battlecry?" << std::endl;
  std::cin >> sound;
  Player player(name, sound);
  std::cout << "\n"
            << player.get_name() << ":\n"
            << "Health: " << player.get_health()
            << ", Attack: " << player.get_attack() << std::endl;

  int option = -1;
  bool running = true;
  std::cout << "\nYou approach a gate. What do you do?" << std::endl;
  std::cout << "0: Look through the gate\n1: Open the gate\n2: look around"
            << std::endl;
  input_test(option);
  while (running) {
    switch (option) {
      case 0:
        std::cout << "\nAn enemy saw you and came through the gate!"
                  << std::endl;
        encounter(spawn_small_enemy(), player);
        if (player.get_health() <= 0) {
          return;
        }
        std::cout << "\nYou now enter the gate." << std::endl;
        encounter(spawn_big_enemy(), player);
        if (player.get_health() <= 0) {
          return;
        }
        std::cout << "\nThe death of the enemy attracted the final boss!"
                  << std::endl;
        final_encounter(spawn_boss(), player);
        if (player.get_health() <= 0) {
          return;
        }
        std::cout << "\nYou killed the boss! Look what's happening"
                  << std::endl;
        end_game();
        running = false;
        break;
      case 1:
        std::cout << "\nYou enter the gate." << std::endl;
        encounter(spawn_big_enemy(), player);
        if (player.get_health() <= 0) {
          return;
        }
        std::cout << "\nKilling that enemy attracted the boss!" << std::endl;
        final_encounter(spawn_boss(), player);
        if (player.get_health() <= 0) {
          return;
        }
        std::cout << "\nYou killed the boss! Look what's happening"
                  << std::endl;
        end_game();
        running = false;
        break;
      case 2:
        std::cout << "\nYou find a hole and enter it." << std::endl;
        std::cout << "\nYou fell into the bosses cave!" << std::endl;
        final_encounter(spawn_boss(), player);
        if (player.get_health() <= 0) {
          return;
        }
        std::cout << "\nYou killed the boss! Look what's happening"
                  << std::endl;
        end_game();
        running = false;
        break;
      default:
        std::cout << "Incorrect Input, try again" << std::endl;
        input_test(option);
    }
  }
}

void encounter(Enemy enemy, Player &player) {
  std::cout << "A " << enemy.get_name() << " appeared!" << std::endl;
  std::cout << "What will you do?" << std::endl;
  std::cout << "0: Attack\n1: Defend" << std::endl;
  int option = -1;
  bool alive = true;
  input_test(option);

  while (alive) {
    switch (option) {
      case 0:
        battle_cry(player);
        std::cout << "You succsesfully attacked the enemy" << std::endl;
        enemy.take_damage(enemy.get_health(), player.get_attack(), &damage);
        std::cout << "You did " << player.get_attack()
                  << " damage. The enemy now has " << enemy.get_health()
                  << " health." << std::endl;
        if (enemy.get_health() < 1) {
          alive = false;
        } else {
          std::cout << "0: Attack\n1: Defend" << std::endl;
          input_test(option);
        }
        break;
      case 1:
        std::cout << "You try and defend but you are not very good"
                  << std::endl;
        // https://appdividend.com/2019/07/15/type-conversion-in-cpp-tutorial-with-example/
        if (static_cast<float>(enemy.get_attack()) < player.get_health()) {
          player.take_damage(static_cast<float>(enemy.get_attack()));
        } else {
          player.take_damage(player.get_health());
        }

        std::cout << "You took " << enemy.get_attack()
                  << " damage. You now have " << player.get_health()
                  << " health." << std::endl;
        if (player.get_health() < 1) {
          alive = false;
        } else {
          std::cout << "0: Attack\n1: Defend" << std::endl;
          input_test(option);
        }

        break;
      default:
        std::cout << "That wasn't an option!" << std::endl;
        std::cout << "The enemy took advantage of you and killed you"
                  << std::endl;
        player.set_health(0);
        alive = false;
    }
  }
  if (enemy.get_health() <= 0) {
    std::cout << "You killed the enemy! Good Job!" << std::endl;
    std::cout
        << "You leveled up and increased your damage by 2.5 and health by 10!"
        << std::endl;
    const float newAttack = player.get_attack() + 2.5F;
    const float newHealth = player.get_health() + 10.0F;
    player.set_attack(newAttack);
    player.set_health(newHealth);
    std::cout << "\n"
              << player.get_name() << ":\n"
              << "Health: " << player.get_health()
              << ", Attack: " << player.get_attack() << std::endl;
  } else {
    std::cout << "Oh no! You died." << std::endl;
  }
}

void final_encounter(Enemy enemy, Player &player) {
  std::cout << "The " << enemy.get_name() << " appeared!" << std::endl;
  std::cout << "What will you do?" << std::endl;
  std::cout << "0: Attack\n1: Defend\n2: Charge Attack" << std::endl;
  int option = -1;
  bool alive = true;
  input_test(option);

  while (alive) {
    switch (option) {
      case 0:
        battle_cry(player);
        std::cout << "You succsesfully attacked the enemy" << std::endl;
        enemy.take_damage(enemy.get_health(), player.get_attack(), &damage);
        std::cout << "You did " << player.get_attack()
                  << " damage. The enemy now has " << enemy.get_health()
                  << " health." << std::endl;
        if (enemy.get_health() < 1) {
          alive = false;
        } else {
          std::cout << "0: Attack\n1: Defend\n2: Charge Attack" << std::endl;
          input_test(option);
        }
        break;
      case 1:
        std::cout << "You try and defend but you are not very good"
                  << std::endl;
        player.take_damage(static_cast<float>(enemy.get_attack()));
        std::cout << "You took " << enemy.get_attack()
                  << " damage. You now have " << player.get_health()
                  << " health." << std::endl;
        if (player.get_health() < 1) {
          alive = false;
        } else {
          std::cout << "0: Attack\n1: Defend\n2: Charge Attack" << std::endl;
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
          std::cout << "Uh oh! Your attack was to powerful and you blew up the "
                       "universe!"
                    << std::endl;
          player.set_health(0);
          return;
        }
        std::cout << "You succsesfully attacked the enemy" << std::endl;
        enemy.take_damage(enemy.get_health(), player.get_attack(), &damage);
        if (enemy.get_health() < 0) {
          enemy.set_health(0);
        }
        std::cout << "You did " << player.get_attack()
                  << " damage. The enemy now has " << enemy.get_health()
                  << " health." << std::endl;
        if (enemy.get_health() < 1) {
          alive = false;
        } else {
          std::cout << "0: Attack\n1: Defend\n2: Charge Attack" << std::endl;
          input_test(option);
        }
        break;
      default:
        std::cout << "That wasn't an option!" << std::endl;
        std::cout << "The enemy took advantage of you and killed you"
                  << std::endl;
        player.set_health(0);
        alive = false;
    }
  }
  if (enemy.get_health() <= 0) {
    std::cout << "You killed the enemy! Good Job!" << std::endl;
  } else {
    std::cout << "Oh no! You died." << std::endl;
  }
}

/**
 * @brief Shows Polymorphism and Iterators on aggregates. LO7 & LO3.
 *
 * I could not figure out how to clear the warnings for these.
 *
 */
void end_game() {
  // https://www.codesdope.com/cpp-stdarray/
  // The magic number warning is left because I want 10 and only 10 of each
  // object.
  std::array<Character *, 10> character{};
  std::array<Enemy *, 10> enemy{};

  for (int i = 0; i < 10; i++) {
    character[i] = enemy[i] = new Enemy(10, 4, "Enemy", "AAAA");
  }

  for (int i = 0; i < 10; i++) {
    character[i]->kill();
  }
}

void battle_cry(Player p) { std::cout << p.battle_cry << std::endl; }

void charge_attack(Player &player) {
  float a = 0;
  std::cout << "Charge attack: Enter the amount to attack!" << std::endl;

  try {
    std::cin >> a;
    // Source:
    // https://stackoverflow.com/questions/11523569/how-can-i-avoid-char-input-for-an-int-variable
    if (std::cin.fail()) {
      std::cin.clear();                // clears cin
      std::cin.ignore(INT_MAX, '\n');  // ignores input
      throw std::string("NOT AN INTEGER");
    }
  }
  // I have this set up to catch a string if cin fails when someone does not
  // enter an integer.
  catch (const std::string &e) {
    std::cout << e << "\nYou can't enter that silly! Now the game is over."
              << std::endl;
  }

  player.set_attack(a);
}

auto spawn_small_enemy() -> Enemy {
  constexpr float health = 10.0F;
  constexpr int attack = 5;
  Enemy smallenemy(health, attack, "Goblin", "RAHH!");
  return smallenemy;
}

auto spawn_big_enemy() -> Enemy {
  constexpr float health = 30.0F;
  constexpr int attack = 10;
  Enemy bigenemy(health, attack, "Hobgoblin", "GHAAARRRRR!");
  return bigenemy;
}

auto spawn_boss() -> Enemy {
  constexpr float health = 100.0F;
  constexpr int attack = 20;
  Enemy bossenemy(health, attack, "Goblin King", "ROOOAAAAAARRR!");
  return bossenemy;
}

constexpr float damage(float h, float a) { return h - a; }

void input_test(int &option) {
  try {
    std::cin >> option;
    // Source:
    // https://stackoverflow.com/questions/11523569/how-can-i-avoid-char-input-for-an-int-variable
    if (std::cin.fail()) {
      std::cin.clear();                // clears cin
      std::cin.ignore(INT_MAX, '\n');  // ignores input
      option = -1;
      constexpr double d = 1.1;
      throw d;
    }
  }  // while I am not catching an exception, C++ allows you to throw any
     // object, so I threw a double in this case.
  catch (double) {
    std::cout << "You didn't enter a number! You can't do that!" << std::endl;
  }
}