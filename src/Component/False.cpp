/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "False.hpp"

False::False(std::string name)
{
    _name = name;
    _link._component = nullptr;
    _link._pin = 0;
    _value = nts::FALSE;
}

False::~False()
{
}

void False::setValue(nts::Tristate value)
{
}

nts::Tristate False::getValue() const
{
    return nts::FALSE;
}

size_t False::getPinLink() const
{
    return _link._pin;
}

nts::Tristate False::compute(std::size_t pin)
{
    return _value;
}

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _link._component = &other;
    _link._pin = otherPin;
}

void False::dump() const
{
    std::cout << "False : " << _value << std::endl;
}