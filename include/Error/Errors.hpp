/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __ERRORS_HEADER__
#define __ERRORS_HEADER__

#include <string>

class Errors : public std::exception
{
    public:
        Errors(std::string message,
                  std::string component = "Unknown");
        std::string const &getComponent() const;
        virtual ~Errors() noexcept {};
        const char* what() const noexcept override;
    private:
        std::string _message;
        std::string _componement;
};

#endif //__ERRORS_HEADER__