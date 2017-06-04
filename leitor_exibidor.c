#include "argument_checks.h"

int main(int argc, char* argv[]) {
    checkArgumentAmount(argc);
    checkFileExtension(argv[1]);
    readClassFile(argv[1]);
    return 0;
}
