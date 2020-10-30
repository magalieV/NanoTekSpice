/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "True.hpp"

True::True(std::string name)
{
    _name = name;
    _link._component = nullptr;
    _link._pin = 0;
    _value = nts::TRUE;
}

True::~True()
{
}

void True::setValue(nts::Tristate value)
{
}

nts::Tristate True::getValue() const
{
    return nts::TRUE;
}

size_t True::getPinLink() const
{
    return _link._pin;
}

nts::Tristate True::compute(std::size_t pin)
{
    return _value;
}

void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _link._component = &other;
    _link._pin = otherPin;
}

void True::dump() const
{
    std::cout << "True : " << _value << std::endl;
}