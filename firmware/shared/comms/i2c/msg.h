#include <concepts>
#include <cstdint>
#include <cstring>
#include <format>
#include <string>

#pragma once

namespace shared::i2c {

enum class MessageType {
    Read,
    Write,
    WriteRead,
};

template <size_t N>
struct Message {
    Message(uint8_t address_, const uint8_t (&data_)[N], MessageType type_)
        : address(address_),
          data_length(N),  // Always use full buffer size
          type(type_) {
        std::memcpy(data, data_, N);  // Do we really need this?
    }

    MessageType type;
    uint8_t address;
    uint8_t data_length;  // Kept in struct but now initialized from N
    uint8_t data[N];
};

// Deduction guide
template <size_t N>
Message(uint8_t, const uint8_t (&)[N], MessageType) -> Message<N>;

}  // namespace shared::i2c

// Convert Message to string with `std::format`
template <size_t N>
struct std::formatter<shared::i2c::Message<N>> {
    constexpr auto parse(auto& ctx) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const shared::i2c::Message<N>& msg, FormatContext& ctx) const {
        std::string str = std::format("[{:02X}]", msg.address);

        if (msg.type == shared::i2c::MessageType::Write) {
            str += std::format(" WR ->");
        } else {
            str += std::format(" RD <-");
        }

        for (int i = 0; i < msg.data_length; ++i) {
            str += std::format(" {:02X}", msg.data[i]);
        }

        return std::format_to(ctx.out(), "{}", str);
    }
};