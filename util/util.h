#ifndef MSAB_UTIL_H
#define MSAB_UTIL_H

#include <vector>
#include <filesystem>
#include <fstream>
#include <cstddef>
#include <array>

namespace util {

    namespace constants{

        static const std::array<char, 8> DIALED_NOT_SAVED =   {static_cast<char>(0xFF),0x00,static_cast<char>(0xFF),
                                                               static_cast<char>(0xFF),0x00,0x00,0x00,0x00};

        static const std::array<char, 8> MISSED_NOT_SAVED =   {static_cast<char>(0xFF),0x02,static_cast<char>(0xFF),
                                                               static_cast<char>(0xFF),0x40,0x00,0x04,0x00};

        static const std::array<char, 8> RECEIVED_NOT_SAVED = {static_cast<char>(0xFF),0x02,static_cast<char>(0xFF),
                                                               static_cast<char>(0xFF),static_cast<char>(0x80),0x00,0x00,0x00};

        static const std::array<char, 8> DIALED_SAVED =       {0x06,0x00};

        static const char SPACE                    = ' ';

        static const std::string BINARIES = std::string("binaries");

        static const std::string BIN = std::string(".bin");

        static const std::string TXT = std::string(".txt");

        static const std::string CALLS = std::string("Calls");

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

        static const size_t WORK_OFFSET            = 145;

        static const size_t FAX_OFFSET             = 187;

        static const size_t TEL_OFFSET             = 42;

        static const size_t MAIL_OFFSET            = 84;

        static const size_t NAME_IN_CONTACTS_OFFSET= 0;

        static const size_t NAME_IN_CONTACTS_SIZE  = 15;

        static const size_t NUMBER_IN_MAIN_OFFSET  = 42;

        static const size_t ORG_SIZE               = 20;

        static const size_t MAIL_SIZE              = 17;

        static const size_t ORG_OFFSET             = 42;
    }

    namespace copy {

        template<size_t N> static std::string deleted(const std::array<char,N> &record);

        template<size_t N> static std::string eMail(const std::array<char,N> &record, size_t offset);

        template<size_t N> static std::string company(const std::array<char,N> &record, size_t offset);

        template<size_t N> static std::string type(const std::array<char,N> &record,size_t offset);

        template<size_t N> static std::string name(const std::array<char,N> &record, size_t offset);

        template<size_t N> static std::string duration(const std::array<char,N> &record,size_t offset);

        template<size_t N> static std::string number(const std::array<char,N> &record,size_t offset);

    }


    //could be used to dynamically find all the possible files that should be used in the correct directory
    static std::vector<std::string> getFiles();

    static int hexToInt(char ch);

    static inline bool isLetter(char ch){
        return (ch>=65 && ch <= 90) || (ch>= 97 && ch <=122);
    }

    static inline bool isNumber(char ch){
        return ch >=48 && ch <57;
    }

    static inline bool isEmail(char ch){
        return (ch >= 48 && ch <=57) ||(ch>=65 && ch <= 90) || (ch>= 97 && ch <=122)|| ch == static_cast<char>(0x2e) || ch== static_cast<char>(40);
    }
}

#endif
