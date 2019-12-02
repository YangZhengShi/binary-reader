#ifndef MSAB_CALL_H
#define MSAB_CALL_H

#include "../api/bin.h"

template<size_t N>class call{

    std::string type;

    std::string name;

    std::string number;

    std::string duration;

    std::vector<call> records;

    explicit call(const std::array<char,N> &);

    static void write(const call &, std::ostream *);

public:

    explicit call(const std::string &fileName);
};

#endif
