/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "And.hpp"

And::And(size_t in, size_t inp, size_t output)
{
    _output = output;
    _input1 =in;
    _input2 = inp;
}

void And::dump() const
{
    std::cout << "Component: " << _input1 << "and component: " << _input2
              << " AND " << std::endl;
}

nts::Tristate And::compute(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED || two == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::TRUE && two == nts::TRUE)
        return nts::TRUE;
    return nts::FALSE;
}

nts::Tristate And::calculThat(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED || two == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::TRUE && two == nts::TRUE)
        return nts::TRUE;
    return nts::FALSE;
}