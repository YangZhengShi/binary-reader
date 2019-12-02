#include <iostream>
#include "util/util.h"
#include "calls/call.h"

int main() {

    auto sources = util::getFiles();

    for(const auto& e: sources){

        if(e.find(util::constants::CALLS) != std::string::npos) call<util::constants::CALLS_RECORD_SIZE> call(e);
    }

}

