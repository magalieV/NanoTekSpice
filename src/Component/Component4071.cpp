/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Component4071.hpp"
#include "PinError.hpp"

Component4071::Component4071(std::string name) : _name(name)
{
    Component4071::_create_pinList();
    Component4071::_createOr();
}

Component4071::~Component4071()
{
}

void Component4071::setValue(nts::Tristate value)
{
}

size_t Component4071::getPinLink() const
{
    return 0;
}

nts::Tristate Component4071::getValue() const
{
    return nts::UNDEFINED;
}

void Component4071::_create_pinList()
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

void Component4071::_createOr()
{
    _or[3] = Or(1, 2, 3);
    _or[4] = Or(5, 6, 4);
    _or[10] = Or(8, 9, 10);
    _or[11] = Or(12, 13, 11);
}

void Component4071::dump() const
{
    for (const auto & it : _pinList) {
        std::cout << "Pin number: " << it.first << std::endl;
    }
    std::cout << std::endl;
    for (const auto & it : _or) {
        it.second.dump();
        std::cout << std::endl;
    }
}

void Component4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void Component4071::_computeList(size_t pin)
{
    for (auto ite : _pinLink) {
        if ((ite.first == _or.at(pin)._input2 || ite.first == _or.at(pin)._input1)) {
            _pinList.at(ite.first)._value = ite.second._component->compute(ite.second._pin);
        }
    }
    Pin pin1 = _pinList.at(_or.at(pin)._input1);
    Pin pin2 = _pinList.at(_or.at(pin)._input2);
    _pinList.at(pin)._value = _or.at(pin).compute(pin1._value, pin2._value);
}

nts::Tristate Component4071::compute(std::size_t pin)
{
    if (_pinList.max_size() < pin || pin == 0)
        throw PinError(INVALID);
    if (pin == 7 or pin == 14)
        throw PinError(INVALID);
    Component4071::_computeList(pin);
    return (_pinList.at(pin)._value);
}