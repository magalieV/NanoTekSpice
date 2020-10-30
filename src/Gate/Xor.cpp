/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Xor.hpp"

Xor::Xor(size_t in, size_t inp, size_t output)
{
    _output = output;
    _input1 =in;
    _input2 = inp;
}

void Xor::dump() const
{
    std::cout << "Component: " << _input1 << "and component: " << _input2
              << " XOR " << std::endl;
}

nts::Tristate Xor::compute(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED || two == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::TRUE && two == nts::TRUE)
        return nts::FALSE;
    if (one == nts::FALSE && two == nts::FALSE)
        return nts::FALSE;
    return nts::TRUE;
}

nts::Tristate Xor::calculThat(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED || two == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::TRUE && two == nts::TRUE)
        return nts::FALSE;
    if (one == nts::FALSE && two == nts::FALSE)
        return nts::FALSE;
    return nts::TRUE;
}