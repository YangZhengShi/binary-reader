#include "call.h"

template<size_t N> std::vector<std::array<char,N>> call<N>::getFile(const std::string &fileName) {

    std::ifstream in(fileName, std::ios::in|std::ios::binary);

    std::vector<std::array<char,N>> result;

    assert(in);

    std::array<char,N> arr{};

    char ch;

    size_t counter = 0;

    while(in.get(ch)){

        if(counter == N){

            result.emplace_back(arr);

            counter = 0;
        }
        arr.at(counter++) = ch;
    }

    return result;
}

template<size_t N> call<N>::call(const std::array<char, 106> &record) {

    this->name = copy::name(record);

    this->type = copy::type(record);

    this->duration = copy::duration(record);

    this->number = copy::number(record);

}

template<size_t N> void call<N>::extractRecords(const std::vector<std::array<char, N>> &data) {

    for(auto e: data) phoneCalls.emplace_back(call(e));
}

std::ostream &operator<<(std::ostream &out, const call<106> &call) {
    return out << "PHONE NUMBER: " <<call.number << " TYPE OF CALL: " << call.type << " DURATION: " << call.duration << " CONTACT NAME(IF THE NUMBER IS SAVED): " << call.name << std::endl;
}

template<size_t N> void call<N>::writeToTXT(const std::vector<std::vector<std::string>> &data, const std::string &fileName) {

    std::string newName;

    std::replace_copy(std::begin(fileName),std::end(fileName),newName,std::string(".bin"),std::string(".txt"));

    std::ofstream out(newName);

    for(const auto &e : phoneCalls) out << e;

    out.close();

}

template<size_t N> call<N>::call(const std::string &fileName) {

    extractRecords(getFile(fileName));

    writeToTXT(fileName);
}
