//
// Created by Kotov on 17.05.2021.
//

#ifndef SEABATTLE_DATA_H
#define SEABATTLE_DATA_H
#include <map>
#include <set>

static std::map<std::set<std::pair<size_t, size_t>>, size_t> ships; //player's ships

void add_ships(std::set<std::pair<size_t, size_t>> &coordinates, size_t size);

std::map<std::set<std::pair<size_t, size_t>>, size_t> &get_ships();

void set_ships(std::map<std::set<std::pair<size_t, size_t>>, size_t> &new_ships);


#endif //SEABATTLE_DATA_H
