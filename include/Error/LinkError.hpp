/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __LINK_ERRORS_HEADER__
#define __LINK_ERRORS_HEADER__

#include "Errors.hpp"

#define NO_LINK std::string("No link section in file")

class LinkError : public Errors
{
    public:
        LinkError(std::string message,
                  std::string component = "Link");
        virtual ~LinkError() noexcept {};
};

#endif //__LINK_ERRORS_HEADER__