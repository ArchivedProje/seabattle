//
// Created by Kotov on 09.05.2021.
//


#include "AI.h"

AI::AI(Printing &new_own_field, Printing &new_opponnent_field) : controller(new_own_field, new_opponnent_field) {
    set_ships();
}

void AI::set_ships() {
    std::mt19937 random(std::chrono::steady_clock::now().time_since_epoch().count());
    std::string direction = "nothing";
    for (size_t i = 1; i < 5; ++i) {
        size_t k = 0;
        while (k < 5 - i) {
            size_t x = random() % 10;
            size_t y = random() % 10;
            if (controller.set_ship(x, y, i, direction)) {
                ++k;
            }
        }
    }
}

std::pair<std::pair<size_t, size_t>, bool> AI::make_shot() {
    auto ships = get_ships();
    std::mt19937 random(std::chrono::steady_clock::now().time_since_epoch().count());
    while (true) {
        size_t shift = random() % 5;
        size_t iter = 0;
        for (auto &item : ships) {
            for (auto &coordinates : item.first) {
                if (controller.get_status(coordinates.first, coordinates.second) == "ship") {
                    if (iter == shift) {
                        int error_x;
                        int error_y;
                        int coordinate_x;
                        int coordinate_y;
                        do {
                            error_x = random() % 3 - 1;
                            error_y = random() % 3 - 1;
                            coordinate_x = static_cast<int>(coordinates.first) + error_x;
                            coordinate_y = static_cast<int>(coordinates.second) + error_y;
                        } while (coordinate_x < 0 || coordinate_x > 9 || coordinate_y < 0 || coordinate_y > 9 ||
                                 shots.contains({coordinate_x, coordinate_y}));
                        shots.insert({coordinate_x, coordinate_y});
                        return {{coordinate_x, coordinate_y},
                                controller.make_shot(coordinates.first + error_x, coordinates.second + error_y)};
                    } else {
                        ++iter;
                    }
                }
            }
        }
    }
}
