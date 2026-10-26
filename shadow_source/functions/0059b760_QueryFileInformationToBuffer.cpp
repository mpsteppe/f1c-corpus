// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B760
// Canonical corpus name: sub_59B760
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59B760_0059b760.c

void UnknownObject::QueryFileInformationToBuffer()
{
    // Queries an open file slot (index a1, guarded by the open-file count uNumber and the slot in-use flag) and fills a caller result buffer with the file's type, size and timestamp information. Disk files (GetFileType 1) take the full GetFileInformationByHandle path with per-time FILETIME-to-systemtime conversion and a compressed datetime via sub_591EDF; character devices (type 2) and pipes (type 3) get a minimal header plus an available-data count (PeekNamedPipe for pipes). Failures set the TLS error to 9 via TLSOffsetGetter, map GetLastError through ErrorIDLookupTable, and return -1.
    // GUARD: Validate slot a1: require a1 below the open-file count uNumber and the slot entry's in-use flag bit (byte at +4 of each 36-byte slot entry) set; otherwise fail immediately. [global:0x008D4A20, source:raw]
    // CALL: Enter the slot's critical section with CriticalSectionEnterWithLazyInit(a1) before any file query. [callee:0x00595A61]
    // CALL: Query the slot handle's type with GetFileType, then clear the high byte of the returned type flags. [global:0x0059E0F8]
    // GUARD: Branch on the file type: 1 takes the disk-file path; 2 (character device) and 3 (pipe) initialize the character-device buffer; 0 and unknown types take the failure path. [source:raw]
    // ASSIGNMENT: For a character device or pipe, write the result buffer header: block size word at +6 (0x2000 for a character device, 4096 for a pipe), flags word +8 set to 1, slot id stored at +0 and +16, zero words at +4, +12 and +10, and zero dwords at +24, +28 and +32. [source:raw]
    // CALCULATION: Set the available-data dword at +20: forced to 0 for character devices, else the value from PeekNamedPipe (also 0 when PeekNamedPipe fails). [global:0x0059E0C0]
    // CALL: Disk-file path: retrieve attributes, sizes and timestamps with GetFileInformationByHandle into a local BY_HANDLE_FILE_INFORMATION; failure goes to the error path. [global:0x0059E0BC]
    // CALCULATION: Encode the attribute/permission bits into the +6 word of the buffer: OR 0x124 when the read-only attribute is set, otherwise OR 0x1B6. [source:raw]
    // CALL: Convert the last-write FILETIME to local time with FileTimeToLocalFileTime and then to system time with FileTimeToSystemTime; failure aborts to the error path. [global:0x0059E0B8, global:0x0059E0AC]
    // CALL: Pack the last-write date/time into the compressed form with sub_591EDF(year, month, day, hour, minute, second, -1) and store it at +28 of the buffer. [callee:0x00591EDF]
    // CALCULATION: Convert the last-access FILETIME when non-zero and store it at +24; when the creation time is zero, reuse the last-write value for the creation slot and mark the +7 high bit. [global:0x0059E0B8, global:0x0059E0AC, callee:0x00591EDF]
    // ASSIGNMENT: Complete the disk entry: copy the file size low dword into +20, set +16 and +0 to 0, write the creation value at +32 and OR 0x80 into the byte at +7 when creation equals last-write. [source:raw]
    // CALL: Error path: read GetLastError and map it through ErrorIDLookupTable before failing. [global:0x0059E188, callee:0x0058AF5C]
    // ASSIGNMENT: Write the TLS error value 9 via TLSOffsetGetter and return -1 when the slot is invalid or a query step fails. [callee:0x0058AFCF, source:raw]
    // CALL: Leave the slot's critical section with FileCriticalSectionLeave(a1) on every exit from the queried path. [callee:0x00595AC0]

    // Conservative worker pseudocode:
    //   int QueryFileInformationToBuffer(int slot, char *out) {
    //     if (slot >= uNumber || ((unsigned char)open_file_array[slot] != 0 && (open_file_array[slot].flags & 1) == 0)) {
    //       *(int *)TLSOffsetGetter() = 9;
    //       return -1;
    //     }
    //     CriticalSectionEnterWithLazyInit(slot);
    //     HANDLE h = *(HANDLE *)&open_file_array[slot];
    //     DWORD type = GetFileType(h);
    //     type &= ~((DWORD)0x80u << 8);
    //     if (type == 1) {
    //       *(WORD *)(out + 6) = 0; *(WORD *)(out + 12) = 0; *(WORD *)(out + 10) = 0;
    //       *(WORD *)(out + 4) = 0; *(WORD *)(out + 8) = 1;
    //       BY_HANDLE_FILE_INFORMATION fi;
    //       if (!GetFileInformationByHandle(h, &fi)) { ErrorIDLookupTable(GetLastError()); FileCriticalSectionLeave(slot); return -1; }
    //       *(WORD *)(out + 6) |= (fi.dwFileAttributes & 1) ? 0x124 : 0x1B6;
    //       FILETIME local; SYSTEMTIME st;
    //       if (!FileTimeToLocalFileTime(&fi.ftLastWriteTime, &local) || !FileTimeToSystemTime(&local, &st)) {
    //         *(int *)TLSOffsetGetter() = 9; FileCriticalSectionLeave(slot); return -1;
    //       }
    //       *(int *)(out + 28) = sub_591EDF(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, -1);
    //       int created = 0;
    //       if (fi.ftLastAccessTime.dwLowDateTime || fi.ftLastAccessTime.dwHighDateTime) {
    //         if (FileTimeToLocalFileTime(&fi.ftLastAccessTime, &local) && FileTimeToSystemTime(&local, &st))
    //           *(int *)(out + 24) = sub_591EDF(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, -1);
    //       }
    //       if (fi.ftCreationTime.dwLowDateTime == 0 && fi.ftCreationTime.dwHighDateTime == 0) {
    //         created = *(int *)(out + 28);
    //       } else if (FileTimeToLocalFileTime(&fi.ftCreationTime, &local) && FileTimeToSystemTime(&local, &st)) {
    //         created = sub_591EDF(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, -1);
    //       }
    //       *(BYTE *)(out + 7) |= 0x80; *(int *)(out + 32) = created;
    //       *(int *)out = 0; *(int *)(out + 20) = (int)fi.nFileSizeLow; *(int *)(out + 16) = 0;
    //     } else {
    //       int avail;
    //       switch (type) {
    //         case 2:  *(WORD *)(out + 6) = 0x2000; break;
    //         case 3:  *(WORD *)(out + 6) = 4096; break;
    //         default: ErrorIDLookupTable(GetLastError()); *(int *)TLSOffsetGetter() = 9; FileCriticalSectionLeave(slot); return -1;
    //       }
    //       *(WORD *)(out + 8) = 1; *(int *)out = slot; *(int *)(out + 16) = slot;
    //       *(WORD *)(out + 4) = 0; *(WORD *)(out + 12) = 0; *(WORD *)(out + 10) = 0;
    //       *(int *)(out + 32) = 0; *(int *)(out + 28) = 0; *(int *)(out + 24) = 0;
    //       if (type == 2) { *(int *)(out + 20) = 0; }
    //       else if (PeekNamedPipe(h, 0, 0, 0, (LPDWORD)&avail, 0)) { *(int *)(out + 20) = avail; }
    //       else { *(int *)(out + 20) = 0; }
    //     }
    //     FileCriticalSectionLeave(slot);
    //     return 0;
    //   }
    // UNRESOLVED: The array base dword_8D4920 for the 36-byte open-file slot entries has no packet global reference; the slot-array indexing in the description is derived from the decompiled expression a1 >> 5 / a1 & 31.
    // UNRESOLVED: The exact meaning of the buffer word at +6 differs by file type (block size for devices, attribute/permission bits for disk files); the disk-file attribute masks 0x124/0x1B6 are taken from the raw source.
    // UNRESOLVED: The TLS value 9 written on failure is a known error id but its message table entry is not resolved here.
}
