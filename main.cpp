#include "Printing.h"
#include "AI.h"
#include "Player.h"
#include <iostream>
#include <windows.h>

void draw(Printing& player_field, Printing& computer_field) {
    std::cout << "Your field:" << std::endl;
    player_field.show(true);
    std::cout << "Computer's field:" << std::endl;
    computer_field.show();
}

int main() {
    std::system("color F0" );
    Printing player_field(std::cout);
    Printing computer_field(std::cout);
    AI computer(computer_field, player_field);
    Player player (player_field, computer_field);
    std::pair<std::pair<size_t, size_t>, bool> computers_shot = {{0, 0}, false};
    std::pair<std::pair<size_t, size_t>, bool> players_shot = {{0, 0}, false};
    while (true) {
        draw(player_field, computer_field);
        if (!computers_shot.second) {
            players_shot = player.make_shot();
        }
        draw(player_field, computer_field);
        if (!players_shot.second) {
            std::cout << "Computer makes shot" << std::endl;
            Sleep(700);
            computers_shot = computer.make_shot();
            std::cout << "Computer shot in " << static_cast<char>(computers_shot.first.first + 65)
                      << computers_shot.first.second + 1 << std::endl;
            Sleep(700);
        }
    }
    return 0;
}
