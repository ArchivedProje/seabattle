//
// Created by Kotov on 10.05.2021.
//

#include "Player.h"

Player::Player(Printing &new_own_field, Printing &new_opponnent_field) : controller(new_own_field, new_opponnent_field) {
    set_ships();
}

std::pair<std::pair<size_t, size_t>, bool> Player::make_shot() {
    size_t x;
    size_t y;
    controller.get_cell(x, y);
    return {{x, y}, controller.make_shot(x, y)};
}

void Player::set_ships() {
    std::cout << "Hi, now you should set your ships" << std::endl;
    for (size_t i = 1; i < 5; ++i) {
        size_t k = 0;
        while (k < 5 - i) {
            controller.show_own_field();
            std::cout << "Size: " << i << std::endl;
            size_t x;
            size_t y;
            if (controller.get_cell(x, y)) {
                std::string direction = "nothing";
                if (i > 1) {
                    std::cout << "Enter direction" << std::endl;
                    std::cin >> direction;
                    while (direction != "left" && direction != "right" && direction != "up" && direction != "down") {
                        std::cout << "Wrong direction, try again!" << std::endl;
                        std::cin >> direction;
                    }
                }
                if (controller.set_ship(x, y, i, direction)) {
                    ++k;
                } else {
                    std::cout << "Wrong input" << std::endl;
                }
            }
        }
    }
}



