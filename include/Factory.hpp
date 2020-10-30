/*
** EPITECH PROJECT, 2020
** OOP - Matthias Schafter
** File description:
** Nanotekspice - IComponent
*/

#ifndef __FACTORY_HEADER__
#define __FACTORY_HEADER__

#include "Component4001.hpp"
#include "Component4011.hpp"
#include "Component4030.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"
#include "IComponent.hpp"
#include "Link.hpp"
#include "Output.hpp"
#include "Input.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Clock.hpp"
#include <memory>
#include <functional>

class Factory
{
    public:
        Factory();
        ~Factory() = default;
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);

    private:
        typedef std::unique_ptr<nts::IComponent> (Factory::*createCpm)(std::string value);
        std::map<std::string, std::function<std::unique_ptr<nts::IComponent>(std::string)>> _component;
};

#endif //__FACTORY_HEADER__

