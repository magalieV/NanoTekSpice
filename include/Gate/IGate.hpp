/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __INTERFACE_GATE_HEADER__
#define __INTERFACE_GATE_HEADER__

#include "IComponent.hpp"

class IGate
{
    public:
        IGate() = default;
        virtual ~IGate() = default;
        virtual void dump() const = 0;
        virtual nts::Tristate compute(nts::Tristate, nts::Tristate) = 0;
};

#endif //__INTERFACE_GATE_HEADER__