//
// Created by Kotov on 09.05.2021.
//

#ifndef SEABATTLE_AI_H
#define SEABATTLE_AI_H

#include <random>
#include <chrono>
#include <iostream>
#include <set>
#include "Printing.h"
#include "Controller.h"

class AI {
private:
    Controller controller;

    void set_ships();

public:
    AI(Printing &new_own_field, Printing &new_opponnent_field);
};

#endif //SEABATTLE_AI_H
