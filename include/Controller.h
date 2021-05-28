//
// Created by Kotov on 23.05.2021.
//

#ifndef SEABATTLE_CONTROLLER_H
#define SEABATTLE_CONTROLLER_H

#include <string>
#include <random>
#include <chrono>
#include "Printing.h"
#include "Data.h"

class Controller {
private:
    Printing &own_field;
    Printing &opponnent_field;
    size_t count_kills;

    bool is_correct_place(size_t x, size_t y);

public:
    explicit Controller(Printing &new_own_field, Printing &new_opponnent_field);

    bool get_cell(size_t &x, size_t &y);

    bool set_ship(size_t x, size_t y, size_t ship_size, std::string &direction, std::string &&which);

    std::pair<int, bool> make_shot(size_t x, size_t y, std::string &&who);

    void show_own_field();

    std::string get_status(size_t x, size_t y);

    void increase_kills();

    std::pair<std::pair<size_t, size_t>, std::string> get_random_cell_direction();

    size_t get_kills();
};

#endif //SEABATTLE_CONTROLLER_H
