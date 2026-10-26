// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406130
// Canonical corpus name: MutexSynchronizationObjectInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexSynchronizationObjectInit_00406130.c

void UnknownObject::MutexSynchronizationObjectInit()
{
    // Constructor/initializer for a mutex synchronization object with a two-phase setup. Phase one uses the file-mutex vtable (off_59E50C): three 20-byte file-path slot entries are initialised from byte offset 0x10, each entry calling StringCopyWithBufferRealloc(&byte_5EA438). Phase two allocates an OS mutex via CreateMutexA into this[20] (0x50), switches the vtable to off_59E4EC, sets a 1.0f timeout at 0x4, stores the configuration parameter a2 at 0x8, and reuses the same 20-byte entry pattern from byte offset 0x1C. If the mutex handle was created, the function takes the mutex with MutexLockWithTimeout(0). Returns this.
    // ASSIGNMENT: Store the file-mutex vtable pointer off_59E50C into the vtable slot at offset 0x0. [field:this:0x00000000, global:0x0059E50C, source:raw]
    // LOOP: First three-entry loop: walk three 20-byte file-path slot entries beginning at byte offset 0x10 (this + 4 dwords), decrementing a count of 3 until it reaches zero. [source:raw]
    // ASSIGNMENT: Per entry: clear the leading dword (offset 0x10 for the first entry), write -1 into the following three dwords (offsets 0x14/0x18/0x1C for the first entry), and clear the trailing byte flag (offset 0x20 for the first entry); the same pattern repeats at each successive 20-byte stride. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALL: Call StringCopyWithBufferRealloc(&byte_5EA438) once per entry to initialise the slot string. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Clear the byte flags of the slot entries; the extractor rendered these byte stores at consecutive addresses 0xFF00000000005450, 0xFF00000000005451 and 0xFF00000000005452. [global:0xFF00000000005450, global:0xFF00000000005451, global:0xFF00000000005452, source:raw]
    // ASSIGNMENT: Set pre-creation state: this[20] (0x50) = 0, byte flag at offset 0x58 (88) = 0, this[21] (0x54) = -1. [field:this:0x00000050, field:this:0x00000058, field:this:0x00000054, source:raw]
    // CALL: Create the OS mutex with CreateMutexA(&MutexAttributes, 0, 0), using a SECURITY_ATTRIBUTES block (nLength 12, no security descriptor, inheritable handle), and store the returned handle into this[20] (0x50). [global:0x0059E1AC, field:this:0x00000050, source:raw]
    // GUARD: If the mutex handle is non-null, set the byte flag at offset 0x58 (88) to 1. [field:this:0x00000058, source:raw]
    // ASSIGNMENT: Switch to the thread-object vtable off_59E4EC at 0x0 and set the timeout 1.0f (literal 1065353216) at 0x4, the configuration parameter a2 at 0x8, and zero at 0xC. [field:this:0x00000000, global:0x0059E4EC, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // LOOP: Second three-entry loop: walk three 20-byte entries beginning at byte offset 0x1C (this + 7 dwords), decrementing a count of 3 until it reaches zero. [source:raw]
    // CALL: Call StringCopyWithBufferRealloc(&byte_5EA438) once per entry in the second loop. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Per entry of the second loop: write -1 into two dwords and clear the trailing byte flag, stepping 20 bytes between entries. [source:raw]
    // GUARD: If the byte flag at offset 0x58 (88) is set, take the mutex with MutexLockWithTimeout(0). [field:this:0x00000058, callee:0x00406700, source:raw]
    // ASSIGNMENT: Write -1 into this[23] (0x5C) as a trailing sentinel. [field:this:0x0000005C, source:raw]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_406130(_DWORD *this, int a2) {
    //     *this = &off_59E50C;
    //     char *v3 = (char *)(this + 4);
    //     int v7 = 3;
    //     do {
    //       *(_DWORD *)v3 = 0;
    //       *((_DWORD *)v3 + 1) = -1;
    //       StringCopyWithBufferRealloc(&byte_5EA438);
    //       *((_DWORD *)v3 + 2) = -1;
    //       *((_DWORD *)v3 + 3) = -1;
    //       v3[16] = 0;
    //       v3 += 20;
    //       --v7;
    //     } while (v7);
    //     this[20] = 0;
    //     *((_BYTE *)this + 88) = 0;
    //     this[21] = -1;
    //     SECURITY_ATTRIBUTES sa = {12, 0, 1};
    //     HANDLE m = CreateMutexA(&sa, 0, 0);
    //     this[20] = m;
    //     if (m) *((_BYTE *)this + 88) = 1;
    //     *this = &off_59E4EC;
    //     this[1] = 1065353216;
    //     this[2] = a2;
    //     this[3] = 0;
    //     char *v5 = (char *)(this + 7);
    //     int v9 = 3;
    //     do {
    //       StringCopyWithBufferRealloc(&byte_5EA438);
    //       *((_DWORD *)v5 - 1) = -1;
    //       *(_DWORD *)v5 = -1;
    //       v5[4] = 0;
    //       v5 += 20;
    //       --v9;
    //     } while (v9);
    //     if (*((_BYTE *)this + 88)) MutexLockWithTimeout(0);
    //     this[23] = -1;
    //     return this;
    //   }
    // UNRESOLVED: The three consecutive byte-store globals (0xFF00000000005450, 0xFF00000000005451, 0xFF00000000005452) do not map cleanly onto the source's byte-flag writes; the extractor appears to have resolved the loop's byte stores against an unknown base. Treated as an extractor rendering of the entry byte-flag clears.
    // UNRESOLVED: The object exposes two vtables (file-mutex off_59E50C then thread-object off_59E4EC); the class identity and the meaning of a2 (configuration parameter at 0x8) come from the caller 0x004078A0 and are unverified.
    // UNRESOLVED: this[20] holds either 0 or an OS mutex HANDLE depending on creation outcome; the exact HANDLE semantics are not confirmed here.
}
