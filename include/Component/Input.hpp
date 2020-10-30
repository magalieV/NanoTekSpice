/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __INPUT_HEADER__
#define __INPUT_HEADER__

#include <iostream>
#include "IComponent.hpp"

class Input : public nts::IComponent
{
    public:
        Input(std::string name = "Component Input");
        virtual ~Input();
        virtual nts::Tristate compute(std::size_t pin = 1) final;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
        virtual void dump() const final;
        void setValue(nts::Tristate value) final;
        nts::Tristate getValue() const final;
        size_t getPinLink() const final;
        nts::Tristate _value;
        nts::Link _link;
    private:
        static const size_t max = 1;
        std::string _name;
};

#endif // __INTPUT_HEADER__
