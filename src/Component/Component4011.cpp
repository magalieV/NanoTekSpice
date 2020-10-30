/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Component4011.hpp"
#include "PinError.hpp"

Component4011::Component4011(std::string name) : _name(name)
{
    Component4011::_create_pinList();
    Component4011::_createNand();
}

Component4011::~Component4011()
{
}

void Component4011::setValue(nts::Tristate value)
{
}

nts::Tristate Component4011::getValue() const
{
    return nts::UNDEFINED;
}

size_t Component4011::getPinLink() const
{
    return 0;
}

void Component4011::_create_pinList()
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

void Component4011::_createNand()
{
    _nand[3] = Nand(1, 2, 3);
    _nand[4] = Nand(5, 6, 4);
    _nand[10] = Nand(8, 9, 10);
    _nand[11] = Nand(12, 13, 11);
}

void Component4011::dump() const
{
    for (const auto & it : _pinList) {
        std::cout << "Pin number: " << it.first << std::endl;
    }
    std::cout << std::endl;
    for (const auto & it : _nand) {
        it.second.dump();
        std::cout << std::endl;
    }
}

void Component4011::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void Component4011::_computeList(size_t pin)
{
    for (auto ite : _pinLink) {
        if ((ite.first == _nand.at(pin)._input2 || ite.first == _nand.at(pin)._input1)) {
            _pinList.at(ite.first)._value = ite.second._component->compute(ite.second._pin);
        }
    }
    Pin pin1 = _pinList.at(_nand.at(pin)._input1);
    Pin pin2 = _pinList.at(_nand.at(pin)._input2);
    _pinList.at(pin)._value = _nand.at(pin).compute(pin1._value, pin2._value);
}

nts::Tristate Component4011::compute(std::size_t pin)
{
    if (_pinList.max_size() < pin || pin == 0)
        throw PinError(INVALID);
    if (pin == 7 or pin == 14)
        throw PinError(INVALID);
    Component4011::_computeList(pin);
    return (_pinList.at(pin)._value);
}