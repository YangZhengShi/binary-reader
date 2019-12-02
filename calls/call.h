#ifndef MSAB_CALL_H
#define MSAB_CALL_H

#include "../api/bin.h"
/**
 * The appropriate format of a record is shown on notes.txt.
 *
 * By calling the private constructor, the record is parsed based on its positions
 * (for example the phone number is placed on chars 58 to 68) so when the data
 * and the object is created it will be put into the vector records where it will be read later
 * entry by entry to place every record on the output stream.
 * */
template<size_t N>class call{

    std::string type;

    std::string name;

    std::string number;

    std::string duration;

    std::vector<call> records;

public:

    static void write(const call &call, std::ostream *out){
        *out << "PHONE NUMBER: " << call.number << " TYPE OF CALL: " << call.type << call.name <<  std::endl;
    }


    explicit call(const std::array<char,N> &record){

        this->name      = util::copy::name(record,util::constants::NAME_IN_CALLS_OFFSET);

        this->type      = util::copy::type(record,util::constants::TYPE_OFFSET);

        this->duration  = util::copy::duration(record,util::constants::DURATION_OFFSET);

        this->number    = util::copy::number(record,util::constants::NUMBER_IN_CALLS_OFFSET);
    }

    explicit call(const std::string &fileName){

        this->records=bin<N,call>::extractRecords(bin<N,call>::getFile(fileName));

        bin<N,call>::writeToTXT(this->records,fileName);
    }
};

#endif
