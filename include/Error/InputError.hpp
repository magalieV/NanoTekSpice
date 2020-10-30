/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __INPUT_ERRORS_HEADER__
#define __INPUT_ERRORS_HEADER__

#include "Errors.hpp"

#define NO_INI std::string("One of several input are not link")

class InputError : public Errors
{
    public:
        InputError(std::string message,
                  std::string component = "Input");
        virtual ~InputError() noexcept {};
};

#endif //__INPUT_ERRORS_HEADER__