#include    "misc_helper.h"

#include <windows.h>
#include <stdio.h>

void copy_to_clipboard(const char *str) {
    printf("Copying to clipboard...\n");
    const size_t len = strlen(str) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), str, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    if (GetLastError() != 0) {
        printf("Failed to open clipboard\n");
        exit(EXIT_FAILURE);
    }

    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    if (GetLastError() != 0) {
        printf("Failed to copy to clipboard\n");
        exit(EXIT_FAILURE);
    }

    CloseClipboard();
}

int check(char *str, char *expected) {
    if (strcmp(str, expected) != 0) {
        printf("Expected: %s\n", expected);
        printf("Got: %s\n", str);
        printf("Failed\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Passed\n");
        return 0;
    }
}