#ifndef MSAB_COPY_H
#define MSAB_COPY_H

#include "constants.h"

namespace copy{

    static std::string type(const std::array<char,106> &record) {

        std::array<char,8> temp{};

        for (size_t i = 0; i < 8; i++) temp.at(i) = record.at(4 + i);

        if(temp==constants::DIALED_NOT_SAVED)         return std::string( "WAS DIALED BUT NOT SAVED");

        else if (temp==constants::MISSED_NOT_SAVED)   return std::string( "WAS MISSED BUT NOT SAVED");

        else if (temp==constants::RECEIVED_NOT_SAVED) return std::string( "WAS RECEIVED BUT NOT SAVED");

        else if (temp==constants::DIALED_SAVED)       return std::string( "WAS DIALED AND SAVED AS");

        else                                          return std::string( "NOTHING HAPPENED");
    }

    static std::string name(const std::array<char,106> &record){

        std::array<char,42> result{};

        for (size_t i = 0; i< 42; i++) {

            if(record.at(16 + i) == static_cast<char>(0x00))result.at(i) = constants::SPACE;

            else result.at(i) = record.at(16 + i);
        }

        return std::string(std::begin(result), std::end(result));
    }

    static std::string duration(const std::array<char,106> &record){

        std::array<char, 33> result{};

        for (size_t i = 0; i<33; i++) result.at(i) =util::hexToInt(record.at(68 + i));

        return std::string(std::begin(result), std::end(result));
    }

    static std::string number(const std::array<char,106> &record){

        std::array<char, 10> result{};

        for (size_t i = 0; i<10; i++){

            if (record.at(58 + i) <= 48) result.at(i) = constants::SPACE;

            else result.at(i) = record.at(58 + i);
        }

        return std::string(std::begin(result), std::end(result));
    }
}

#endif
