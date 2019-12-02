#ifndef MSAB_CALL_H
#define MSAB_CALL_H

#include "../api/bin.h"
/**
 * The appropriate format of a record is shown on notes.txt.
 *
 * By calling the private constructor, the record is parsed based on its positions
 * (for example the phone number is placed on chars 58 to 68) so when the data
 * and the object is created it will be put into the vector records where it will be read later
 * entry by entry to place every record on the output stream.
 * */
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

    ~call(){
        free(&records);
    }
};

#endif
