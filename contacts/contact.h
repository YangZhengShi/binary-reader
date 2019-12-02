#ifndef MSAB_CONTACT_H
#define MSAB_CONTACT_H

#include "../api/bin.h"

template<size_t N,size_t M> class contact {

    std::vector<contact> main;

    std::vector<contact> details;

    std::vector<contact> final;

    std::string name;

    std::string tel;

    std::string fax;

    std::string home;

    std::string work;

    std::string email;

    std::string org;

    std::string deleted;

    //merge the 2 different contacts created on main and details(since they are added on the same index it is enough to create a final contact to be added on main vector)
    contact(const contact &,const contact &);

    //create a contact based on the raw records received from both the binary files
    explicit contact(const std::array<char,N> &, const std::array<char,M> &);

    //Write the final contact to the specific output stream
    void write(const contact &, std::ostream *);

public:

    //public constuctor for creating the contacts
    explicit contact(const std::string &,const std::string &);
    ~contact(){
        free(&main);
        free(&details);
        free(&final);
    };

};

#endif