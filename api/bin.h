#ifndef MSAB_BIN_H
#define MSAB_BIN_H

#include <array>
#include <fstream>
#include <vector>
#include "../util/Util.h"

template <size_t N> class bin {

    virtual std::vector<std::array<char, N>> getFile(const std::string &) = 0;

    virtual void extractRecords(const std::vector<std::array<char,N>> &) = 0;

    virtual void writeToTXT(const std::vector<std::vector<std::string>> &, const std::string&) = 0;

};

#endif
