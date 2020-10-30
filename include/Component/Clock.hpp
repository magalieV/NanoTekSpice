/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __CLOCK_HEADER__
#define __CLOCK_HEADER__

#include <iostream>
#include "IComponent.hpp"

class Clock: public nts::IComponent
{
    public:
        virtual ~Clock() = default;
        Clock(std::string name);
        virtual nts::Tristate compute(std::size_t pin = 1) final;
        nts::Tristate computeThat();
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
        virtual void dump() const final;
        void setValue(nts::Tristate value) final;
        nts::Tristate getValue() const final;
        size_t getPinLink() const final;
        std::string _name;
        nts::Tristate _value;
    private:
        static const size_t max = 1;
        nts::Link _link;
};

#endif //__CLOCK_HEADER__