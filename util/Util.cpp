#include "Util.h"

namespace util{

    static std::vector<std::string> getFiles(){

        std::vector<std::string> files;

        for (const auto& entry : std::filesystem::directory_iterator(std::filesystem::current_path()/BIN)) files.emplace_back(std::filesystem::current_path()/BIN/entry.path().filename().string());

        return files;
    }

    static int hexToInt(char ch){

        if (ch >= '0' && ch <= '9') return ch - '0';

        if (ch >= 'A' && ch <= 'F') return ch - 'A' + 10;

        if (ch >= 'a' && ch <= 'f') return ch - 'a' + 10;

        return -1;
    }
}