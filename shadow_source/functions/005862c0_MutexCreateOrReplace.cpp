// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005862C0
// Canonical corpus name: MutexCreatorWithErrorHandling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexCreatorWithErrorHandling_005862c0.c

void UnknownObject::MutexCreateOrReplace()
{
    // Creates or replaces a mutex on an object. If the ready flag byte at this+0x58 is set and CloseHandle on the stored handle at this+0x50 succeeds, the handle slot is cleared to 0. A fresh unnamed mutex is then created with CreateMutexA using a SECURITY_ATTRIBUTES struct (nLength=12, no descriptor, inheritable) and stored at this+0x50; when creation succeeds the ready flag at this+0x58 is set to 1. Returns the ready flag byte. Invoked by sub_5837F0.
    // GUARD: If the ready flag byte at this+0x58 is set, attempt to close the existing mutex handle at this+0x50 via CloseHandle. [field:this:0x00000058, global:0x0059E1A8, source:raw]
    // ASSIGNMENT: When the flag is set and CloseHandle succeeds, clear the handle slot at this+0x50 to 0. [field:this:0x00000050, global:0x0059E1A8, source:raw]
    // ASSIGNMENT: Initialize the SECURITY_ATTRIBUTES for the new mutex: nLength=12, lpSecurityDescriptor=0, bInheritHandle=1. [source:raw]
    // CALL: CreateMutexA(&MutexAttributes, 0, 0) creates an unnamed mutex; the returned HANDLE is stored at this+0x50. [global:0x0059E1AC, field:this:0x00000050, source:raw]
    // STATE_TRANSITION: If the new handle at this+0x50 is non-null, set the ready flag byte at this+0x58 to 1. [field:this:0x00000050, field:this:0x00000058, source:raw]
    // RETURN: Return the ready flag byte at this+0x58. [field:this:0x00000058, function:0x005862C0, source:raw]
    // CALL: Invoked by sub_5837F0 (0x005837F0). [caller:0x005837F0]

    // Conservative worker pseudocode:
    //   char MutexCreateOrReplace(int *this) {
    //     if (*(char *)(this + 0x58) && CloseHandle(*(void **)(this + 0x50)))
    //       *(int *)(this + 0x50) = 0;
    //     MutexAttributes.nLength = 12;
    //     MutexAttributes.lpSecurityDescriptor = 0;
    //     MutexAttributes.bInheritHandle = 1;
    //     *(void **)(this + 0x50) = CreateMutexA(&MutexAttributes, 0, 0);
    //     if (*(void **)(this + 0x50))
    //       *(char *)(this + 0x58) = 1;
    //     return *(char *)(this + 0x58);
    //   }
    // UNRESOLVED: global:0xFF00000000005450, global:0xFF00000000005451 and global:0xFF00000000005452 are listed as written globals but do not appear in the decompiled body; their role is unknown.
}
