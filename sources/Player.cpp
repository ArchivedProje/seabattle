//
// Created by Kotov on 10.05.2021.
//

#include "Player.h"

Player::Player(Printing &new_own_field, Printing &new_opponnent_field) : controller(new_own_field,
                                                                                    new_opponnent_field) {
    set_ships();
}

std::pair<std::pair<size_t, size_t>, std::pair<int, bool>> Player::make_shot() {
    size_t x;
    size_t y;
    if (controller.get_cell(x, y)) {
        std::pair<int, bool> shot = controller.make_shot(x, y, "player");
        if (shot.second) {
            controller.increase_kills();
        }
        return {{x, y}, shot};
    } else {
        return {{x, y}, {-1, false}};
    }
}

void Player::set_ships() {
    std::cout << "Hi, now you should place your ships" << std::endl;
    std::cout << "You can enter 'auto' or 'manual'" << std::endl;
    std::string input;
    std::cin >> input;
    while (input != "auto" && input != "manual") {
        std::cout << "Wrong input. Try again" << std::endl;
        std::cin >> input;
    }
    for (size_t i = 1; i < 5; ++i) {
        size_t k = 0;
        while (k < 5 - i) {
            if (input == "manual") {
                controller.show_own_field();
                std::cout << "Size: " << i << std::endl;
                size_t x;
                size_t y;
                if (controller.get_cell(x, y)) {
                    std::string direction = "nothing";
                    if (i > 1) {
                        std::cout << "Enter direction" << std::endl;
                        std::cin >> direction;
                        while (direction != "left" && direction != "right" && direction != "up" &&
                               direction != "down") {
                            std::cout << "Wrong direction, try again!" << std::endl;
                            std::cin >> direction;
                        }
                    }
                    if (controller.set_ship(x, y, i, direction, "player")) {
                        ++k;
                    } else {
                        std::cout << "Wrong input" << std::endl;
                    }
                }
            } else {
                auto cell_direction = controller.get_random_cell_direction();
                if (controller.set_ship(cell_direction.first.first, cell_direction.first.second, i, cell_direction.second, "computer")) {
                    ++k;
                }
            }
        }
    }
}

size_t Player::get_kills() {
    return controller.get_kills();
}
