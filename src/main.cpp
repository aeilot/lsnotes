#include <getopt.h>

#include <cstdio>
#include <cstring>
#include <iostream>

#include <cstdlib>

#include "fmt/core.h"

using namespace std;

static const struct option long_options[] = {{"help", no_argument, NULL, 'h'},
                                             {"edit", no_argument, NULL, 'e'},
                                             {"view", no_argument, NULL, 'v'},
                                             {"config", no_argument, NULL, 'c'},
                                             {0, 0, 0, 0}};

struct LSConfig {
    int addTitle;
    int addBottom;
} instance;

void help() {
    cout << "lsnotes" << endl;
    cout << "lsnotes [--help|-h] [--edit|-e] [--view|-v] [--config|-c]" << endl;
    cout << "The program will automatically do \"view\" operation if without "
            "arguments. Skip if there's no .lsnotes file"
         << endl
         << endl;
    cout << "For more: Check https://github.com/aeilot/lsnotes" << endl;
    cout << "------------" << endl << "License: MIT | Made by @aeilot" << endl;
}

void view() {
    FILE* note = NULL;
    note = fopen(".lsnotes", "r");
    if (note != NULL) {
        if (instance.addTitle) cout << "LSNOTES:" << endl;
        while (!feof(note)) {
            int c;
            if ((c = fgetc(note)) != EOF) cout << char(c);
        }
        if (instance.addBottom) cout << "---" << endl;
    }
    fclose(note);
}

void edit() {
    const char* editor = getenv("EDITOR");
    if (editor == NULL) {
        cout << "Default Editor Not Set." << endl;
#if defined(_WIN32)
        cout << "Using Notepad.exe" << endl;
        system("notepad.exe .lsnotes");
#else
        cout << "Using vi" << endl;
        system("vi .lsnotes");
#endif
        cout << "You can set $EDITOR to PATH" << endl;
    } else {
        cout << "Editing the .lsnotes file with the default editor" << endl;
        system("$EDITOR .lsnotes");
    }
}

void readConfig() {
    FILE* config = NULL;
    char* home = getenv("HOME");
    char* path = new char[strlen(home) + 12];
    strcpy(path, home);
    strcat(path, "/.lsnotesrc");
    config = fopen(path, "r");
    if (config != NULL) {
        fscanf(config, "%d%d", &instance.addTitle, &instance.addBottom);
    } else {
        instance.addBottom = 1;
        instance.addTitle = 0;
    }
    fclose(config);
}

void config() {
    FILE* configtmp = NULL;
    char* home = getenv("HOME");
    char* pathtmp = new char[strlen(home) + 16];
    strcpy(pathtmp, home);
    strcat(pathtmp, "/.lsnotesrc.tmp");
    char* path = new char[strlen(home) + 12];
    strcpy(path, home);
    strcat(path, "/.lsnotesrc");

    configtmp = fopen(pathtmp, "w+");
    cout << "CONFIGURATION (0: no, 1: yes)" << endl;
    cout << "Add a title (Currently " << instance.addTitle << "): ";
    int t;
    cin >> t;
    instance.addTitle = t;
    cout << "Add a bottom divider (Currently " << instance.addBottom << "): ";
    cin >> t;
    instance.addBottom = t;
    fprintf(configtmp, "%d %d", instance.addTitle, instance.addBottom);
    fclose(configtmp);
    remove(path);
    rename(pathtmp, path);
    cout << "Changes saved" << endl;
}

int main(int argc, char* argv[]) {
    // Init
    int opt = 0;
    int option_index = 0;
    readConfig();
    // Handle options
    while (1) {
        opt = getopt_long(argc, argv, "hevc", long_options, &option_index);
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
            case 'c':
                config();
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