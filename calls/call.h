#ifndef MSAB_CALL_H
#define MSAB_CALL_H

#include "../api/bin.h"

template<size_t N, typename T>class call: bin<N,T> {

    std::string type;

    std::string name;

    std::string number;

    std::string duration;

    std::vector<call> records;

    explicit call(const std::array<char,N> &);

    void write(const T &t, std::ostream *out) override;

public:

    explicit call(const std::string &fileName);
};

#endif
