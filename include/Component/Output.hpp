/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __OUTPUT_HEADER__
#define __OUTPUT_HEADER__

#include <iostream>
#include "IComponent.hpp"

class Output : public nts::IComponent
{
    public:
        Output(std::string name = "Component Output");
        virtual ~Output();
        nts::Tristate compute(std::size_t pin = 1) final;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
        void dump() const final;
        void setValue(nts::Tristate value) final;
        nts::Tristate getValue() const final;
        size_t getPinLink() const final;
        std::string _name;
        nts::Tristate _value;
        nts::Link _link;
    private:
        static const size_t max = 1;
};

#endif // __OUTPUT_HEADER__
