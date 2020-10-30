/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __OUTPUT_ERRORS_HEADER__
#define __OUPUT_ERRORS_HEADER__

#include "Errors.hpp"

class OutputError : public Errors
{
    public:
        OutputError(std::string message,
                  std::string component = "Output");
        virtual ~OutputError() noexcept {};
};

#endif //__OUTPUT_ERRORS_HEADER__