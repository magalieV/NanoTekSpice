/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include <regex>
#include "Parse.hpp"
#include "FileError.hpp"
#include "ChipsetError.hpp"
#include "LinkError.hpp"

Parse::Parse(char *argv[])
{
    std::ifstream flux;
    std::string extension;
    std::string fileName = argv[1];
    std::vector<std::string> args;

    flux.open(fileName);
    if (!flux)
        throw FileError(CANNOT_OPEN);
    extension = fileName.substr(fileName.find_last_of(".") + 1);
    if (extension != "nts")
        throw FileError("'" + extension + "'" + BAD_EXT);
    Parse::_parseThis(flux);
    for (int index = 2; argv[index]; index++) {
        args.emplace_back(argv[index]);
    }
    if (!args.empty()) {
        _circuit.initialize(args);
    }
    _circuit.run();
}

bool Parse::_checkComment(std::string &line)
{
    for (char index : line) {
        if (index == '#')
            return true;
        if (index != '\t' or index != ' ') {
            std::string part1 = line.substr(line.find_first_of('#'));
            line = line.substr(0, line.size() - part1.size());
            return false;
        }
    }
    return true;
}

std::vector<std::string> Parse::_split(const std::string &line, const std::string &delimiter)
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

void Parse::_createLink(std::stringstream &stream)
{
    std::string line;
    std::vector<std::string> components;

    while (getline(stream, line)) {
        components = _split(line, "\t :");
        if (components.size() < 4)
            throw FileError(ERROR_COMPONENTS_FILE);
        _circuit.setLinkForThat(components[0], atoi(components[1].c_str()),
            components[2], atoi(components[3].c_str()));
    }
}

bool Parse::_removeEmptyLine(std::string &line) {
    bool found = false;
    for (char index : line) {
        if (index != '\t' or index != ' ' or index != '\n')
            found = true;
    }
    return found;
}

void Parse::_createComponent(std::stringstream &stream)
{
    std::string line;
    std::vector<std::string> components;

    while (getline(stream, line)) {
        if (line.find(LINK) != std::string::npos || line == ".links:")
            break;
        components = _split(line, "\t ()");
        if (components.size() < 2)
            throw FileError(ERROR_COMPONENTS_FILE);
        if (components.size() == 3)
            _circuit.addComponent(components[0], components[1], components[2]);
        else
            _circuit.addComponent(components[0], components[1]);
    }
    if (line.find_first_of(LINK) != std::string::npos)
        _createLink(stream);
    else
        throw LinkError(NO_LINK);
}

void Parse::_purifyThat(std::ifstream &flux, std::stringstream &file)
{
    std::string line;


    while (std::getline(flux, line)) {
        if (line.find_first_of('#') != std::string::npos) {
            if (!_checkComment(line))
                file << line << std::endl;
        } else if (_removeEmptyLine(line)) {
            file << line << std::endl;
        }
    }
}

void Parse::_parseThis(std::ifstream &flux)
{
    std::stringstream stream;
    bool found = false;
    std::string line;
    _purifyThat(flux, stream);
    while (getline(stream, line)) {
        if (line.find_first_of(CHIP) != std::string::npos) {
            Parse::_createComponent(stream);
            found = true;
            break;
        }
    }
    if (!found)
        throw ChipsetError(NOT);
}