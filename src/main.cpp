#include <getopt.h>

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

static const struct option long_options[] = {{"help", no_argument, NULL, 'h'},
                                             {"edit", no_argument, NULL, 'e'},
                                             {"view", no_argument, NULL, 'v'},
                                             {0, 0, 0, 0}};

void help() {
    cout << "lsnotes" << endl;
    cout << "lsnotes [--help|-h] [--edit|-e] [--view|-v]" << endl;
    cout << "The program will automatically do \"view\" operation if without "
            "arguments. Skip if there's no .lsnotes file"
         << endl
         << endl;
    cout << "For more: Check https://github.com/aeilot/lsnotes" << endl;
    cout << "------------" << endl << "License: MIT | Made by @aeilot" << endl;
}

void view() {
    FILE* note = NULL;
    char cwd[1000];
    getcwd(cwd, sizeof(cwd));
    char* t = new char[strlen(cwd) + 9 + 1];
    strcpy(t, cwd);
    strcat(t, "/.lsnotes");
    note = fopen(t, "r");
    if (note != NULL) {
        while (!feof(note)) {
            int c;
            if ((c = fgetc(note)) != EOF) cout << char(c);
        }
        cout << "---" << endl;
    }
    fclose(note);
}

void edit() {
    cout << "Editing the .lsnotes file with the default editor" << endl;
    system("$EDITOR .lsnotes");
}

int main(int argc, char* argv[]) {
    // Init
    int opt = 0;
    int option_index = 0;
    // Handle options
    while (1) {
        opt = getopt_long(argc, argv, "hev", long_options, &option_index);
        if (opt == -1) break;
        switch (opt) {
            case 'h':
                help();
                exit(EXIT_SUCCESS);
                break;
            case 'e':
                edit();
                exit(EXIT_SUCCESS);
                break;
            case 'v':
                view();
                exit(EXIT_SUCCESS);
                break;
            default:
                cout << "Try lsnotes --help for more information" << endl;
                exit(EXIT_FAILURE);
        }
    }
    // If no option, view the file
    view();
    return 0;
}