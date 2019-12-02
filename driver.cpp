#include <filesystem>
#include "calls/call.h"
#include "contacts/contact.h"

int main() {

    auto calls = std::filesystem::current_path()/"binaries"/"Calls.bin";

    auto details = std::filesystem::current_path()/"binaries"/"Phonebook_Details.bin";

    auto main = std::filesystem::current_path()/"binaries"/"Phonebook_Main.bin";


    call<util::constants::CALLS_RECORD_SIZE> call(calls);

    //explicitly call destructor to assert freeing up of memory
    call.~call();

    contact<util::constants::PHONEBOOK_MAIN_SIZE,util::constants::PHONEBOOK_RECORD_SIZE> contact(main,details);

    contact.~contact();

    return 0;

}
