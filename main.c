#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "permissions/permissions.h"

typedef enum { False, True } boolean;
typedef struct {
        boolean remove_defaults;
        boolean include_all_users;
} options;

int main(int argc, char * argv[])
{
        if (argc <= 1) {
                printf("Please enter additional options. Enter \"-h\" for help.\n");
                return 0;
        }

        for (int i = 1; i < argc; ++i) {
                // Options
                options myoptions = {0, 0};

                if (strcmp(argv[i], "-d") == 0) {
                        myoptions.remove_defaults = 1;
                }
                else if (strcmp(argv[i], "-a") == 0) {
                        myoptions.include_all_users = 1;
                }

                // Gerneral commands
                // List packages
                else if (strcmp(argv[i], "-p") == 0) {
                        system("adb shell pm list packages");
                        return 0;
                }

                // List users
                else if (strcmp(argv[i], "-u") == 0) {
                        system("adb shell pm list users");
                        return 0;
                }

                // Search
                else if (strcmp(argv[i], "--search") == 0) {
                        if (i == argc) {
                                printf("Please enter search term after \"-s\".");
                                return 0;
                        }
                        char command[100];
                        char search_term[50];
                        strncpy(search_term, argv[i + 1], 50);
                        snprintf(command, 100, "adb shell pm list packages | grep \"%s\"", search_term);
                        system(command);
                        return 0;
                }

                else if (strcmp(argv[i], "--permissions") == 0) {
                        permissions();
                        return 0;
                }

                //help page
                else if (strcmp(argv[i], "-h") == 0) {
                        printf("Samsung debloater v0.1\n");
                        printf("\n");
                        printf("Debloater options:\n");
                        printf("%-30s%s\n", "-d", "Remove default apps");
                        printf("%-30s%s\n", "-a", "Debloat all users");
                        printf("\n");
                        printf("General commands:\n");
                        printf("%-30s%s\n", "-p", "List installed packages");
                        printf("%-30s%s\n", "-u", "List users");
                        printf("%-30s%s\n", "-h", "Print help menu");
                        printf("%-30s%s\n", "--search SEARCH-TERM", "Search installed packages");
                        printf("%-30s%s\n", "--permissions", "Open permissions utility");
                        return 0;
                }
                else {
                        printf("Unknown command. Please enter \"-h\" for help.\n");
                        return 0;
                }
        }
}