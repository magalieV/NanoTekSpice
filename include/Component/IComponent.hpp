/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef ICOMPENENT_HPP_
#define ICOMPENENT_HPP_

#include <iostream>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent {
        public:
            virtual ~IComponent() = default;
        public:
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual size_t getPinLink() const = 0;
            virtual void setValue(nts::Tristate value) = 0;
            virtual nts::Tristate getValue() const = 0;
    };
    struct Link {
        nts::IComponent *_component;
        size_t _pin;
    };
}

#endif /* !ICOMPENENT_HPP_ */
