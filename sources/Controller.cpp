//
// Created by Kotov on 23.05.2021.
//

#include "Controller.h"


Controller::Controller(Printing &new_own_field, Printing &new_opponnent_field) : own_field(new_own_field),
                                                                                opponnent_field(new_opponnent_field) {}

bool Controller::set_ship(size_t x, size_t y, size_t ship_size) {
    if (is_correct_place(x, y)) {
        bool set_ship = false;
        size_t x_left = own_field.get_distance(x, y, 'x', "left");
        size_t x_right = own_field.get_distance(x, y, 'x', "right");
        size_t y_up = own_field.get_distance(x, y, 'y', "up");
        size_t y_down = own_field.get_distance(x, y, 'y', "down");
        std::set<std::pair<size_t, size_t>> coordinates;
        if (x_left + x_right > ship_size) {
            bool empty = true;
            size_t shift = 1;
            while (x - x_left + shift < x + x_right) {
                size_t j = x - x_left + shift;
                for (; j < x - x_left + shift + ship_size; ++j) {
                    empty = empty && is_correct_place(j, y);
                    if (!empty) {
                        ++shift;
                        break;
                    }
                }
                if (empty) {
                    for (j = x - x_left + shift; j < x - x_left + shift + ship_size; ++j) {
                        own_field.set_status(j, y, "ship");
                        coordinates.insert(std::make_pair(j, y));
                    }
                    add_ships(coordinates, ship_size);
                    return true;
                }
            }
        }
        if (!set_ship && y_up + y_down > ship_size) {
            bool empty = true;
            size_t shift = 1;
            while (y - y_down + shift < y + y_up) {
                size_t j = y - y_down + shift;
                for (; j < y - y_down + shift + ship_size; ++j) {
                    empty = empty && is_correct_place(x, j);
                    if (!empty) {
                        ++shift;
                        break;
                    }
                }
                if (empty) {
                    for (j = y - y_down + shift; j < y - y_down + shift + ship_size; ++j) {
                        own_field.set_status(x, j, "ship");
                        coordinates.insert(std::make_pair(x, j));
                    }
                    add_ships(coordinates, ship_size);
                    return true;
                }
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

void Controller::get_cell(char &x, size_t &y) {
    std::string input;
    std::cout << "Enter cell" << std::endl;
    std::cin >> input;
    try {
        y = std::stoi(input.substr(1, input.size() - 1));
    } catch (std::exception &) {
        std::cout << "Wrong input" << std::endl;
        return;
    }
    x = input[0];
}

void Controller::make_shot() {
    char x;
    size_t y;
    get_cell(x, y);
    opponnent_field.shot(x, y);
}


