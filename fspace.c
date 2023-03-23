#include <stdio.h>
#include <sys/statvfs.h>

int main() {
    struct statvfs fs_info;
    if (statvfs("/", &fs_info) == -1) {
        perror("Error getting filesystem information");
        return 1;
    }
    printf("------------------\n");
    long long bytes_left = (long long)fs_info.f_bsize * fs_info.f_bavail;
    printf("|\x1b[36m%lld bytes\x1b[0m|\n", bytes_left);
    
    double kilobytes_left = (double)bytes_left / 1024;
    printf("|\x1b[33m%.2f KB\x1b[0m   |\n", kilobytes_left);
    
    double megabytes_left = kilobytes_left / 1024;
    printf("|\x1b[32m%.2f MB\x1b[0m      |\n", megabytes_left);
    
    double gigabytes_left = megabytes_left / 1024;
    printf("|\x1b[31m%.2f GB\x1b[0m         |\n", gigabytes_left);
    printf("------------------\n\n");
    
    return 0;
}

