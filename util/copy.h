#ifndef MSAB_COPY_H
#define MSAB_COPY_H

#include "constants.h"
#include "Util.h"

namespace copy{

    template<size_t N> static std::string type(const std::array<char,N> &record,size_t offset) {

        std::array<char,constants::TYPE_SIZE> temp{};

        for (size_t i = 0; i < constants::TYPE_SIZE; i++) temp.at(i) = record.at(offset + i);

        if(temp==constants::DIALED_NOT_SAVED)         return std::string( "WAS DIALED BUT NOT SAVED");

        else if (temp==constants::MISSED_NOT_SAVED)   return std::string( "WAS MISSED BUT NOT SAVED");

        else if (temp==constants::RECEIVED_NOT_SAVED) return std::string( "WAS RECEIVED BUT NOT SAVED");

        else if (temp==constants::DIALED_SAVED)       return std::string( "WAS DIALED AND SAVED AS");

        else                                          return std::string( "NOTHING HAPPENED");
    }

    template<size_t N> static std::string name(const std::array<char,N> &record, size_t offset){

        std::array<char,constants::NAME_SIZE> result{};

        for (size_t i = 0; i< constants::NAME_SIZE; i++) {

            if(record.at(offset + i) == static_cast<char>(0x00))result.at(i) = constants::SPACE;

            else result.at(i) = record.at(offset + i);
        }
        return std::string(std::begin(result), std::end(result));
    }

    template<size_t N> static std::string duration(const std::array<char,N> &record,size_t offset){

        std::array<char, constants::DURATION_SIZE> result{};

        for (size_t i = 0; i<33; i++) result.at(i) =util::hexToInt(record.at(offset + i));

        return std::string(std::begin(result), std::end(result));
    }

    template<size_t N> static std::string number(const std::array<char,N> &record,size_t offset){

        std::array<char, constants::NUMBER_SIZE> result{};

        for (size_t i = 0; i<constants::NUMBER_SIZE; i++){

            if (record.at(58 + i) <= constants::NOT_A_NUMBER) result.at(i) = constants::SPACE;

            else result.at(i) = record.at(offset+ i);
        }
        return std::string(std::begin(result), std::end(result));
    }
}

#endif
