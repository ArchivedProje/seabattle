//
// Created by Kotov on 17.05.2021.
//
#include "Data.h"

void data::add_ships(std::set<std::pair<size_t, size_t>> &coordinates, std::pair<size_t, std::string> &&size_name) {
    ships[coordinates] = {size_name.first, size_name.second};
}

std::map<std::set<std::pair<size_t, size_t>>, std::pair<size_t, std::string>> &data::get_ships() {
    return ships;
}

void data::set_ships(std::map<std::set<std::pair<size_t, size_t>>, std::pair<size_t, std::string>> &new_ships) {
    ships = new_ships;
}
