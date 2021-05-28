//
// Created by Kotov on 23.05.2021.
//

#include "Controller.h"


Controller::Controller(Printing &new_own_field, Printing &new_opponnent_field) : own_field(new_own_field),
                                                                                 opponnent_field(new_opponnent_field),
                                                                                 count_kills(0) {}

bool Controller::set_ship(size_t x, size_t y, size_t ship_size, std::string &direction, std::string &&which) {
    if (is_correct_place(x, y)) {
        std::pair<size_t, bool> x_left = own_field.get_distance(x, y, 'x', "left");
        std::pair<size_t, bool> x_right = own_field.get_distance(x, y, 'x', "right");
        std::pair<size_t, bool> y_up = own_field.get_distance(x, y, 'y', "up");
        std::pair<size_t, bool> y_down = own_field.get_distance(x, y, 'y', "down");
        std::set<std::pair<size_t, size_t>> coordinates;
        bool empty = true;
        if ((direction == "nothing" || direction == "right") &&
            (x_right.first > ship_size || (x_right.second && x_right.first >= ship_size))) {
            for (size_t j = x; j < x + ship_size; ++j) {
                empty = empty && is_correct_place(j, y);
                if (!empty) {
                    break;
                }
            }
            if (empty) {
                for (size_t j = x; j < x + ship_size; ++j) {
                    own_field.set_status(j, y, "ship");
                    coordinates.insert(std::make_pair(j, y));
                }
                data::add_ships(coordinates, {ship_size, which});
                return true;
            }
        }
        if ((direction == "nothing" || direction == "left") &&
            (x_left.first > ship_size || (x_left.second && x_left.first >= ship_size))) {
            for (size_t j = x, k = 0; k < ship_size; --j, ++k) {
                empty = empty && is_correct_place(j, y);
                if (!empty) {
                    break;
                }
            }
            if (empty) {
                for (size_t j = x, k = 0; k < ship_size; --j, ++k) {
                    own_field.set_status(j, y, "ship");
                    coordinates.insert(std::make_pair(j, y));
                }
                data::add_ships(coordinates, {ship_size, which});
                return true;
            }
        }
        if ((direction == "nothing" || direction == "down") &&
            (y_up.first > ship_size || (y_up.second && y_up.first >= ship_size))) {
            for (size_t j = y; j < y + ship_size; ++j) {
                empty = empty && is_correct_place(x, j);
                if (!empty) {
                    break;
                }
            }
            if (empty) {
                for (size_t j = y; j < y + ship_size; ++j) {
                    own_field.set_status(x, j, "ship");
                    coordinates.insert(std::make_pair(x, j));
                }
                data::add_ships(coordinates, {ship_size, which});
                return true;
            }
        }
        if ((direction == "nothing" || direction == "up") &&
            (y_down.first > ship_size || (y_down.second && y_down.first >= ship_size))) {
            for (size_t j = y, k = 0; k < ship_size; --j, ++k) {
                empty = empty && is_correct_place(x, j);
                if (!empty) {
                    break;
                }
            }
            if (empty) {
                for (size_t j = y, k = 0; k < ship_size; --j, ++k) {
                    own_field.set_status(x, j, "ship");
                    coordinates.insert(std::make_pair(x, j));
                }
                data::add_ships(coordinates, {ship_size, which});
                return true;
            }
        }
    }
    return false;
}

bool Controller::is_correct_place(size_t x, size_t y) {
    bool correct = true;
    for (int i = -1; i < 2; ++i) {
        if (static_cast<int>(x + i) >= 0 && static_cast<int>(x + i) < 10) {
            x += i;
        } else {
            continue;
        }
        correct = correct && (own_field.get_status(x, y) == "empty");
        if (y < 9) {
            ++y;
            correct = correct && (own_field.get_status(x, y) == "empty");
            --y;
        }
        if (y > 0) {
            --y;
            correct = correct && (own_field.get_status(x, y) == "empty");
            ++y;
        }
        x -= i;
        if (!correct) {
            return false;
        }
    }
    return true;
}

bool Controller::get_cell(size_t &x, size_t &y) {
    std::string input;
    std::cout << "Enter cell" << std::endl;
    std::cin >> input;
    try {
        y = std::stoi(input.substr(1, input.size() - 1));
        if (y == 0) {
            std::cout << "Wrong input" << std::endl;
            return false;
        }
        --y;
    } catch (std::exception &) {
        std::cout << "Wrong input" << std::endl;
        return false;
    }
    if (input[0] < 'A' || input[0] > 'J') {
        std::cout << "Wrong input" << std::endl;
        return false;
    }
    x = static_cast<size_t>(input[0] - 65);
    return true;
}

std::pair<bool, bool> Controller::make_shot(size_t x, size_t y, std::string &&who) {
    return opponnent_field.shot(x, y, std::move(who));
}

void Controller::show_own_field() {
    own_field.show(true);
}

std::string Controller::get_status(size_t x, size_t y) {
    return opponnent_field.get_status(x, y);
}

void Controller::increase_kills() {
    ++count_kills;
}

size_t Controller::get_kills() {
    return count_kills;
}



