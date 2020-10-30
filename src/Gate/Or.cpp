/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Or.hpp"

Or::Or(size_t in, size_t inp, size_t output)
{
    _output = output;
    _input1 =in;
    _input2 = inp;
}

void Or::dump() const
{
    std::cout << "Component: " << _input1 << "and component: " << _input2
              << " OR " << std::endl;
}

nts::Tristate Or::compute(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED || two == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::FALSE && two == nts::FALSE)
        return nts::FALSE;
    return nts::TRUE;
}

nts::Tristate Or::calculThat(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED || two == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::FALSE && two == nts::FALSE)
        return nts::FALSE;
    return nts::TRUE;
}