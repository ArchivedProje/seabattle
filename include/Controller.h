//
// Created by Kotov on 23.05.2021.
//

#ifndef SEABATTLE_CONTROLLER_H
#define SEABATTLE_CONTROLLER_H
#include "Printing.h"
#include "Data.h"

class Controller {
private:
    Printing& own_field;
    Printing& opponnent_field;

    bool is_correct_place(size_t x, size_t y);

    void get_cell(char &x, size_t &y);
public:
    explicit  Controller(Printing& new_own_field, Printing& new_opponnent_field);

    bool set_ship(size_t x, size_t y, size_t ship_size);

    void make_shot();

};

#endif //SEABATTLE_CONTROLLER_H
