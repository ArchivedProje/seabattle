//
// Created by Kotov on 10.05.2021.
//

#include "Player.h"

Player::Player(Printing &new_own_field, Printing &new_opponnent_field) : controller(new_own_field, new_opponnent_field) {}

void Player::make_shot() {
    controller.make_shot();
}



