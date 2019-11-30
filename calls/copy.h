#ifndef MSAB_COPY_H
#define MSAB_COPY_H

#include <cstddef>
#include <array>
#include "constants.h"

#define SPACE ' '

namespace copy{

    static int hex2int(const char ch){

        if (ch >= '0' && ch <= '9') return ch - '0';

        if (ch >= 'A' && ch <= 'F') return ch - 'A' + 10;

        if (ch >= 'a' && ch <= 'f') return ch - 'a' + 10;

        return -1;
    }

    static void copyType(const std::array<char,106> &s, std::string *dest) {

        std::array<char,8> temp{};

        for (size_t i = 0; i < 8; i++) temp.at(i) = s.at(4 + i);

        if(std::equal(std::begin(temp),std::end(temp),constants::DIALED_NOT_SAVED))         *dest = "dialed and not saved";

        else if (std::equal(std::begin(temp),std::end(temp),constants::MISSED_NOT_SAVED))   *dest = "missed and not saved";

        else if (std::equal(std::begin(temp),std::end(temp),constants::RECEIVED_NOT_SAVED)) *dest = "received and not saved";

        else if (std::equal(std::begin(temp),std::end(temp),constants::DIALED_SAVED))       *dest = "dialed and saved";

        else                                                                                       *dest = "unknown operation";
    }

    static void copyName(const std::array<char,106> &s, std::array<char,42> *dest){

        for (size_t i = 0; i< 42; i++) {

            if(s.at(16+i) == static_cast<char>(0x00))dest->at(i) = SPACE;

            else dest->at(i) = s.at(16 + i);
        }
        //could use to remove some spaces but i get bugged result
        //std::remove(std::begin(*dest),std::end(*dest),' ');
    }

    static void copyDuration(const std::array<char,106> &s, std::array<char,33> *dest){

        for (size_t i = 0; i<33; i++) dest->at(i) =hex2int(s.at(68+i));
    }

    static void copyNumber(const std::array<char,106> &s, std::array<char,10> *dest){

        for (size_t i = 0; i<10; i++){

            if (s.at(58+i) <= 48) dest->at(i) = SPACE;

            else dest->at(i) =hex2int(s.at(58+i));
        }
    }

    static std::vector<std::string> deepCopy(std::array<char,106> record){

        std::vector<std::string> result;

        std::string type;

        std::array<char,42> name{};

        std::array<char,10> number{};

        std::array<char,33> dur{};

        copyType(record,&type);

        copyName(record,&name);

        copyDuration(record,&dur);

        copyNumber(record,&number);

        result.emplace_back(std::string(std::begin(type),std::end(type)));

        result.emplace_back(std::string(std::begin(name),std::end(name)));

        result.emplace_back(std::string(std::begin(number),std::end(number)));

        result.emplace_back(std::string(std::begin(dur),std::end(dur)));

        return result;
    }
}

#endif
