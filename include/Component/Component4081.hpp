/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __COMPONENT4081_HEADER__
#define __COMPONENT4081_HEADER__

#include "IComponent.hpp"
#include "And.hpp"
#include "Link.hpp"
#include <list>
#include <map>

class Component4081 : public nts::IComponent
{
    public:
        Component4081(std::string name = "Component 4081");
        ~Component4081();
        virtual nts::Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const final;
        void setValue(nts::Tristate value) final;
        nts::Tristate getValue() const final;
        size_t getPinLink() const final;

    private:
        void _create_pinList();
        void _createAnd();
        void _computeList(size_t pin);
        std::map<size_t , nts::Link> _pinLink;
        std::map<size_t, Pin> _pinList;
        std::map<size_t , And> _and;
        static const size_t max = 14;
        std::string _name;
};

#endif //__COMPONENT4071__