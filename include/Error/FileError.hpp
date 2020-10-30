/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __FILE_ERRORS_HEADER__
#define __FILE_ERRORS_HEADER__

#include "Errors.hpp"

#define CANNOT_OPEN std::string("The file cannot be open")
#define BAD_EXT std::string("Bad extension")
#define ERROR_COMPONENTS_FILE std::string("Error parsing : bad information on file")
#define OUTPUT_NOT_LINK std::string("Not all of the output are linked")

class FileError : public Errors
{
    public:
        FileError(std::string message,
                       std::string component = "File");
        virtual ~FileError() noexcept {};
};

#endif //__FILE_ERRORS_HEADER__