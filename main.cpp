#include "Printing.h"
#include "AI.h"
#include "Player.h"
#include <iostream>

int main() {
    std::system("color F0" );
    Printing player_field(std::cout);
    Printing computer_filed(std::cout);
    //AI computer(computer_filed, player_field);
    Player player (player_field, computer_filed);
    /*while (true) {
        computer_filed.show(true);
        player.make_shot();
    }*/
    return 0;
}
