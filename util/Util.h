#ifndef MSAB_UTIL_H
#define MSAB_UTIL_H

#include <vector>
#include <filesystem>
#include <fstream>
#include <cstddef>
#include <array>

#define BIN "binaries"

namespace util {

    static std::vector<std::string> getFiles();

    static int hexToInt(char ch);
}

#endif
