//
// Created by Kotov on 10.05.2021.
//

#ifndef SEABATTLE_PLAYER_H
#define SEABATTLE_PLAYER_H

#include "Printing.h"
#include "Controller.h"

class Player {
    Controller controller;

    void get_cell(char &x, size_t &y);

public:
    Player(Printing &new_own_field, Printing &new_opponnent_field);

    void make_shot();
};

#endif //SEABATTLE_PLAYER_H
