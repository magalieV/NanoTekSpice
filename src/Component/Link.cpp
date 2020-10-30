/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Link.hpp"

Pin::Pin(size_t number, std::string type)
{
    _number = number;
    _value = nts::Tristate::UNDEFINED;
    _type = type;
}

Pin::~Pin()
{
}

void Pin::setValue(nts::Tristate value)
{
    _value = value;
}

nts::Tristate Pin::getValue() const
{
    return _value;
}

size_t  Pin::get_pinNumber() const
{
    return _number;
}

size_t Pin::getPinLink() const
{
    return _number;
}

void Pin::dump() const
{
    std::cout << _number << std::endl;
}

nts::Tristate Pin::compute(std::size_t pin)
{
    return _value;
}

void Pin::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _link[pin] = &other;
}