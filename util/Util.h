#ifndef MSAB_UTIL_H
#define MSAB_UTIL_H

#include <vector>
#include <filesystem>
#include <fstream>
#include <cstddef>
#include <array>

#include "../util/copy.h"
#define BINARIES "binaries"

#define BIN ".bin"

#define TXT ".txt"


namespace util {

    static std::vector<std::string> getFiles();

    static int hexToInt(char ch);
}

#endif
