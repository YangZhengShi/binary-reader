#ifndef MSAB_BIN_H
#define MSAB_BIN_H

#include "../util/util.h"
/**
 * Basic API for extracting and storing the results of the manipulation of the binary files.
 *
 * -getFile(const std::string &) template function reads and returns a vector of arrays with the characters.
 * Based on the format and the structure of every record, it is constructed with fixed size bytes
 * so every array in the vector represents a record that will be handled accordingly.
 *
 * -extractRecords(std::vector<T> *,const std::vector<std::array<char, N>> &) reads every entry from the getFile
 * function and stores the results in every objects vector(eg calls are read by getFile,
 * the results are parsed and extracted in its private constructor and stored on the vector as objects).
 *
 * Note that for the Phonebook and contacts there are 2 vectors filled separately with objects
 * and then merged in the final vector(see implementation of the constructor of contacts).
 *
 * -writeToTXT(const std::vector<T> &data, const std::string &fileName) creates a proper name for the output,
 * make an output file stream to write the results and for every entry(record on the vector of objects it takes
 * as argument it's calling the objects specific write method where it formats the output into a human readable form)
 * */
template <size_t N,class T> class bin {

public:

    static std::vector<std::array<char, N>> getFile(const std::string &);

    static void extractRecords(std::vector<T> *,const std::vector<std::array<char, N>> &);

    static void writeToTXT(const std::vector<T> &data, const std::string &fileName);

};

#endif
