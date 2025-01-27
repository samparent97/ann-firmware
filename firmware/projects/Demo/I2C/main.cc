#include <cstdint>

#include "bindings.h"
#include "shared/comms/i2c/msg.h"

int main() {
    bindings::Initialize();

    while (true) {
        uint8_t data1[] = {0x02, 0x03, 0x05};

        bindings::i2c_bus1.Transmit(
            shared::i2c::Message(0x01, data1, shared::i2c::MessageType::Write));
        bindings::DelayMS(1000);

        uint8_t data2[3];
        bindings::i2c_bus2.Transmit(
            shared::i2c::Message(0x03, data2, shared::i2c::MessageType::Read));
        bindings::DelayMS(1000);
    }

    return 0;
}