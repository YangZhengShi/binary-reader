#include "contact.h"

template<size_t N,typename T> contact<N,T>::contact(const std::array<char, N> &main, const std::array<char, N> &details) {

    this->tel      = copy::number(main,constants::TEL_OFFSET);

    this->name     = copy::name(main,constants::NAME_IN_CONTACTS_OFFSET);

    this->email    =copy::name(details,constants::MAIL_OFFSET);

    this->fax      =copy::number(details,constants::FAX_OFFSET);

    this->home     =copy::number(details,constants::HOME_OFFSET);

    this->org      =copy::name(details,constants::ORG_OFFSET);

    this->work     =copy::number(details,constants::WORK_OFFSET);
}

template<size_t N,typename T>contact<N,T>::contact(const std::string &fileName) {

    extractRecords(this->contacts,contact::getFile<N>(fileName));

    writeToTXT(this->contacts,fileName);
}

template<size_t N, typename T> void contact<N, T>::write(const T &contact, std::ostream *out) {
    *out <<"NAME OF CONTACT: " << contact.name
         << " HOME PHONE NUMBER: " << contact.home
         << " WORK PHONE NUMBER: " << contact.work
         << " FAX  PHONE NUMBER: " << contact.fax
         << " ORG PHONE NUMBER:  " << contact.org
         << " EMAIL:" << contact.email << " DELETED? " <<std::endl;

}
