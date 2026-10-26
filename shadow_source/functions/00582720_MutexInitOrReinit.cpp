// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00582720
// Canonical corpus name: sub_582720
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_582720_00582720.c

void UnknownObject::MutexInitOrReinit()
{
    // Initializes or reinitializes a mutex on an object. If the ready flag byte at this+0x28 is set and CloseHandle on the stored handle at this+0x20 succeeds, the handle slot is cleared to 0. A fresh unnamed mutex is then created with CreateMutexA using a SECURITY_ATTRIBUTES struct (nLength=12, no descriptor, inheritable) and stored at this+0x20; when creation succeeds the ready flag at this+0x28 is set to 1. Returns the ready flag byte. Invoked by sub_57BA10.
    // GUARD: If the ready flag byte at this+0x28 is set, attempt to close the existing mutex handle at this+0x20 via CloseHandle. [field:this:0x00000028, global:0x0059E1A8, source:raw]
    // ASSIGNMENT: When the flag is set and CloseHandle succeeds, clear the handle slot at this+0x20 to 0. [field:this:0x00000020, global:0x0059E1A8, source:raw]
    // ASSIGNMENT: Initialize the SECURITY_ATTRIBUTES for the new mutex: nLength=12, lpSecurityDescriptor=0, bInheritHandle=1. [source:raw]
    // CALL: CreateMutexA(&MutexAttributes, 0, 0) creates an unnamed mutex; the returned HANDLE is stored at this+0x20. [global:0x0059E1AC, field:this:0x00000020, source:raw]
    // STATE_TRANSITION: If the new handle at this+0x20 is non-null, set the ready flag byte at this+0x28 to 1. [field:this:0x00000020, field:this:0x00000028, source:raw]
    // RETURN: Return the ready flag byte at this+0x28. [field:this:0x00000028, function:0x00582720, source:raw]
    // CALL: Invoked by sub_57BA10 (0x0057BA10). [caller:0x0057BA10]

    // Conservative worker pseudocode:
    //   char MutexInitOrReinit(int *this) {
    //     if (*(char *)(this + 0x28) && CloseHandle(*(void **)(this + 0x20)))
    //       *(int *)(this + 0x20) = 0;
    //     MutexAttributes.nLength = 12;
    //     MutexAttributes.lpSecurityDescriptor = 0;
    //     MutexAttributes.bInheritHandle = 1;
    //     *(void **)(this + 0x20) = CreateMutexA(&MutexAttributes, 0, 0);
    //     if (*(void **)(this + 0x20))
    //       *(char *)(this + 0x28) = 1;
    //     return *(char *)(this + 0x28);
    //   }
    // UNRESOLVED: global:0xFF00000000005450, global:0xFF00000000005451 and global:0xFF00000000005452 are listed as written globals but do not appear in the decompiled body; their role is unknown.
}
