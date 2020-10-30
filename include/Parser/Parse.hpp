/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __PARSE_HEADER__
#define __PARSE_HEADER__

#include <iostream>
#include <fstream>
#include <sstream>
#include "Circuit.hpp"
#include <vector>

#define CHIP std::string(".chipsets:")
#define LINK std::string(".links:")
#define COMMENT_BLOCK '#'

class Parse
{
    public:
        explicit Parse(char *argv[]);

    private:
        void _parseThis(std::ifstream &flux);
        void _createComponent(std::stringstream &stream);
        void _createLink(std::stringstream &stream);
        std::vector<std::string> _split(const std::string &line, const std::string &delimiter);
        void _purifyThat(std::ifstream &flux, std::stringstream &file);
        bool _checkComment(std::string &line);
        Circuit _circuit;
        bool _removeEmptyLine(std::string &line);
};

#endif //__PARSE_HEADER__
