/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __TRUE_HEADER__
#define __TRUE_HEADER__

#include <iostream>
#include "IComponent.hpp"

class True: public nts::IComponent
{
    public:
        True(std::string name = "Component True");
        virtual ~True();
        virtual nts::Tristate compute(std::size_t pin = 1) final;
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

#endif //__TRUE_HEADER__