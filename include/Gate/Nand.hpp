/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __NAND_HEADER__
#define __NAND_HEADER__

#include "IComponent.hpp"
#include "IGate.hpp"

class Nand : public IGate
{
    public:
        Nand() = default;
        Nand(size_t in, size_t inp, size_t output);
        ~Nand() final = default;
        void dump() const final;
        nts::Tristate compute(nts::Tristate one, nts::Tristate two) final;
        static nts::Tristate calculThat(nts::Tristate one, nts::Tristate two);
        size_t _input1;
        size_t _output;
        size_t _input2;
};

#endif //__NAND_HEADER__