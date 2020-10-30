/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __AND_HEADER__
#define __AND_HEADER__

#include "IGate.hpp"

class And : public IGate
{
    public:
        And() = default;
        And(size_t in, size_t inp, size_t output);
        ~And() final = default;
        void dump() const final;
        nts::Tristate compute(nts::Tristate one, nts::Tristate two) final;
        static nts::Tristate calculThat(nts::Tristate one, nts::Tristate two);
        size_t _input1;
        size_t _output;
        size_t _input2;
};


#endif //__OR_HEADER__