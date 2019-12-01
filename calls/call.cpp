#include "call.h"

template<size_t N, typename T> call<N,T>::call(const std::array<char, N> &record) {

    this->name      = copy::name(record,constants::NAME_IN_CALLS_OFFSET);

    this->type      = copy::type(record,constants::TYPE_OFFSET);

    this->duration  = copy::duration(record,constants::DURATION_OFFSET);

    this->number    = copy::number(record,constants::NUMBER_IN_CALLS_OFFSET);
}

template<size_t N,typename T>call<N,T>::call(const std::string &fileName) {

    extractRecords(this->calls,call::getFile<N>(fileName));

    writeToTXT(this->calls,fileName);
}

template<size_t N, typename T> void call<N, T>::write(const T &call, std::ostream *out) {
    *out << "PHONE NUMBER: " << call.number << " TYPE OF CALL: " << call.type << " DURATION: " << call.duration << " CONTACT NAME(IF THE NUMBER IS SAVED): " << call.name << std::endl;
}
