#include "Printing.h"
#include "AI.h"
#include "Player.h"
#include <iostream>
#include <windows.h>

void draw(Printing &player_field, Printing &computer_field) {
    std::cout << "Your field:" << std::endl;
    player_field.show(true);
    std::cout << "Computer's field:" << std::endl;
    computer_field.show();
}

int main() {
    std::cout << "Here you can find a simple tutorial about this game - https://github.com/byteihq/seabattle" << std::endl;
    Printing player_field(std::cout);
    Printing computer_field(std::cout);
    AI computer(computer_field, player_field);
    Player player(player_field, computer_field);
    std::pair<std::pair<size_t, size_t>, std::pair<bool, bool>> computers_shot = {{0,     0},
                                                                                  {false, false}};
    std::pair<std::pair<size_t, size_t>, std::pair<int, bool>> players_shot = {{0, 0},
                                                                               {0, false}};
    while (computer.get_kills() < 10 && player.get_kills() < 10) {
        draw(player_field, computer_field);
        if (!computers_shot.second.first) {
            players_shot = player.make_shot();
            if (players_shot.second.second) {
                std::cout << "You destroyed ship" << std::endl;
            }
        }
        if (players_shot.second.first == 0) {
            std::cout << "You miss" << std::endl;
            std::cout << "Computer makes shot" << std::endl;
            Sleep(1000);
            computers_shot = computer.make_shot();
            std::cout << "Computer shot in " << static_cast<char>(computers_shot.first.first + 65)
                      << computers_shot.first.second + 1 << std::endl;
            if (computers_shot.second.second) {
                std::cout << "Computer destroyed your ship" << std::endl;
            }
            Sleep(1000);
        } else if (players_shot.second.first == 1 && !players_shot.second.second) {
            std::cout << "You hit" << std::endl;
        } else if (!players_shot.second.second) {
            std::cout << "Try again" << std::endl;
        }
    }
    if (computer.get_kills() == 10) {
        std::cout << "You lose" << std::endl;
    } else {
        std::cout << "You won" << std::endl;
    }

    return 0;
}
