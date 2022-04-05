#include <getopt.h>

#include <cstdio>
#include <iostream>

using namespace std;

static const struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {"edit", optional_argument, NULL, 'e'},
    {"view", optional_argument, NULL, 'v'},
    {0, 0, 0, 0}};

void help() {
    cout << "lsnotes" << endl;
    cout
        << "lsnotes [--help|-h] [--edit|-e (directory)] [--view|-v (directory)]"
        << endl;
    cout << "The program will automatically do \"view\" operation if without "
            "arguments. Skip if there's no .lsnotes file"
         << endl
         << endl;
    cout << "For more: Check https://github.com/aeilot/lsnotes" << endl;
    cout << "------------" << endl << "License: MIT | Made by @aeilot" << endl;
}

void view() {}

void edit() {}

int main(int argc, char* argv[]) {
    int opt = 0;
    int option_index = 0;
    while (1) {
        opt = getopt_long(argc, argv, "he:v:", long_options, &option_index);
        if (opt == -1) break;
        switch (opt) {
            case 'h':
                help();
                break;
            case 'v':
            default:
                break;
        }
    }
    return 0;
}