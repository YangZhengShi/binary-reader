#ifndef MSAB_BIN_H
#define MSAB_BIN_H

#include "../util/Util.h"

template <size_t N,typename T> class bin {

    static std::vector<std::array<char, N>> getFile(const std::string &fileName);

    static void extractRecords(std::vector<T> *vector,const std::vector<std::array<char, N>> &data);

    static void writeToTXT(const std::vector<T> &data, const std::string &fileName);

    virtual void write(const T&, std::ostream *) = 0;

};

#endif
