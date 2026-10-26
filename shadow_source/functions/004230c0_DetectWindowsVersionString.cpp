// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004230C0
// Canonical corpus name: sub_4230C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4230C0_004230c0.c

void UnknownObject::DetectWindowsVersionString()
{
    // Detects the Windows OS version via GetVersionExA (156-byte OSVERSIONINFOA, retrying with 148 bytes) and selects a platform-name string into a local buffer: Win32s, Windows 9x family (95/98/Me by major/minor), or Windows NT family (NT, 2000, XP by major/minor). On success the selected string is copied into the output argument a1 when non-null and its length returned. Called by ConfigIniParser (00421CD0).
    // LOOP: Copy the default platform string aUnknown into the local v13 buffer via a do-while loop terminated on the null terminator. [global:0x005C307C, source:raw]
    // CALCULATION: Zero the OSVERSIONINFOA structure with memset, then set dwOSVersionInfoSize (first dword) to 156. [source:raw]
    // CALL: Call GetVersionExA with the 156-byte structure; on failure retry after setting dwOSVersionInfoSize to 148. [global:0x0059E198, source:raw]
    // GUARD: If both GetVersionExA attempts fail, skip all string selection and return the failed result (0). [global:0x0059E198, source:raw]
    // GUARD: If dwPlatformId (offset +16) is 0 (Win32s), copy byte_5C3044 into v13 and jump to the copy-out path. [global:0x005C3044, source:raw]
    // GUARD: If dwPlatformId (offset +16) is 1 (Win32 Windows 9x): with dwMajorVersion (offset +4) >= 4 and dwMinorVersion (offset +8) >= 0x5A copy byte_5C3070 (Me); else if major > 4 or minor != 0 copy byte_5C3058 (98); else copy byte_5C3064 (95). [global:0x005C3070, global:0x005C3058, global:0x005C3064, source:raw]
    // GUARD: If dwPlatformId (offset +16) is 2 (Win32 NT): with dwMajorVersion (offset +4) <= 4 copy aWindowsNt; otherwise with major >= 5 copy aWindowsXp when dwMinorVersion (offset +8) is non-zero, else aWindows2000. [global:0x005C2D90, global:0x005C2D9C, global:0x005C2D80, source:raw]
    // ASSIGNMENT: Copy-out path: when output argument a1 is non-null, strcpy(a1, v13) writes the selected platform string to the caller's buffer. [source:raw]
    // RETURN: Return the string-length result (loop index of the last copied string), or the leftover value for platforms outside the handled range. ConfigIniParser (00421CD0) is the caller. [function:0x004230C0, caller:0x00421CD0, source:raw]

    // Conservative worker pseudocode:
    //   int DetectWindowsVersionString(char* out) {
    //     char buf[256];
    //     int i = 0;
    //     do { buf[i] = aUnknown[i]; } while (buf[i++] != 0);
    //     OSVERSIONINFOA vi; memset(&vi, 0, sizeof(vi)); vi.dwOSVersionInfoSize = 156;
    //     if (!GetVersionExA(&vi)) { vi.dwOSVersionInfoSize = 148; if (!GetVersionExA(&vi)) return result; }
    //     int result = 0;
    //     if (vi.dwPlatformId == 0) { do { buf[result] = byte_5C3044[result]; } while (buf[result++] != 0); }
    //     else if (vi.dwPlatformId == 1) {
    //       if (vi.dwMajorVersion >= 4 && vi.dwMinorVersion >= 0x5A) copy(byte_5C3070);
    //       else if (vi.dwMajorVersion > 4 || vi.dwMinorVersion != 0) copy(byte_5C3058);
    //       else copy(byte_5C3064);
    //     } else if (vi.dwPlatformId == 2) {
    //       if (vi.dwMajorVersion <= 4) copy(aWindowsNt);
    //       else if (vi.dwMajorVersion >= 5) { if (vi.dwMinorVersion) copy(aWindowsXp); else copy(aWindows2000); }
    //     }
    //     if (out) strcpy(out, buf);
    //     return result;
    //   }
    // UNRESOLVED: The four ff-prefixed globals (0xFF00000000005370..0xFF00000000005374) are decompiler mis-analysis artifacts of invalid pointer arithmetic, not real data accesses.
    // UNRESOLVED: Return value for dwPlatformId values outside 0..2 is (dwPlatformId - 2), a decompiler artifact rather than an intended length.
    // UNRESOLVED: Actual string content of the byte globals (aUnknown, byte_5C3044/58/64/70, aWindowsNt/2000/Xp) is not visible in this packet.
}
