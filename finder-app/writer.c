#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    openlog("writer", 0, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR,
                "Wrong number of arguments\n"
                "Total number of arguments should be 2:\n"
                "  1) Full path to a file (including filename)\n"
                "  2) Text string which will be written within this file\n");
        closelog();
        return 1;
    }

    char *filepath = argv[1];
    char *text = argv[2];

    syslog(LOG_DEBUG, "Writing %s to %s", text, filepath);

    int fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        syslog(LOG_ERR, "Error: Failed to open file %s\n", filepath);
        closelog();
        return 1;
    }

    ssize_t bytes_written = write(fd, text, strlen(text));
    if (bytes_written == -1) {
        syslog(LOG_ERR, "Error: Failed to write into the file\n");
        close(fd);
        closelog();
        return 1;
    }

    if (close(fd) == -1) {
        syslog(LOG_ERR, "Error: Failed to close the file\n");
        closelog();
        return 1;
    }

    closelog();
    return 0;
}

