#ifndef MSAB_CALL_H
#define MSAB_CALL_H

#include "../api/bin.h"
#include "copy.h"

template <size_t N>class call : public bin<N> {

    static std::vector<call> phoneCalls;

    std::string type;

    std::string name;

    std::string number;

    std::string duration;

    explicit call(const std::array<char,106> &);

    friend std::ostream& operator<<(std::ostream&, const call<106> &);

    std::vector<std::array<char,N>> getFile(const std::string &fileName) override;

    void extractRecords(const std::vector<std::array<char, N>> &vector) override;

    void writeToTXT(const std::vector<std::vector<std::string>> &, const std::string &) override;

public:

    //works as a driver if a call binary is detected
    explicit call(const std::string &fileName);
};

#endif
