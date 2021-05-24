//
// Created by Kotov on 23.05.2021.
//

#ifndef SEABATTLE_CONTROLLER_H
#define SEABATTLE_CONTROLLER_H
#include <string>
#include "Printing.h"
#include "Data.h"

class Controller {
private:
    Printing& own_field;
    Printing& opponnent_field;

    bool is_correct_place(size_t x, size_t y);

public:
    explicit  Controller(Printing& new_own_field, Printing& new_opponnent_field);

    bool get_cell(size_t &x, size_t &y);

    bool set_ship(size_t x, size_t y, size_t ship_size, std::string& direction);

    bool make_shot(size_t x, size_t y);

    void show_own_field();

    std::string get_status(size_t x, size_t y);
};

#endif //SEABATTLE_CONTROLLER_H
