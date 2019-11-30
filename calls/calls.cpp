#include "calls.h"
#include "copy.h"

template<size_t N> calls<N>::calls(const std::string &fileName) {

    auto records = getFile(fileName);

    auto data = extractRecords(records);

    writeToTXT(data);
}

template<size_t N> std::vector<std::array<char,N>> calls<N>::getFile(const std::string &fileName) {

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

template<size_t N> std::vector<std::vector<std::string>> calls<N>::extractRecords(const std::vector<std::array<char, N>> &data) {

    std::vector<std::vector<std::string>> result;

    result.reserve(data.size());

    for(auto e: data) result.emplace_back(copy::deepCopy(e));

    return result;
}

template<size_t N> void calls<N>::writeToTXT(const std::vector<std::vector<std::string>> &vector) {

}
