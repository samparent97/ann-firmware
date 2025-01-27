/// @author Samuel Parent, Hydar Zartash
/// @date 2024-11-21

#pragma once

#include "shared/comms/i2c/msg.h"
#include "shared/periph/i2c.h"

namespace mcal::cli::periph {

class I2C : public shared::periph::I2C {
private:
    int bus_number_;

public:
    I2C(int bus_number) : bus_number_(bus_number) {}

protected:
    template<size_t N>
    void TransmitImpl(const shared::i2c::Message<N>& msg) override {
        std::string str = std::format("I2C{} - Tx: {}", bus_number_, msg);
    }
};

}  // namespace mcal::cli::periph