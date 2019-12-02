#include <filesystem>
#include "calls/call.h"
#include "contacts/contact.h"

//run the executable as follows: ./msab pwd

#define PRINT(X) std::cout<<(X) <<std::endl;

int main(int argc, char **argv) {

    PRINT("MANDATORY ASSIGNMENT FOR MSAB BY KONSTANTINOS XYDEROS")
    PRINT("READING BINARIES FROM: ")

    PRINT("Started parsing Calls...")
    call<util::constants::CALLS_RECORD_SIZE> call(std::string(argv[1]).append(util::constants::CALLS));
    PRINT("Calls.txt saved on the same directory as the original binary")

    PRINT("Started parsing Contacts")
    contact<util::constants::PHONEBOOK_MAIN_SIZE,util::constants::PHONEBOOK_RECORD_SIZE>
            contact(std::string(argv[1]).append(util::constants::MAIN),std::string(argv[1]).append(util::constants::DETAILS));
    PRINT("Phonebook_Main.txt saved on the same directory as the original binary")

    PRINT("THANK YOU FOR YOUR TIME!!!")

    return 0;
}
