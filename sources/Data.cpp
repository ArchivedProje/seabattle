//
// Created by Kotov on 17.05.2021.
//
#include "Data.h"

void add_ships(std::set<std::pair<size_t, size_t>> &coordinates, size_t size) {
    ships[coordinates] = size;
}

std::map<std::set<std::pair<size_t, size_t>>, size_t> &get_ships() {
    return ships;
}

void set_ships(std::map<std::set<std::pair<size_t, size_t>>, size_t> &new_ships) {
    ships = new_ships;
}
