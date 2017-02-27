//
// Jdecade-4017.cpp for Jdecade-4017 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Fri Feb 17 16:50:28 2017 Riamon Vincent
//

#include "gates/Jdecade-4017.hpp"

nts::Jdecade4017::Jdecade4017(Tristate val) : AComponent(CONST::C4017, val, 14) {
  _outputs[3] = {.clock = 14, .master_reset = 15, Tristate::UNDEFINED};
  _outputs[2] = {.clock = 14, .master_reset = 15, Tristate::UNDEFINED};
  _outputs[4] = {.clock = 14, .master_reset = 15, Tristate::UNDEFINED};
  _outputs[7] = {.clock = 14, .master_reset = 15, Tristate::UNDEFINED};
  _outputs[10] = {.clock = 14, .master_reset = 15, Tristate::UNDEFINED};
  _outputs[1] = {.clock = 14, .master_reset = 15, Tristate::UNDEFINED};
  _outputs[5] = {.clock = 14, .master_reset = 15, Tristate::UNDEFINED};
  _outputs[6] = {.clock = 14, .master_reset = 15, Tristate::UNDEFINED};
  _outputs[9] = {.clock = 14, .master_reset = 15, Tristate::UNDEFINED};
  _outputs[11] = {.clock = 14, .master_reset = 15, Tristate::UNDEFINED};
}

nts::Jdecade4017::~Jdecade4017() {
}

static int isInput(size_t pin) {
  if (pin == 1 || pin == 2 || pin == 5 || pin == 6 ||
      pin == 8 || pin == 9 || pin == 12 || pin == 13) {
    return 1;
  } else if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
    return 0;
  }
  return -1;
}

nts::Tristate nts::Jdecade4017::nand_gate(size_t first_pin, size_t second_pin) const {
  return static_cast<Tristate>(!(first_pin && second_pin));
}

nts::Tristate nts::Jdecade4017::Compute(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    throw PinException(pinError(_type, this_pin));
  }
  if (isInput(this_pin))
    return Tristate::UNDEFINED;
  return Tristate::UNDEFINED;
}

nts::Tristate nts::Jdecade4017::calcInput(size_t this_pin) {
  if (!_pins[this_pin]) {
    return Tristate::UNDEFINED;
  }

  if (_pins[this_pin].comp->getType() == CONST::OUTPUT) {
    throw OutputException("Can't use output as an input");
  }

  return _pins[this_pin].compute();
}

nts::Tristate nts::Jdecade4017::calcOutput(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    return Tristate::UNDEFINED;
  }

  size_t firstPin = _outputs[this_pin].first;
  size_t secondPin = _outputs[this_pin].second;

  if (!_pins[firstPin] || !_pins[secondPin]) {
    return Tristate::UNDEFINED;
  }

  return nand_gate(_pins[firstPin].compute(), _pins[secondPin].compute());
}
