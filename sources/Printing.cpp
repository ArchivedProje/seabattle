
#include "Printing.h"


Printing::Printing(std::ostream &new_stream) : stream(new_stream) {
    symbols["miss"] = "*";
    symbols["hit"] = "x";
    symbols["ship"] = "s";
    symbols["empty"] = "_";
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            map_status[{i, j}] = symbols["empty"];
        }
    }
    update_map();
}

void Printing::cls() {
    map.str(std::string());
}

void Printing::show(bool with_ships) const {
    if (with_ships) {
    stream << map.str();
    } else {
        for (auto& symbol : map.str()) {
            if (symbol == 's') {
                symbol = '_';
            }
            stream << symbol;
        }
    }
}

void Printing::set_status(const size_t x, const size_t y, const std::string &status) {
    map_status[{x, y}] = symbols[status];
    update_map();
}

void Printing::update_map() {
    cls();
    map << std::setw(5) << "A" << std::setw(2) << "B" << std::setw(2) << "C" << std::setw(2) << "D" << std::setw(2)
        << "E" << std::setw(2) << "F" << std::setw(2) << "G" << std::setw(2) << "H" << std::setw(2) << "I"
        << std::setw(2) << "J" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        map << std::setw(2) << std::right << i + 1 << " |";
        for (size_t j = 0; j < 10; ++j) {
            map << map_status[{j, i}] << "|";
        }
        map << std::endl;
    }
}

std::string Printing::get_status(const size_t x, const size_t y) const {
    try {
        std::string status = map_status.at({x, y});
        for (const auto &item : symbols) {
            if (item.second == status) {
                return item.first;
            }
        }
    } catch (std::out_of_range& ) {
        std::cerr << x << ' ' << y << " Out" << std::endl;
    }
    return "unknown";
}

std::pair<size_t, bool>  Printing::get_distance(size_t x, size_t y, const char coordinate, const std::string &direction, bool check_current) const {
    size_t distance = 0;
    bool end = false;
    if (check_current) {
        if (get_status(x, y) != "empty") {
            return {distance, end};
        }
        ++distance;
    }
    if (coordinate == 'x') {
        if (direction == "right") {
            while (x < 9) {
                ++x;
                if (get_status(x, y) == "empty") {
                    ++distance;
                } else {
                    break;
                }
            }
        } else {
            while (x > 0) {
                size_t k = x - 1;
                if (get_status(k, y) == "empty") {
                    ++distance;
                } else {
                    break;
                }
                --x;
            }
        }
    } else {
        if (direction == "up") {
            while (y < 9) {
                ++y;
                if (get_status(x, y) == "empty") {
                    ++distance;
                } else {
                    break;
                }
            }
        } else {
            while (y > 0) {
                size_t k = y - 1;
                if (get_status(x, k) == "empty") {
                    ++distance;
                } else {
                    break;
                }
                --y;
            }
        }
    }
    if (x == 9 || y == 9 || x == 0 || y == 0) {
        end = true;
    }
    return {distance, end};
}

bool Printing::shot(size_t x, size_t y) {
    try {
        if (map_status.at({x, y}) == symbols["ship"]) {
            map_status.at({x, y}) = symbols["hit"];
            dead(x, y);
            update_map();
            return true;
        } else if (map_status.at({x, y}) == symbols["empty"]) {
            map_status.at({x, y}) = symbols["miss"];
            update_map();
        } else {
            std::cout << "You have already shot here" << std::endl;
        }
    } catch (std::out_of_range&) {
        std::cout << "Wrong input" << std::endl;
        return false;
    }
    return false;
}

void Printing::dead(size_t x, size_t y) {
    auto ships = get_ships();
    for (auto& item : ships) {
        if (item.first.contains({x, y})) {
            --item.second;
            if (item.second == 0) {
                for (auto& coordinates : item.first) {
                    for (int i = -1; i < 2; ++i) {
                        size_t new_x = coordinates.first;
                        size_t new_y = coordinates.second;
                        if (static_cast<int>(new_x + i) < 10 && static_cast<int>(new_x + i) > -1) {
                            new_x += i;
                        } else {
                            continue;
                        }
                        if (!item.first.contains({new_x, new_y})) {
                            set_status(new_x, new_y, "miss");
                        }
                        if (new_y < 9) {
                            ++new_y;
                            if (!item.first.contains({new_x, new_y})) {
                                set_status(new_x, new_y, "miss");
                            }
                            --new_y;
                        }
                        if (new_y > 0) {
                            --new_y;
                            if (!item.first.contains({new_x, new_y})) {
                                set_status(new_x, new_y, "miss");
                            }
                            ++new_y;
                        }
                        new_x -= i;
                    }
                }
                ships.erase(item.first);
            }
        }
    }
    set_ships(ships);
}
