//
// Created by Kotov on 17.05.2021.
//

#ifndef SEABATTLE_DATA_H
#define SEABATTLE_DATA_H

#include <map>
#include <set>
#include <string>


namespace data {
    static std::map<std::set<std::pair<size_t, size_t>>, std::pair<size_t, std::string>> ships; //player's ships

    void add_ships(std::set<std::pair<size_t, size_t>> &coordinates, std::pair<size_t, std::string> &&size_name);

    std::map<std::set<std::pair<size_t, size_t>>, std::pair<size_t, std::string>> &get_ships();

    void set_ships(std::map<std::set<std::pair<size_t, size_t>>, std::pair<size_t, std::string>> &new_ships);
}

#endif //SEABATTLE_DATA_H
