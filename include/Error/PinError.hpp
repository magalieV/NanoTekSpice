/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __PIN_ERRORS_HEADER__
#define __PIN_ERRORS_HEADER__

#include "Errors.hpp"

#define NO_OUTPUT std::string("The pin request is not an output")
#define IMPOSSIBLE_LINK std::string("The pin request doesn't exist")
#define INVALID std::string("Invalid pin")

class PinError : public Errors
{
    public:
        PinError(std::string message,
                  std::string component = "Pin");
        virtual ~PinError() noexcept {};
};

#endif //__PIN_ERRORS_HEADER__