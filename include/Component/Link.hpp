/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __LINK_HEADER__
#define __LINK_HEADER__

#include "IComponent.hpp"
#include "nor.hpp"
#include <map>

class Pin : public nts::IComponent
{
    public:
        Pin() = default;
        Pin(size_t number, std::string type = "no_type");
        ~Pin();
        size_t get_pinNumber() const;
        void dump() const;
        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void setValue(nts::Tristate value) final;
        nts::Tristate getValue() const final;
        size_t getPinLink() const final;
        nts::Tristate _value;
    private:
        size_t _number;
        std::string _type;
        std::map<size_t, nts::IComponent *> _link;
};

#endif //__LINK_HEADER__