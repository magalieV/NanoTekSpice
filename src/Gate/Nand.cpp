/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Nand.hpp"

Nand::Nand(size_t in, size_t inp, size_t output)
{
    _output = output;
    _input1 =in;
    _input2 = inp;
}

void Nand::dump() const
{
    std::cout << "Component: " << _input1 << "and component: " << _input2
              << " NAND " << std::endl;
}

nts::Tristate Nand::compute(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED || two == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::FALSE || two == nts::FALSE)
        return nts::TRUE;
    return nts::FALSE;
}

nts::Tristate Nand::calculThat(nts::Tristate one, nts::Tristate two)
{
    if (one == nts::UNDEFINED || two == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (one == nts::FALSE || two == nts::FALSE)
        return nts::TRUE;
    return nts::FALSE;
}