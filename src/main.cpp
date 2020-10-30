/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Parse.hpp"
#include "Errors.hpp"

int main(int ac, char *argv[])
{
    if (ac < 2)
        return (84);
    try {
        Parse parser(argv);
    } catch (const Errors &e) {
        std::cerr << e.what() << std::endl;
        std::exit(84);
    }
    return (0);
}