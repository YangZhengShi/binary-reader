#include "call.h"

template<size_t N> call<N>::call(const std::array<char, N> &record) {

    this->name      = util::copy::name(record,util::constants::NAME_IN_CALLS_OFFSET);

    this->type      = util::copy::type(record,util::constants::TYPE_OFFSET);

    this->duration  = util::copy::duration(record,util::constants::DURATION_OFFSET);

    this->number    = util::copy::number(record,util::constants::NUMBER_IN_CALLS_OFFSET);
}

template<size_t N>call<N>::call(const std::string &fileName) {

    bin<N,call>::extractRecords(this->calls,bin<N,call>::getFile(fileName));

    bin<N,call>::writeToTXT(this->calls,fileName);
}

template<size_t N> void call<N>::write(const call &call, std::ostream *out) {
    *out << "PHONE NUMBER: " << call.number << " TYPE OF CALL: " << call.type << " DURATION: " << call.duration << " CONTACT NAME(IF THE NUMBER IS SAVED): " << call.name << std::endl;
}
