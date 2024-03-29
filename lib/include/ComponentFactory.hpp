//
// Component.hpp for Component in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Fri Feb  3 14:30:15 2017 Riamon Vincent
// Last update Thu Feb  9 01:16:53 2017 Riamon Vincent
//

#ifndef COMPONENT_FACTORY_HPP_
# define COMPONENT_FACTORY_HPP_

# include "AComponent.hpp"
# include "Input.hpp"
# include "Clock.hpp"
# include "Output.hpp"
# include "True.hpp"
# include "False.hpp"
# include "AND-4081.hpp"
# include "OR-4071.hpp"
# include "NAND-4011.hpp"
# include "NOR-4001.hpp"
# include "XOR-4030.hpp"
# include "INVERSE-4069.hpp"
# include "FlipFlop-4013.hpp"
# include "adder-4008.hpp"
# include "decoder-4514.hpp"
# include "counter-4040.hpp"
# include "rand-4801.hpp"
# include "rdonly-2716.hpp"
# include "register-4094.hpp"
# include "Jdecade-4017.hpp"

namespace nts {

  class ComponentFactory {
  public:
    ~ComponentFactory();
    AComponent *createComponent(std::string const& type,
				std::string const& value) const;

    static ComponentFactory getInstance();

    static inline Tristate getTristate(std::string const& val) {
      if (val == "0") {
	return Tristate::FALSE;
      } else if (val == "1") {
	return Tristate::TRUE;
      }

      return Tristate::UNDEFINED;
    }

  private:
    ComponentFactory();

    static ComponentFactory _instance;

    typedef AComponent *(ComponentFactory::*mkComp)(std::string const& value) const;

    static const std::map<std::string, mkComp> _funcMap;

    template<class T>
    AComponent *newComp(std::string const& val) const {
      return new T(getTristate(val));
    }
  };
}

#endif //!COMPONENT_FACTORY_HPP_
