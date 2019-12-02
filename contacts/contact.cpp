#include "contact.h"

template<size_t N,size_t M> contact<N,M>::contact(const std::array<char, N> &main, const std::array<char, M> &details) {

    this->tel      = util::copy::number(main,util::constants::TEL_OFFSET);

    this->name     = util::copy::name(main,util::constants::NAME_IN_CONTACTS_OFFSET);

    this->email    =util::copy::eMail(details,util::constants::MAIL_OFFSET);

    this->fax      =util::copy::number(details,util::constants::FAX_OFFSET);

    this->home     =util::copy::number(details,util::constants::HOME_OFFSET);

    this->org      =util::copy::company(details,util::constants::ORG_OFFSET);

    this->work     =util::copy::number(details,util::constants::WORK_OFFSET);

    this->deleted  =util::copy::deleted(main);
}

template<size_t N,size_t M> contact<N,M>::contact(const contact &main,const contact &details){

    this->name= main.name;

    this->tel=main.tel;

    this->work= details.work;

    this->email=details.email;

    this->fax = details.fax;

    this->org = details.org;

    this->work = details.work;

    this->deleted = main.deleted;
}

template<size_t N,size_t M> contact<N,M>::contact(const std::string &main, const std::string &details) {

    bin<N,contact>::extractRecords(this->main,bin<N,contact>::getFile<N>(main));

    bin<M,contact>::extractRecords(this->details,bin<M,contact>::getFile<M>(details));

    for (size_t i =0; i<this->main.size(); i++) this->final.emplace_back(contact(this->main.at(i),this->details.at(i)));

    bin<N,contact>::writeToTXT(this->final,main);
}

template<size_t N,size_t M> void contact<N,M>::write(const contact &contact, std::ostream *out) {
    *out <<"NAME OF CONTACT: " << contact.name
         << " HOME PHONE NUMBER: " << contact.home
         << " WORK PHONE NUMBER: " << contact.work
         << " FAX  PHONE NUMBER: " << contact.fax
         << " ORG PHONE NUMBER:  " << contact.org
         << " EMAIL:" << contact.email
         << " DELETED: " << contact.deleted <<std::endl;
}
