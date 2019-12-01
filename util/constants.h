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

    static const char SPACE                    = ' ';

    static const size_t CALLS_RECORD_SIZE      = 106;

    static const size_t PHONEBOOK_RECORD_SIZE  = 232;

    static const size_t PHONEBOOK_MAIN_SIZE    = 86;

    static const size_t NOT_A_NUMBER           = 48;

    static const size_t TYPE_SIZE              = 8;

    static const size_t TYPE_OFFSET            = 4;

    static const size_t NAME_SIZE              = 42;

    static const size_t NAME_IN_CALLS_OFFSET   = 16;

    static const size_t DURATION_SIZE          = 33;

    static const size_t DURATION_OFFSET        = 68;

    static const size_t NUMBER_SIZE            = 22;

    static const size_t NUMBER_IN_CALLS_OFFSET = 58;

    static const size_t HOME_OFFSET            = 0;

    static const size_t WORK_OFFSET            = 146;

    static const size_t FAX_OFFSET             = 188;

    static const size_t TEL_OFFSET             = 42;

    static const size_t MAIL_OFFSET            = 85;

    static const size_t NAME_IN_CONTACTS_OFFSET= 0;

    static const size_t ORG_OFFSET             = 43;

}

#endif
