#ifndef MSAB_CONTACT_H
#define MSAB_CONTACT_H

#include "../api/bin.h"

template<size_t N,size_t M> class contact {

    std::vector<std::array<char,N>> main;

    std::vector<std::array<char,M>> details;

    std::vector<contact> final;

    std::string name;

    std::string tel;

    std::string fax;

    std::string home;

    std::string work;

    std::string email;

    std::string org;

    std::string deleted;

public:

    explicit contact(const std::string &main,const std::string &details) {

        for(std::array<char,N> e : bin<N,contact>::getFile(main))this->main.emplace_back(e);

        for(std::array<char,M> e : bin<M,contact>::getFile(details)) this->details.emplace_back(e);

        for (size_t i = 0; i < this->main.size(); i++)
            this->final.emplace_back(contact(this->main.at(i), this->details.at(i)));

        bin<N, contact>::writeToTXT(this->final, main);
    }

    explicit contact(const std::array<char,N> &main, const std::array<char,M> &details) {

        this->tel = util::copy::number(main, util::constants::TEL_OFFSET);

        this->name = util::copy::nameInContacts(main, util::constants::NAME_IN_CONTACTS_OFFSET);

        this->email = util::copy::eMail(details, util::constants::MAIL_OFFSET);

        this->fax = util::copy::number(details, util::constants::FAX_OFFSET);

        this->home = util::copy::number(details, util::constants::HOME_OFFSET);

        this->org = util::copy::company(details, util::constants::ORG_OFFSET);

        this->work = util::copy::number(details, util::constants::WORK_OFFSET);

        this->deleted = util::copy::deleted(main);
    }

    static void write(const contact &contact, std::ostream *out){
        *out << "NAME OF CONTACT: " << contact.name
             << "     TELEPHONE OF CONTACT: " << contact.tel
             << " HOME PHONE NUMBER: " << contact.home
             << " WORK PHONE NUMBER: " << contact.work
             << " FAX  PHONE NUMBER: " << contact.fax
             << " ORG PHONE NUMBER:  " << contact.org
             << " EMAIL:" << contact.email
             << " DELETED: " << contact.deleted << std::endl;
    }
};


#endif