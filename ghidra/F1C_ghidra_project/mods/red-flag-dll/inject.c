/*
 * inject.exe — injects red_flag.dll into F1 Challenge Online.exe
 *
 * Usage:  inject.exe red_flag.dll
 *
 * Build (MinGW 32-bit):
 *   i686-w64-mingw32-gcc -o inject.exe inject.c -lkernel32 -m32
 *
 * Build (MSVC 32-bit):
 *   cl /Fe:inject.exe inject.c
 *
 * Run the game first, then run inject.exe. The DLL will be loaded into
 * the game process and the hotkey thread starts immediately.
 */

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

#define TARGET_PROCESS "F1 Challenge Online.exe"

static DWORD find_pid(const char *name)
{
    DWORD pid = 0;
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) return 0;

    PROCESSENTRY32 pe = { sizeof(pe) };
    if (Process32First(snap, &pe)) {
        do {
            if (_stricmp(pe.szExeFile, name) == 0) {
                pid = pe.th32ProcessID;
                break;
            }
        } while (Process32Next(snap, &pe));
    }
    CloseHandle(snap);
    return pid;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: inject.exe <path_to_dll>\n");
        return 1;
    }

    /* Resolve absolute path to DLL */
    char dll_path[MAX_PATH];
    if (!GetFullPathNameA(argv[1], MAX_PATH, dll_path, NULL)) {
        fprintf(stderr, "Error: cannot resolve DLL path\n");
        return 1;
    }

    DWORD pid = find_pid(TARGET_PROCESS);
    if (!pid) {
        fprintf(stderr, "Error: '%s' not found. Start the game first.\n", TARGET_PROCESS);
        return 1;
    }
    printf("Found %s  PID=%lu\n", TARGET_PROCESS, pid);

    /* Open target process with required rights */
    HANDLE proc = OpenProcess(
        PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE,
        FALSE, pid);
    if (!proc) {
        fprintf(stderr, "Error: OpenProcess failed (%lu)\n", GetLastError());
        return 1;
    }

    /* Allocate space for DLL path in target process */
    SIZE_T path_len = strlen(dll_path) + 1;
    LPVOID remote_str = VirtualAllocEx(proc, NULL, path_len,
                                       MEM_COMMIT | MEM_RESERVE,
                                       PAGE_READWRITE);
    if (!remote_str) {
        fprintf(stderr, "Error: VirtualAllocEx failed (%lu)\n", GetLastError());
        CloseHandle(proc);
        return 1;
    }

    if (!WriteProcessMemory(proc, remote_str, dll_path, path_len, NULL)) {
        fprintf(stderr, "Error: WriteProcessMemory failed (%lu)\n", GetLastError());
        VirtualFreeEx(proc, remote_str, 0, MEM_RELEASE);
        CloseHandle(proc);
        return 1;
    }

    /* Start remote thread at LoadLibraryA(dll_path) */
    LPTHREAD_START_ROUTINE load_fn =
        (LPTHREAD_START_ROUTINE)GetProcAddress(
            GetModuleHandleA("kernel32.dll"), "LoadLibraryA");

    HANDLE thread = CreateRemoteThread(proc, NULL, 0,
                                       load_fn, remote_str, 0, NULL);
    if (!thread) {
        fprintf(stderr, "Error: CreateRemoteThread failed (%lu)\n", GetLastError());
        VirtualFreeEx(proc, remote_str, 0, MEM_RELEASE);
        CloseHandle(proc);
        return 1;
    }

    WaitForSingleObject(thread, 5000);

    DWORD exit_code = 0;
    GetExitCodeThread(thread, &exit_code);
    if (exit_code == 0) {
        fprintf(stderr, "Error: LoadLibrary returned NULL — check DLL path and bitness\n");
    } else {
        printf("Injected OK. Press M in-game to toggle red flag.\n");
    }

    CloseHandle(thread);
    VirtualFreeEx(proc, remote_str, 0, MEM_RELEASE);
    CloseHandle(proc);

    printf("\nPress Enter to close...\n");
    getchar();
    return exit_code ? 0 : 1;
}
