#include "util.h"

namespace util::copy{

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

                if(!util::isLetter(record.at(offset + i)))result.at(i) = constants::SPACE;

                else result.at(i) = record.at(offset + i);
            }
            return std::string(std::begin(result), std::end(result));
        }

    template<size_t N> static std::string deleted(const std::array<char,N> &record){

        std::array<char,1> result{};

        result.at(0) = record.at(85);

        if (result.at(0)== static_cast<char>(0xD7)) return std::string("deleted");

        else return std::string("not deleted");
    }

        template<size_t N> static std::string company(const std::array<char,N> &record, size_t offset){

            std::array<char,constants::NAME_SIZE> result{};

            for (size_t i = 0; i< constants::NAME_SIZE; i++) {

                if(!util::isLetter(record.at(offset + i)))result.at(i) = constants::SPACE;

                else result.at(i) = record.at(offset + i);
            }
            return std::string(std::begin(result), std::end(result));
        }

    template<size_t N> static std::string eMail(const std::array<char,N> &record, size_t offset){

        std::array<char,constants::MAIL_SIZE> result{};

        for (size_t i = 0; i< constants::MAIL_SIZE; i++) {

            if(!util::isEmail(record.at(offset + i)))result.at(i) = constants::SPACE;

            else result.at(i) = record.at(offset + i);
        }

        if(std::string(std::begin(result),std::end(result)).find(".com") != std::string::npos) return std::string(std::begin(result), std::end(result));

        else if(std::string(std::begin(result),std::end(result)).find('.') != std::string::npos){

            auto found  = std::string(std::begin(result),std::end(result)).find('.') + 3;

            for(auto i = found; i< result.size(); i++) result.at(i) =' ';
        }

        else if(std::string(std::begin(result),std::end(result)).find('@') == std::string::npos) for(auto &el : result) el =' ';

        return std::string(std::begin(result), std::end(result));
    }

        template<size_t N> static std::string duration(const std::array<char,N> &record,size_t offset){

            std::array<char, constants::DURATION_SIZE> result{};

            for (size_t i = 0; i<constants::DURATION_SIZE; i++) result.at(i) =util::hexToInt(record.at(offset + i));

            return std::string(std::begin(result), std::end(result));
        }

        template<size_t N> static std::string number(const std::array<char,N> &record,size_t offset){

            std::array<char, constants::NUMBER_SIZE> result{};

            for (size_t i = 0; i<constants::NUMBER_SIZE; i++){

                if (!util::isNumber(record.at(offset + i))) result.at(i) = constants::SPACE;

                else result.at(i) = record.at(offset+ i);
            }

            if(std::string(std::begin(result),std::end(result)).find(constants::SPACE) != std::string::npos)for(auto i = std::string(std::begin(result),std::end(result)).find(constants::SPACE) +1; i<result.size(); i++)result.at(i) = constants::SPACE;

            return std::string(std::begin(result), std::end(result));
        }
    }