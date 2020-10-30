/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include <Error/FileError.hpp>
#include "Circuit.hpp"
#include "ComponentError.hpp"
#include "Link.hpp"
#include <functional>
#include "InputError.hpp"
#include <algorithm>

int Circuit::outputSet = 0;
int Circuit::OutputSize = 0;

bool Circuit::_end = true;

Circuit::Circuit()
{
    _cmds["loop"] = &Circuit::loop;
    _cmds["simulate"] = &Circuit::simulate;
    _cmds["display"] = &Circuit::display;
    _cmds["dump"] = &Circuit::dump;
    _cmds["exit"] = &Circuit::exit;
}

void Circuit::endSimulation(int sig)
{
    (void)sig;
    Circuit::_end = false;
}

void Circuit::addComponent(const std::string &type, const std::string &name, const std::string &value)
{
    if (_componentList.find(name) != _componentList.end())
        throw ComponentError(ALREADY);
    if (value.empty()) {
        std::unique_ptr<nts::IComponent> ptr = _factory.createComponent(type, name);
        _componentList[name] = circuitComponent{._type = type, ._component = std::move(ptr)};
        _key.emplace_back(name);
        if (type == "output")
            OutputSize++;
    }
}

std::vector<std::string> Circuit::_split(const std::string &line, const std::string &delimiter)
{
    std::string buffer;
    std::vector<std::string> result;
    bool found = false;

    for (char index : line) {
        found = false;
        for (char idx : delimiter) {
            if (index == idx)
                found = true;
        }
        if (found && !buffer.empty()) {
            result.emplace_back(buffer);
            buffer.clear();
        } else if (!found){
            buffer.push_back(index);
        }
    }
    if (!buffer.empty())
        result.emplace_back(buffer);
    return result;
}

bool Circuit::_setLinkOutpout(const std::string &name, int link, const std::string &nameOther, int linkOther)
{
    if (_componentList.at(nameOther)._type == "output") {
        _componentList.at(nameOther)._component->setLink(linkOther, *_componentList.at(name)._component, link);
        outputSet++;
        return true;
    } else if (_componentList.at(name)._type == "output") {
        _componentList.at(name)._component->setLink(link, *_componentList.at(nameOther)._component, linkOther);
        outputSet++;
        return true;
    }
    return false;
}

bool Circuit::_setLinkComponent(const std::string &name, int link, const std::string &nameOther, int linkOther)
{
    if (_componentList.at(nameOther)._type.find('4') != std::string::npos or _componentList.at(nameOther)._type.find('2') != std::string::npos) {
        _componentList.at(nameOther)._component->setLink(linkOther, *_componentList.at(name)._component, link);
        return true;
    } else if (_componentList.at(name)._type.find('4') != std::string::npos or _componentList.at(name)._type.find('2') != std::string::npos) {
        _componentList.at(name)._component->setLink(link, *_componentList.at(nameOther)._component, linkOther);
        return true;
    }
    return false;
}

void Circuit::_setLinkOther(const std::string &name, int link, const std::string &nameOther, int linkOther)
{
    _componentList.at(name)._component->setLink(link, *_componentList.at(nameOther)._component, linkOther);
    _componentList.at(nameOther)._component->setLink(linkOther, *_componentList.at(name)._component, link);
}

void Circuit::setLinkForThat(const std::string &name, int link, const std::string &nameOther, int linkOther)
{
    bool result = false;

    if (_componentList.find(name) == _componentList.end() || _componentList.find(nameOther) == _componentList.end())
        throw ComponentError(NOT_FOUND);
    result = _setLinkOutpout(name, link, nameOther, linkOther);
    if (!result)
        result = _setLinkComponent(name, link, nameOther, linkOther);
    if (!result)
        _setLinkOther(name, link, nameOther, linkOther);
}

bool Circuit::exit(const std::string &line)
{
    return true;
}

bool Circuit::display(const std::string &line)
{
    std::sort(_key.begin(), _key.end(), [](const std::string &a, const std::string &b){
        return a < b;
    });
    for (auto name : _key) {
        if (_componentList.at(name)._type == "output")
            _componentList.at(name)._component->dump();
    }
    return false;
}

void Circuit::_checkInput()
{
    for (auto name : _key) {
        if ((_componentList.at(name)._type == "input" || _componentList.at(name)._type == "clock")
        && _componentList.at(name)._component->getValue() == nts::UNDEFINED)
            throw InputError(NO_INI);
    }
}

bool Circuit::inputValue(const std::string &line)
{
    std::vector<std::string> list = _split(line, "\t= ");

    if (list.size() < 2)
        throw FileError(ERROR_COMPONENTS_FILE);
    if (_componentList.find(list[0]) == _componentList.end())
        throw ComponentError(NOT_FOUND);
    int value = atoi(list[1].c_str());
    if (_componentList.at(list[0])._type == "input" || _componentList.at(list[0])._type == "clock") {
        switch (value) {
            case 1:
                _componentList.at(list[0])._component->setValue(nts::Tristate::TRUE);
                break;
            case 0:
                _componentList.at(list[0])._component->setValue(nts::Tristate::FALSE);
                break;
            default:
                _componentList.at(list[0])._component->setValue(nts::Tristate::UNDEFINED);
                break;
        }
    }
    return false;
}

bool Circuit::simulate(const std::string &line)
{
    for (auto name : _key) {
        if (_componentList.at(name)._type == "output")
            _componentList.at(name)._component->compute(_componentList.at(name)._component->getPinLink());
    }
    for (auto name : _key) {
        if (_componentList.at(name)._type == "clock")
            _componentList.at(name)._component->compute(300);
    }
    return false;
}

bool Circuit::loop(const std::string &line)
{
    _end = true;
    while (_end) {
        Circuit::simulate(line);
        signal(SIGINT, Circuit::endSimulation);
    }
    _end = true;
    return false;
}

bool Circuit::dump(const std::string &line)
{
    for (auto it : _key) {
        _componentList.at(it)._component->dump();
    }
    return false;
}

void Circuit::initialize(std::vector<std::string> argv)
{
    for (auto line : argv) {
        if (line.find('=') != std::string::npos)
            Circuit::inputValue(line);
    }
}

bool Circuit::useCmds(const std::string &line)
{
    for (auto it : _cmds) {
        if (it.first == line) {
            return (this->*it.second)(line);
        }
    }
    return false;
}

void Circuit::run()
{
    std::string line;

    signal(SIGINT, Circuit::endSimulation);
    _end = true;
    if (outputSet != OutputSize) {
        throw FileError(OUTPUT_NOT_LINK);
    }
    _checkInput();
    Circuit::simulate("");
    Circuit::display("");
    do {
        std::cout << "> ";
        _end = true;
        signal(SIGINT, Circuit::endSimulation);
        if (!getline(std::cin, line)) {
            break;
        }
        if (Circuit::useCmds(line))
            break;
        if (line.find('=') != std::string::npos)
            Circuit::inputValue(line);
    } while (Circuit::_end);
}