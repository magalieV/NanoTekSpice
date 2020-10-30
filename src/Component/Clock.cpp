/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Clock.hpp"
#include "Inverted.hpp"

Clock::Clock(std::string name)
{
    _name = name;
    _link._component = nullptr;
    _link._pin = 0;
    _value = nts::UNDEFINED;
}

void Clock::setValue(nts::Tristate value)
{
    _value = value;
}

nts::Tristate Clock::getValue() const
{
    return _value;
}

size_t Clock::getPinLink() const
{
    return _link._pin;
}

nts::Tristate Clock::compute(std::size_t pin)
{
    if (pin == 300)
        return computeThat();
    return _value;
}

nts::Tristate Clock::computeThat()
{
    if (_value == nts::TRUE)
        _value = nts::FALSE;
    else if (_value == nts::FALSE)
        _value = nts::TRUE;
    else
        _value = nts::UNDEFINED;
    return _value;
}

void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _link._component = &other;
    _link._pin = otherPin;
}

void Clock::dump() const
{
    std::cout << "Clock : " << _value << std::endl;
}