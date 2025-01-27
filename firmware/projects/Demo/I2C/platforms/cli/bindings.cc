#include <unistd.h>

#include <iostream>

#include "../../bindings.h"
#include "mcal/cli/periph/gpio.h"
#include "mcal/cli/periph/i2c.h"
#include "shared/periph/gpio.h"
#include "shared/periph/i2c.h"

namespace mcal::cli {

periph::I2C i2c_bus1{1};
periph::I2C i2c_bus2{2};
periph::DigitalOutput indicator{"Indicator"};

}  // namespace mcal::cli

namespace bindings {

shared::periph::DigitalOutput& indicator = mcal::cli::indicator;
shared::periph::I2C<mcal::cli::periph::I2C>& i2c_bus1 = mcal::cli::i2c_bus1;
shared::periph::I2C<mcal::cli::periph::I2C>& i2c_bus2 = mcal::cli::i2c_bus2;

void DelayMS(unsigned int ms) {
    usleep(ms * 1000);
}

void Initialize() {
    std::cout << "Initializing the CLI..." << std::endl;
}

}  // namespace bindings