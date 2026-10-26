// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595AF9
// Canonical corpus name: sub_595AF9
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_595AF9_00595af9.c

void UnknownObject::CRTFileOpenCreate()
{
    // CRT-style file open/create wrapper around CreateFileA. Parses the mode flag field a2 into desired access, share mode, creation disposition and flags-and-attributes, builds a SECURITY_ATTRIBUTES struct, allocates a file-descriptor slot via sub_595801, opens the file, tags the descriptor with its file type (disk/pipe/console), optionally reads the first byte to detect and rewind the 0x1A EOF marker, and returns the descriptor index or -1 with a TLS error code on any failure.
    // ASSIGNMENT: Initialize SECURITY_ATTRIBUTES with nLength 12 and a null security descriptor, and set the handle-inherit flag from flag bit 0x80 of a2 (inheritable when unset). [source:raw]
    // CALCULATION: Compute the flags-and-attributes byte v20: set bit 0x80 when flag bit 0x8000 is unset and either bit 0x4000 is set or the CRT open flag dword_8D41FC does not equal 0x8000. [source:raw, global:0x008D41FC]
    // CALCULATION: Map the low two bits of a2 to dwDesiredAccess: 0 to 0x80000000, 1 to 0x40000000, 2 to the read/write combination (-1073741824); any other low-bit combination falls through to the error path. [source:raw]
    // GUARD: Map the share-mode argument Buffer to dwShareMode (16/32/48/64 to 0/1/2/3); an out-of-range value jumps to the error path. [source:raw]
    // CALL: Error path: store error 22 into the TLS error slot via TLSOffsetGetter, clear the extended slot via TLSOffsetGetter_afd8, and return -1. [callee:0x0058AFCF, callee:0x0058AFD8, source:raw]
    // CALCULATION: Map bits 0x700 of a2 to dwCreationDisposition: 0/0x400 to OPEN_EXISTING(3), 0x100 to OPEN_ALWAYS(4), 0x200/0x600 to CREATE_NEW(5), 0x500/0x700 to TRUNCATE_EXISTING(1), 0x300 to CREATE_ALWAYS(2); unknown combinations hit the error path. [source:raw]
    // CALCULATION: Assemble the flags-and-attributes value v6 (base 128): flag 0x100 forces 1 when attribute byte a4 lacks bit 0x80 relative to dword_8D3E70, flag 0x40 adds 0x4000000 and sets an access byte, flag 0x1000 adds 0x100, flag 0x20 adds 0x8000000, flag 0x10 adds 0x10000000. [source:raw, global:0x008D3E70]
    // CALL: Allocate a file-descriptor slot via sub_595801; on -1 store error 24 into the TLS error slot via TLSOffsetGetter, clear the extended slot via TLSOffsetGetter_afd8, and return -1. [callee:0x00595801, callee:0x0058AFCF, callee:0x0058AFD8, source:raw]
    // CALL: Open the file with CreateFileA using the resolved access, share mode, security attributes, creation disposition and flags. [global:0x0059E224, source:raw]
    // GUARD: If the returned handle is INVALID_HANDLE_VALUE, close it with CloseHandle, retrieve GetLastError, translate it through ErrorIDLookupTable, and return -1. [global:0x0059E1A8, global:0x0059E188, callee:0x0058AF5C, source:raw]
    // CALL: Classify the handle with GetFileType (2 = pipe, 3 = console set extra attribute bits) and register the descriptor with the handle via sub_595924. [global:0x0059E0F8, callee:0x00595924, source:raw]
    // GUARD: For non-char-device descriptors with append semantics (a2 bit 1): seek to one byte past EOF via FileSeekViaSetFilePointer, read one byte through sub_58CA19, and if it equals the 0x1A EOF marker rewind with sub_59797B and reset the seek position; on any failure release the descriptor via sub_58C331 and return -1. [callee:0x0058C789, callee:0x0058CA19, callee:0x0059797B, callee:0x0058C331, source:raw]
    // STATE_TRANSITION: Record the descriptor attribute byte (adding bit 0x20 when the 0x48 attribute mask is empty and a2 bit 8 is set), leave the file critical section via FileCriticalSectionLeave, and return the descriptor index. [callee:0x00595AC0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_595AF9(LPCSTR name, int16 mode, int share, char attr) {
    //     SECURITY_ATTRIBUTES sa = { nLength: 12, bInheritHandle: (mode&0x80)==0 };
    //     parse access from mode&3, share from share, disposition from mode&0x700, flags from mode/attr;
    //     int fd = sub_595801();
    //     if (fd == -1) { set_tls_error(24); return -1; }
    //     HANDLE h = CreateFileA(name, access, share, &sa, disposition, flags, 0);
    //     if (h == INVALID_HANDLE_VALUE) { close; ErrorIDLookupTable(GetLastError()); return -1; }
    //     int ft = GetFileType(h);
    //     if (ft) { tag flags by type; sub_595924(fd, h);
    //       if (char-device) { EOF-marker scan and rewind via SetFilePointer/read; }
    //       set descriptor flags; FileCriticalSectionLeave(fd); return fd; }
    //     CloseHandle(h); ErrorIDLookupTable(GetLastError()); return -1;
    //   }
    // UNRESOLVED: The three written byte globals byte_FF00000000005450/5451/5452 are reported as written but do not appear in the reconstructed body; their location and purpose are unknown.
    // UNRESOLVED: The descriptor table base dword_8D4920 used for the descriptor flag writes is not present in the packet globals; the entry layout (36-byte stride) is inferred from the raw source.
    // UNRESOLVED: Exact meaning of a4 attribute byte bit 0x80 relative to dword_8D3E70 (binary/text mode) is inferred, not confirmed.
}
