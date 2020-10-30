/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __NOR_HEADER__
#define __NOR_HEADER__

#include "IComponent.hpp"
#include "IGate.hpp"

class Nor : public IGate
{
    public:
        Nor() = default;
        Nor(size_t in, size_t inp, size_t output);
        ~Nor() final = default;
        void dump() const final;
        nts::Tristate compute(nts::Tristate one, nts::Tristate two) final;
        static nts::Tristate calculThat(nts::Tristate one, nts::Tristate two);
        size_t _input1;
        size_t _output;
        size_t _input2;
};

#endif //__NOR_HEADER__