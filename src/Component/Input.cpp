/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Input.hpp"

Input::Input(std::string name)
{
    _name = name;
    _link._component = nullptr;
    _link._pin = 0;
    _value = nts::UNDEFINED;
}

Input::~Input()
{
}

void Input::setValue(nts::Tristate value)
{
    _value = value;
}

nts::Tristate Input::getValue() const
{
    return _value;
}

size_t Input::getPinLink() const
{
    return _link._pin;
}

nts::Tristate Input::compute(std::size_t pin)
{
    return _value;
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _link._component = &other;
    _link._pin = otherPin;
}

void Input::dump() const
{
    std::cout << "Output : " << _value;
}