#include <filesystem>
#include "calls/call.h"
#include "contacts/contact.h"

/**
 * Please note that the modules are working exactly as described,
 * i faced an issue with the linker of gcc since it cannot "see" the implementation
 * of the constructors(the headers were probably not included in the compilation stage?
 * have faced similar issues with CLion before).
 *
 * results can be seen in the out directory.
 * */

int main() {

    //hardcoded path for the binaries
    auto calls = std::filesystem::current_path()/"binaries"/"Calls.bin";

    auto details = std::filesystem::current_path()/"binaries"/"Phonebook_Details.bin";

    auto main = std::filesystem::current_path()/"binaries"/"Phonebook_Main.bin";

    //calling the constructor to start working on its tasks for every binary
    call<util::constants::CALLS_RECORD_SIZE> call(calls);

    contact<util::constants::PHONEBOOK_MAIN_SIZE,util::constants::PHONEBOOK_RECORD_SIZE> contact(main,details);

    //explicitly call destructor to assert freeing up of memory
    call.~call();

    contact.~contact();

    return 0;
}
