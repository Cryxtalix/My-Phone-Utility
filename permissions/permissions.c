#include "permissions.h"

int permissions()
{
    typedef enum { False, True } boolean;
    boolean remove_permissions = 0,
            secure_settings = 0,
            volume_longpress = 0,
            read_logs = 0;

    char remove_permissions;
    char secure_settings;
    char volume_longpress;
    char read_logs;

    system("clear -x");
    printf("Tasker permissions utility\n");
    printf("Do you want to add or remove permissions?\n\n");
    
    
}