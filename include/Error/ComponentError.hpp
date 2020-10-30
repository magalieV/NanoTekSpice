/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __COMPONENT_ERRORS_HEADER__
#define __COMPONENT_ERRORS_HEADER__

#include "Errors.hpp"

#define ALREADY std::string("The component name already exist")
#define NOT_FOUND std::string("Component not found")

class ComponentError : public Errors
{
    public:
        ComponentError(std::string message,
                     std::string component = "Component");
        virtual ~ComponentError() noexcept {};
};

#endif //__COMPONENT_ERRORS_HEADER__