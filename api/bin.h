#ifndef MSAB_BIN_H
#define MSAB_BIN_H

#include "../util/util.h"

template <size_t N,class T> class bin {

public:

    static std::vector<std::array<char, N>> getFile(const std::string &fileName);

    static void extractRecords(std::vector<T> *vector,const std::vector<std::array<char, N>> &data);

    static void writeToTXT(const std::vector<T> &data, const std::string &fileName);

};

#endif
