/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __CHIPSET_ERRORS_HEADER__
#define __CHIPSET_ERRORS_HEADER__

#include "Errors.hpp"

#define NOT std::string ("The chipset cannot be found")

class ChipsetError : public Errors
{
    public:
        ChipsetError(std::string message,
               std::string component = "Chipset");
        virtual ~ChipsetError() noexcept {};
};

#endif //__CHIPSET_ERRORS_HEADER__