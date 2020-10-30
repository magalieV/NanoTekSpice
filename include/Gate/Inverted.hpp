/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __INVERTED_HEADER__
#define __INVERTED_HEADER__

#include "IComponent.hpp"
#include "IGate.hpp"

class Inverted : public IGate
{
    public:
        Inverted() = default;
        Inverted(size_t in, size_t output);
        ~Inverted() final = default;
        void dump() const final;
        nts::Tristate compute(nts::Tristate one, nts::Tristate = nts::UNDEFINED) final;
        static nts::Tristate calculThat(nts::Tristate one, nts::Tristate two);
        size_t _input;
        size_t _output;
};

#endif //__NAND_HEADER__