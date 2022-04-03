#include <getopt.h>

#include <cstdio>
#include <iostream>

using namespace std;

static const struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {"edit", optional_argument, NULL, 'e'},
    {"view", optional_argument, NULL, 'v'}};

void help() {}

void view() {}

void edit() {}

int main(int argc, char* argv[]) {
    int opt = 0;
    int option_index = 0;
    while ((opt = getopt_long(argc, argv, "h:e:v:", long_options,
                              &option_index) != EOF)) {
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