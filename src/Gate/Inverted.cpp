/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Inverted.hpp"

Inverted::Inverted(size_t in, size_t output)
{
    _output = output;
    _input =in;
}

void Inverted::dump() const
{
    std::cout << "Component: " << _input
              << " INVERTED " << std::endl;
}

nts::Tristate Inverted::compute(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::TRUE)
        return nts::FALSE;
    return nts::TRUE;
}

nts::Tristate Inverted::calculThat(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::TRUE)
        return nts::FALSE;
    return nts::TRUE;
}