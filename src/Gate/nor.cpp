/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "nor.hpp"

Nor::Nor(size_t in, size_t inp, size_t output)
{
    _output = output;
    _input1 =in;
    _input2 = inp;
}

void Nor::dump() const
{
    std::cout << "Component: " << _input1 << "and component: " << _input2
    << " NOR " << std::endl;
}

nts::Tristate Nor::compute(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED || two == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::TRUE || two == nts::TRUE)
        return nts::FALSE;
    return nts::TRUE;
}

nts::Tristate Nor::calculThat(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED || two == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::TRUE || two == nts::TRUE)
        return nts::FALSE;
    return nts::TRUE;
}