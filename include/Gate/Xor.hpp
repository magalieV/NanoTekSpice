/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __XOR_HEADER__
#define __XOR_HEADER__

#include "IComponent.hpp"
#include "Link.hpp"
#include "IGate.hpp"

class Xor : public IGate
{
    public:
        Xor() = default;
        Xor(size_t in, size_t inp, size_t output);
        ~Xor() = default;
        void dump() const;
        nts::Tristate compute(nts::Tristate one, nts::Tristate two) final;
        static nts::Tristate calculThat(nts::Tristate one, nts::Tristate two);
        size_t _input1;
        size_t _output;
        size_t _input2;
};

#endif //__XOR_HEADER__