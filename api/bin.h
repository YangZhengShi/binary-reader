#ifndef MSAB_BIN_H
#define MSAB_BIN_H

#include "../util/util.h"

template <size_t N,class T> class bin {

public:

    static std::vector<std::array<char, N>> getFile(const std::string &);

    static void extractRecords(std::vector<T> *,const std::vector<std::array<char, N>> &,const std::vector<std::array<char, N>> &);

    static void writeToTXT(const std::vector<T> &data, const std::string &fileName);

};

#endif
