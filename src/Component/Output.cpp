/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Output.hpp"

Output::Output(std::string name)
{
    _name = name;
    _link._component = nullptr;
    _link._pin = 0;
    _value = nts::UNDEFINED;
}

Output::~Output()
{
}

void Output::setValue(nts::Tristate value)
{
    _value = value;
}

nts::Tristate Output::getValue() const
{
    return _value;
}

size_t Output::getPinLink() const
{
    return _link._pin;
}

nts::Tristate Output::compute(std::size_t pin)
{
    if (_link._component != nullptr) {
        _value = _link._component->compute(_link._pin);
    }
    return _value;
}

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _link._component = &other;
    _link._pin = otherPin;
}

void Output::dump() const
{
    if (_value == nts::UNDEFINED) {
        std::cout << _name << "=U" << std::endl;
    } else {
        std::cout << _name << "=" << _value << std::endl;
    }
}