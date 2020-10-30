/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __COMPONENT4030_HEADER__
#define __COMPONENT4030_HEADER__

#include "IComponent.hpp"
#include "Xor.hpp"
#include "Link.hpp"
#include <list>
#include <map>

class Component4030 : public nts::IComponent
{
    public:
        Component4030(std::string name = "Component 4030");
        ~Component4030();
        virtual nts::Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const final;
        void setValue(nts::Tristate value) final;
        nts::Tristate getValue() const final;
        size_t getPinLink() const final;

    private:
        void _create_pinList();
        void _createXor();
        void _computeList(size_t pin);
        std::map<size_t , nts::Link> _pinLink;
        std::map<size_t, Pin> _pinList;
        std::map<size_t , Xor> _xor;
        static const size_t max = 14;
        std::string _name;
};

#endif //__COMPONENT4030__