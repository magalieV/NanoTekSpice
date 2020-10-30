/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#include "Errors.hpp"

Errors::Errors(std::string message, std::string component)
{
    _message = message;
    _componement = component;
}

const std::string & Errors::getComponent() const
{
    return _componement;
}

const char * Errors::what() const noexcept
{
    return _message.c_str();
}