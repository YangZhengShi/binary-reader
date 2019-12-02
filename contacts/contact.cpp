#include "contact.h"

template<size_t N> contact<N>::contact(const std::array<char, N> &main, const std::array<char, N> &details) {

    this->tel      = util::copy::number(main,util::constants::TEL_OFFSET);

    this->name     = util::copy::name(main,util::constants::NAME_IN_CONTACTS_OFFSET);

    this->email    =util::copy::name(details,util::constants::MAIL_OFFSET);

    this->fax      =util::copy::number(details,util::constants::FAX_OFFSET);

    this->home     =util::copy::number(details,util::constants::HOME_OFFSET);

    this->org      =util::copy::name(details,util::constants::ORG_OFFSET);

    this->work     =util::copy::number(details,util::constants::WORK_OFFSET);
}

template<size_t N> contact<N>::contact(const std::string &main, const std::string &details) {

    bin<N,contact>::extractRecords(this->contacts,bin<N,contact>::getFile<N>(main));

    bin<N,contact>::writeToTXT(this->contacts,main);
}

template<size_t N> void contact<N>::write(const contact &contact, std::ostream *out) {
    *out <<"NAME OF CONTACT: " << contact.name
         << " HOME PHONE NUMBER: " << contact.home
         << " WORK PHONE NUMBER: " << contact.work
         << " FAX  PHONE NUMBER: " << contact.fax
         << " ORG PHONE NUMBER:  " << contact.org
         << " EMAIL:" << contact.email << " DELETED? " <<std::endl;

}
