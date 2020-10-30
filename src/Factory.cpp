/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Factory.hpp"
#include "ComponentError.hpp"

Factory::Factory()
{
    _component.clear();
    _component["true"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new True(value));
    };
    _component["clock"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Clock(value));
    };
    _component["output"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Output(value));
    };
    _component["input"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Input(value));
    };
    _component["false"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new False(value));
    };
    _component["4801"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Pin(1, value));
    };
    _component["4514"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Pin(1, value));
    };
    _component["4094"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Pin(1, value));
    };
    _component["4081"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Component4081(value));
    };
    _component["4071"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Component4071(value));
    };
    _component["4069"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Component4069(value));
    };
    _component["4040"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Pin(1, value));
    };
    _component["4030"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Component4030(value));
    };
    _component["4017"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Pin(1, value));
    };
    _component["4013"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Pin(1, value));
    };
    _component["4001"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Component4001(value));
    };
    _component["2716"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Pin(1, value));
    };
    _component["4008"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Pin(1, value));
    };
    _component["4011"] = [](std::string value)->std::unique_ptr<nts::IComponent> {
        return std::unique_ptr<nts::IComponent>(new Component4011(value));
    };
}


std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string &type, const std::string &value)
{
    if (_component.find(type) == _component.end())
        throw ComponentError(NOT_FOUND);
    auto ptr = _component.at(type);
    return ptr(value);
}