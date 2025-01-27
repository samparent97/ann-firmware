/// @author Samuel Parent, Hydar Zartash
/// @date 2024-11-21

#pragma once

#include "shared/comms/i2c/msg.h"
#include "shared/util/peripheral.h"

namespace shared::periph {

class I2C : public util::Peripheral {
public:
    template<size_t N>
    void Transmit(const shared::i2c::Message<N>& msg) {
        TransmitImpl(msg);
    }

protected:
    virtual ~I2C() = default;
    
    template<size_t N>
    virtual void TransmitImpl(const shared::i2c::Message<N>& msg) = 0;
};

}  // namespace shared::periph
