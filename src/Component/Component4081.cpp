/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Component4081.hpp"
#include "PinError.hpp"

Component4081::Component4081(std::string name) : _name(name)
{
    Component4081::_create_pinList();
    Component4081::_createAnd();
}

Component4081::~Component4081()
{
}

size_t Component4081::getPinLink() const
{
    return 0;
}

void Component4081::setValue(nts::Tristate value)
{
}

nts::Tristate Component4081::getValue() const
{
    return nts::UNDEFINED;
}

void Component4081::_create_pinList()
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

void Component4081::_createAnd()
{
    _and[3] = And(1, 2, 3);
    _and[4] = And(5, 6, 4);
    _and[10] = And(8, 9, 10);
    _and[11] = And(12, 13, 11);
}

void Component4081::dump() const
{
    for (const auto & it : _pinList) {
        std::cout << "Pin number: " << it.first << std::endl;
    }
    std::cout << std::endl;
    for (const auto & it : _and) {
        it.second.dump();
        std::cout << std::endl;
    }
}

void Component4081::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void Component4081::_computeList(size_t pin)
{
    for (auto ite : _pinLink) {
       if ((ite.first == _and.at(pin)._input2 || ite.first == _and.at(pin)._input1)) {
            _pinList.at(ite.first)._value = ite.second._component->compute(ite.second._pin);
        }
    }
    Pin pin1 = _pinList.at(_and.at(pin)._input1);
    Pin pin2 = _pinList.at(_and.at(pin)._input2);
    _pinList.at(pin)._value = _and.at(pin).compute(pin1._value, pin2._value);
}

nts::Tristate Component4081::compute(std::size_t pin)
{
    if (_pinList.max_size() < pin || pin == 0)
        throw PinError(INVALID);
    if (pin == 7 or pin == 14)
        throw PinError(INVALID);
    Component4081::_computeList(pin);
    return (_pinList.at(pin)._value);
}