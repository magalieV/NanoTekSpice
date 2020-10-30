/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __COMPONENT4069_HEADER__
#define __COMPONENT4069_HEADER__

#include "IComponent.hpp"
#include "Inverted.hpp"
#include "Link.hpp"
#include <list>
#include <map>

class Component4069 : public nts::IComponent
{
    public:
        Component4069(std::string name = "Component 4069");
        ~Component4069();
        virtual nts::Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const final;
        void setValue(nts::Tristate value) final;
        nts::Tristate getValue() const final;
        size_t getPinLink() const final;

    private:
        void _create_pinList();
        void _createInverted();
        void _computeList(size_t pin);
        std::map<size_t , nts::Link> _pinLink;
        std::map<size_t, Pin> _pinList;
        std::map<size_t , Inverted> _inverted;
        static const size_t max = 14;
        std::string _name;
};

#endif //__COMPONENT4071__