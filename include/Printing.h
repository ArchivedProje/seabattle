//
// Created by Kotov on 09.05.2021.
//

#ifndef SEABATTLE_PRINTING_H
#define SEABATTLE_PRINTING_H

#include <ostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <iostream>
#include "Data.h"

class Controller;

class Printing {
private:
    friend class Controller;
    std::ostream &stream;
    std::stringstream map;
    std::map<std::string, std::string> symbols;
    std::map<std::pair<size_t, size_t>, std::string> map_status;

    void update_map();

    void set_status(const size_t x, const size_t y, const std::string& status);

    std::string get_status(const size_t x, const size_t y) const;

    std::pair<size_t, bool> get_distance(size_t x, size_t y, const char coordinate, const std::string& direction, bool check_current = true) const;

public:
    explicit Printing(std::ostream &new_stream);

    void shot(size_t x, size_t y);

    void dead(size_t x, size_t y);

    void cls();

    void show(bool with_ships = false) const;
};

#endif //SEABATTLE_PRINTING_H
