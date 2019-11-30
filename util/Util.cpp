#include "Util.h"

namespace util{

    static std::vector<std::string> getFiles(){

        std::vector<std::string> files;

        for (const auto& entry : std::filesystem::directory_iterator(std::filesystem::current_path()/BIN)) files.emplace_back(std::filesystem::current_path()/BIN/entry.path().filename().string());

        return files;
    }
}