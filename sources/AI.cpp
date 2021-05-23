//
// Created by Kotov on 09.05.2021.
//


#include "AI.h"

AI::AI(Printing &new_own_field, Printing &new_opponnent_field) : controller(new_own_field, new_opponnent_field) {
    set_ships();
}

void AI::set_ships() {
    std::mt19937 random(std::chrono::steady_clock::now().time_since_epoch().count());
    for (size_t i = 1; i < 5; ++i) {
        size_t k = 0;
        while (k < 5 - i) {
            size_t x = random() % 10;
            size_t y = random() % 10;
            if (controller.set_ship(x, y, i)) {
                ++k;
            }
        }
    }
}
