/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __CIRCUIT_HEADER__
#define __CIRCUIT_HEADER__

#include <iostream>
#include <map>
#include <csignal>
#include <vector>
#include "Factory.hpp"

class Circuit
{
        struct circuitComponent {
            std::string _type;
            std::unique_ptr<nts::IComponent> _component;
        };
    public:
        explicit Circuit();
        void addComponent(const std::string &type, const std::string &name, const std::string &value = "");
        void setLinkForThat(const std::string &name, int link, const std::string &nameOther, int linkOther);
        void run();
        static bool _end;
        static void endSimulation(int sig);
        void initialize(std::vector<std::string> atrgv);

    private:
        Factory _factory;
        std::vector<std::string> _split(const std::string &line, const std::string &delimiter);
        bool _setLinkOutpout(const std::string &name, int link, const std::string &nameOther, int linkOther);
        bool _setLinkComponent(const std::string &name, int link, const std::string &nameOther, int linkOther);
        void _setLinkOther(const std::string &name, int link, const std::string &nameOther, int linkOther);
        bool exit(const std::string &line);
        bool display(const std::string &line);
        bool inputValue(const std::string &line);
        bool simulate(const std::string &line);
        bool loop(const std::string &line);
        bool useCmds(const std::string &line);
        bool dump(const std::string &line);
        void _checkInput();
        std::map<std::string, circuitComponent> _componentList;
        std::vector<std::string> _key;
        static int outputSet;
        static int OutputSize;
        typedef bool (Circuit::*func)(const std::string &);
        std::map<std::string, func> _cmds;
};

#endif //__CIRCUIT_HEADER__
