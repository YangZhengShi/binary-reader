#ifndef MSAB_CONTACT_H
#define MSAB_CONTACT_H

#include "../api/bin.h"

template<size_t N> class contact {

    std::vector<contact> records;

    std::string name;

    std::string tel;

    std::string fax;

    std::string home;

    std::string work;

    std::string email;

    std::string org;

    std::string deleted;

    explicit contact(const std::array<char,N> &, const std::array<char,N> &);

    void write(const contact &, std::ostream *) override;

public:

    explicit contact(const std::string &,const std::string &);

};

#endif