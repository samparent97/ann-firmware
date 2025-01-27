#include "msg.h"
#include <iostream>

int main() {
    try {
        std::cout << "Starting test program...\n";
        
        // Test Write Message
        uint8_t write_buffer[] = {0xDE, 0xAD, 0xBE, 0xEF};
        const uint8_t write_address = 0x97;
        
        std::cout << "Creating write message...\n";
        shared::i2c::Message write_msg(
            write_address,
            write_buffer,
            shared::i2c::MessageType::Write
        );
        
        std::cout << "Write message created successfully\n";
        std::cout << std::format("{}\n", write_msg);

        // Test Read Message
        uint8_t read_buffer[] = {0x01, 0x02};  // Register addresses to read from
        const uint8_t read_address = 0x48;
        
        std::cout << "\nCreating read message...\n";
        shared::i2c::Message read_msg(
            read_address,
            read_buffer,
            shared::i2c::MessageType::Read
        );
        
        std::cout << "Read message created successfully\n";
        std::cout << std::format("{}\n", read_msg);
        
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception caught" << std::endl;
        return 1;
    }

    return 0;
}