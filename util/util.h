#ifndef MSAB_UTIL_H
#define MSAB_UTIL_H

#include <vector>
#include <filesystem>
#include <fstream>
#include <cstddef>
#include <array>

/**
 * Utility functions for the module.
 *
 * Since there are parts on the records that are not recognisable by text, i hard coded some sequences
 * that i made sense of wat they would mean.
 *
 * For example the DIALED_NOT_SAVED array of chars corresponds to dialed but the number is not saved
 * (used the pictures provided for the assignment in order to know which record is what so i could make the codes).
 *
 * The sizes of every part of the record are hardcoded and evaluated on compile time since array allocation
 * and templates need to know the number on compile time(static data structures).
 *
 * Offsets are calculated based on the observation of the records(see different classes with their notes.txt).
 *
 * the copy namespace plays a vital role on the code since it is actually using these values and extracting the data
 * from chars to the string fields on every class.
 *
 * email is being cleaned as well since it can detect where there are extra characters that should not be there
 * (based on the results)
 *
 * duration on every call is represented as a hex number on the record so a function hextoint was made to help
 * the situation.
 *
 * getfiles is an extra function for further automation since it could read the files on the directory
 * where the binaries are stored.
 *
 * one idea to improve the solution was to automate the process of finding the record size based on the most frequent
 * character but would not work since there were some "corrupted" chars on the binary and would not gie clear results back.
 *
 *
 * */
namespace util {

    static int hex2int(char hex) {

        int val = 0;

        if (hex >= '0' && hex <= '9') val = hex - '0';

        else if (hex >= 'a' && hex <= 'f') val = hex - 'a' + 10;

        else if (hex >= 'A' && hex <= 'F') val = hex - 'A' + 10;

        return val;
    }

    static inline bool isLetter(char ch){
        return (ch>=65 && ch <= 90) || (ch>= 97 && ch <=122);
    }

    static inline bool isNumber(char ch){
        return ch >=48 && ch <58;
    }

    static inline bool isEmail(char ch){
        return (ch >= 48 && ch <=58) ||(ch>=64 && ch <= 90) || (ch>= 97 && ch <=122)|| ch == static_cast<char>(0x2e) || ch== static_cast<char>(40);
    }

    static inline bool isValid(char ch){
        return isNumber(ch) || isLetter(ch);
    }

    namespace constants{

        static const std::array<char, 8> DIALED_NOT_SAVED =   {static_cast<char>(0xFF),0x00,static_cast<char>(0xFF),
                                                               static_cast<char>(0xFF),0x00,0x00,0x00,0x00};

        static const std::array<char, 8> MISSED_NOT_SAVED =   {static_cast<char>(0xFF),0x02,static_cast<char>(0xFF),
                                                               static_cast<char>(0xFF),0x40,0x00,0x04,0x00};

        static const std::array<char, 8> RECEIVED_NOT_SAVED = {static_cast<char>(0xFF),0x02,static_cast<char>(0xFF),
                                                               static_cast<char>(0xFF),static_cast<char>(0x80),0x00,0x00,0x00};

        static const std::array<char, 2> DIALED_SAVED =       {0x06,0x00};

        static const char SPACE                    = ' ';

        static const std::string BINARIES = std::string("binaries");

        static const std::string BIN = std::string(".bin");

        static const std::string TXT = std::string(".txt");

        static const std::string CALLS = std::string("/binaries/Calls.bin");

        static const std::string DETAILS = std::string("/binaries/Phonebook_Details.bin");

        static const std::string MAIN = std::string("/binaries/Phonebook_Main.bin");

        static const size_t CALLS_RECORD_SIZE      = 106;

        static const size_t PHONEBOOK_RECORD_SIZE  = 232;

        static const size_t PHONEBOOK_MAIN_SIZE    = 86;

        static const size_t TYPE_SIZE              = 8;

        static const size_t TYPE_OFFSET            = 4;

        static const size_t NAME_SIZE              = 42;

        static const size_t NAME_IN_CALLS_OFFSET   = 16;

        static const size_t DURATION_SIZE          = 30;

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

        static const size_t ORG_SIZE               = 19;

        static const size_t MAIL_SIZE              = 17;

        static const size_t ORG_OFFSET             = 42;
    }

    namespace copy {

        template<size_t N> static std::string type(const std::array<char,N> &record,size_t offset) {

            std::array<char,constants::TYPE_SIZE> temp{};

            std::array<char,2> dialedAndSaved{};

            for (size_t i = 0; i < constants::TYPE_SIZE; i++) temp.at(i) = record.at(offset + i);
            dialedAndSaved.at(0) = temp.at(0);
            dialedAndSaved.at(1) = temp.at(1);

            if(temp==constants::DIALED_NOT_SAVED)                   return std::string("WAS DIALED BUT NOT SAVED:     ");

            else if (temp==constants::MISSED_NOT_SAVED)             return std::string("WAS MISSED BUT NOT SAVED:     ");

            else if (temp==constants::RECEIVED_NOT_SAVED)           return std::string("WAS RECEIVED BUT NOT SAVED:   ");

            else if (dialedAndSaved==constants::DIALED_SAVED)       return std::string("WAS DIALED AND SAVED AS:      ");

            else                                                    return std::string( " ");
        }

        template<size_t N> static std::string nameInContacts(const std::array<char,N> &record, size_t offset){

            std::array<char,constants::NAME_IN_CONTACTS_SIZE> result{};

            for (size_t i = 0; i< constants::NAME_IN_CONTACTS_SIZE; i++) {

                if(!isValid(record.at(offset + i)))result.at(i)= constants::SPACE;

                else result.at(i) = record.at(offset + i);
            }
            return std::string(std::begin(result), std::end(result));
        }

        template<size_t N> static std::string name(const std::array<char,N> &record, size_t offset){

            std::array<char,constants::NAME_SIZE> result{};

            for (size_t i = 0; i< constants::NAME_SIZE; i++) {

                if(!isValid(record.at(offset + i)))result.at(i)= constants::SPACE;

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

            std::array<char,constants::ORG_SIZE> result{};

            for (size_t i = 0; i< constants::ORG_SIZE; i++) {

                if(!isValid(record.at(offset + i)))result.at(i) = constants::SPACE;

                else result.at(i) = record.at(offset + i);
            }
            return std::string(std::begin(result), std::end(result));
        }

        template<size_t N> static std::string eMail(const std::array<char,N> &record, size_t offset){

            std::array<char,constants::MAIL_SIZE> result{};

            for (size_t i = 0; i< constants::MAIL_SIZE; i++) {

                if(!isEmail(record.at(offset + i)))result.at(i) = constants::SPACE;

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

            std::array<char, constants::DURATION_SIZE+1> result{};

            for (size_t i = 0; i<=constants::DURATION_SIZE; i++) result.at(i) = hex2int(record.at(offset + i));

            return std::string(std::begin(result), std::end(result));
        }

        template<size_t N> static std::string number(const std::array<char,N> &record,size_t offset){

            std::array<char, constants::NUMBER_SIZE> result{};

            for (size_t i = 0; i<constants::NUMBER_SIZE; i++){

                if (!isNumber(record.at(offset + i))) result.at(i) = constants::SPACE;

                else result.at(i) = record.at(offset+ i);
            }

            if(std::string(std::begin(result),std::end(result)).find(constants::SPACE) != std::string::npos)for(auto i = std::string(std::begin(result),std::end(result)).find(constants::SPACE) +1; i<result.size(); i++)result.at(i) = constants::SPACE;

            return std::string(std::begin(result), std::end(result));
        }
    }
}

#endif
