// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585EA0
// Canonical corpus name: MutexPairInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexPairInitializer_00585ea0.c

void UnknownObject::MutexPairInitializer()
{
    // Initializes a mutex-pair/list object: clears two DWORD pointer slots (offsets 0x0, 0x4), two byte state flags (offsets 0x8, 0x18), and sets two INFINITE timeout DWORDs (-1 at offsets 0x10, 0x20). Creates two anonymous inheritable mutexes via CreateMutexA (0x0059E1AC), storing each handle at offset 0xC and 0x1C and setting the corresponding created flag (offsets 0x14, 0x24) to 1 only when the handle is non-null. Returns this.
    // ASSIGNMENT: Set the byte flag at this+0x8 to 0, clearing list-1 state. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Set the DWORD at this+0xC to 0 before storing the mutex-1 handle. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Set the byte at this+0x14 to 0, clearing the mutex-1 created flag. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Set the DWORD at this+0x10 to -1, initializing the mutex-1 timeout to INFINITE. [field:this:0x00000010, source:raw]
    // CALL: Call CreateMutexA (0x0059E1AC) with a 12-byte SECURITY_ATTRIBUTES (null security descriptor, bInheritHandle=1), initial owner 0 and null name, creating anonymous mutex 1; result captured in v2. [global:0x0059E1AC, source:raw]
    // ASSIGNMENT: Store the mutex-1 handle v2 into the DWORD at this+0xC. [field:this:0x0000000C, source:raw]
    // GUARD: If mutex-1 handle v2 is non-null, set the created flag byte at this+0x14 to 1. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Set the byte flag at this+0x18 to 0, clearing list-2 state. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Set the DWORD at this+0x1C to 0 before storing the mutex-2 handle. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Set the byte at this+0x24 to 0, clearing the mutex-2 created flag. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Set the DWORD at this+0x20 to -1, initializing the mutex-2 timeout to INFINITE. [field:this:0x00000020, source:raw]
    // CALL: Call CreateMutexA (0x0059E1AC) again with the same attributes, creating anonymous mutex 2; result captured in v3. [global:0x0059E1AC, source:raw]
    // ASSIGNMENT: Store the mutex-2 handle v3 into the DWORD at this+0x1C. [field:this:0x0000001C, source:raw]
    // GUARD: If mutex-2 handle v3 is non-null, set the created flag byte at this+0x24 to 1. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Set the DWORD at this+0x0 to 0, clearing the list head pointer. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set the DWORD at this+0x4 to 0, clearing the second list pointer. [field:this:0x00000004, source:raw]
    // RETURN: Return this, completing the initialization. [function:0x00585EA0, source:raw]

    // Conservative worker pseudocode:
    //   void *MutexPairInitializer(void *this) {
    //       this->byte_8 = 0;
    //       this->mutex1Handle_0xC = 0;
    //       this->mutex1Created_0x14 = 0;
    //       this->mutex1Timeout_0x10 = -1;
    //       HANDLE v2 = CreateMutexA(&MutexAttributes, 0, 0);
    //       this->mutex1Handle_0xC = v2;
    //       if (v2) this->mutex1Created_0x14 = 1;
    //       this->byte_18 = 0;
    //       this->mutex2Handle_0x1C = 0;
    //       this->mutex2Created_0x24 = 0;
    //       this->mutex2Timeout_0x20 = -1;
    //       HANDLE v3 = CreateMutexA(&MutexAttributes, 0, 0);
    //       this->mutex2Handle_0x1C = v3;
    //       if (v3) this->mutex2Created_0x24 = 1;
    //       this->ptr_0x0 = 0;
    //       this->ptr_0x4 = 0;
    //       return this;
    //   }
    // UNRESOLVED: Three write-only globals byte_FF00000000005450/51/52 (0xFF00000000005450, 0xFF00000000005451, 0xFF00000000005452) appear in the packet with W access but are not visible in the decompiled source; their purpose and writer are unexplained.
    // UNRESOLVED: The SECURITY_ATTRIBUTES bInheritHandle=1 and null-name choices are preserved from the packet but their intended cross-process sharing semantics are not evidenced.
    // UNRESOLVED: The object type owning this initializer is unknown; offsets 0x0/0x4 and 0x10/0x14, 0x20/0x24 are read as pointer/DWORD pairs by consumer code not present in this packet.
}
