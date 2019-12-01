#ifndef MSAB_CONSTANTS_H
#define MSAB_CONSTANTS_H

#include <array>

namespace constants{

    static const std::array<char, 8> DIALED_NOT_SAVED =   {static_cast<char>(0xFF),0x00,static_cast<char>(0xFF),
                                                           static_cast<char>(0xFF),0x00,0x00,0x00,0x00};

    static const std::array<char, 8> MISSED_NOT_SAVED =   {static_cast<char>(0xFF),0x02,static_cast<char>(0xFF),
                                                           static_cast<char>(0xFF),0x40,0x00,0x04,0x00};

    static const std::array<char, 8> RECEIVED_NOT_SAVED = {static_cast<char>(0xFF),0x02,static_cast<char>(0xFF),
                                                           static_cast<char>(0xFF),static_cast<char>(0x80),0x00,0x00,0x00};

    static const std::array<char, 8> DIALED_SAVED =       {0x06,0x00};

    static const char SPACE = ' ';

}

#endif
