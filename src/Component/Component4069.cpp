/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Component4069.hpp"
#include "PinError.hpp"

Component4069::Component4069(std::string name) : _name(name)
{
    Component4069::_create_pinList();
    Component4069::_createInverted();
}

Component4069::~Component4069()
{
}

void Component4069::setValue(nts::Tristate value)
{
}

size_t Component4069::getPinLink() const
{
    return 0;
}

nts::Tristate Component4069::getValue() const
{
    return nts::UNDEFINED;
}

void Component4069::_create_pinList()
{
    _pinList[1] = Pin(1);
    _pinList[2] = Pin(2);
    _pinList[3] = Pin(3);
    _pinList[4] = Pin(4);
    _pinList[5] = Pin(5);
    _pinList[6] = Pin(6);
    _pinList[8] = Pin(8);
    _pinList[9] = Pin(9);
    _pinList[10] = Pin(10);
    _pinList[11] = Pin(11);
    _pinList[12] = Pin(12);
    _pinList[13] = Pin(13);
}

void Component4069::_createInverted()
{
    _inverted[2] = Inverted(1, 2);
    _inverted[4] = Inverted(3, 4);
    _inverted[6] = Inverted(5, 6);
    _inverted[8] = Inverted(9, 8);
    _inverted[10] = Inverted(11, 10);
    _inverted[12] = Inverted(13, 12);
}

void Component4069::dump() const
{
    for (const auto & it : _pinList) {
        std::cout << "Pin number: " << it.first << std::endl;
    }
    std::cout << std::endl;
    for (const auto & it : _inverted) {
        it.second.dump();
        std::cout << std::endl;
    }
}

void Component4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > max || pin == 0)
        throw PinError(IMPOSSIBLE_LINK);
    if (pin == 7 || pin == 14)
        throw PinError(INVALID);
    if (&other == this && pin == otherPin)
        throw PinError(INVALID);
    _pinLink[pin]._component = &other;
    _pinLink.at(pin)._pin = otherPin;
}

void Component4069::_computeList(size_t pin)
{
    for (auto ite : _pinLink) {
        if (ite.first == _inverted.at(pin)._input) {
            _pinList.at(ite.first)._value = ite.second._component->compute(ite.second._pin);
        }
    }
    Pin pin1 = _pinList.at(_inverted.at(pin)._input);
    _pinList.at(pin)._value = _inverted.at(pin).compute(pin1._value);
}

nts::Tristate Component4069::compute(std::size_t pin)
{
    if (_pinList.max_size() < pin || pin == 0)
        throw PinError(INVALID);
    if (pin == 7 or pin == 14)
        throw PinError(INVALID);
    Component4069::_computeList(pin);
    return (_pinList.at(pin)._value);
}