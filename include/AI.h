//
// Created by Kotov on 09.05.2021.
//

#ifndef SEABATTLE_AI_H
#define SEABATTLE_AI_H

#include <iostream>
#include <set>
#include "Printing.h"
#include "Controller.h"

class AI {
private:
    Controller controller;
    std::set<std::pair<size_t, size_t>> shots;

    void set_ships();

public:
    AI(Printing &new_own_field, Printing &new_opponnent_field);

    std::pair<std::pair<size_t, size_t>, std::pair<bool, bool>> make_shot();

    size_t get_kills();
};

#endif //SEABATTLE_AI_H
