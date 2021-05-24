//
// Created by Kotov on 10.05.2021.
//

#ifndef SEABATTLE_PLAYER_H
#define SEABATTLE_PLAYER_H

#include "Printing.h"
#include "Controller.h"

class Player {
    Controller controller;

    void set_ships();

public:
    Player(Printing &new_own_field, Printing &new_opponnent_field);

    std::pair<std::pair<size_t, size_t>, bool> make_shot();
};

#endif //SEABATTLE_PLAYER_H
