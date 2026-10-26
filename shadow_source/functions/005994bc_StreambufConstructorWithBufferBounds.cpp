// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005994BC
// Canonical corpus name: ObjectInitializationWithBufferBoundsSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitializationWithBufferBoundsSetup_005994bc.c

void UnknownObject::StreambufConstructorWithBufferBounds()
{
    // Constructor for a streambuf-style buffer-control object. Sets the byte flag at this+72 to (a3 == 1). When a3 is zero, null-checks the locale sub-object at this+76, acquires a locale refcount under a lock unless this equals -76 (sentinel), and zeroes the external buffer pointer at this+68. Runs SelfReferentialPointerRingInit to wire the pointer ring, then when a2 is non-null and the byte flag is clear, installs the caller's external buffer: boundary pointers at this+12, this+16, this+28, this+32, this+44, this+48 are derived from a2 (a2, a2+8, a2+4). Always stores a2 into the buffer base at this+80, and writes the global capacity dword_8D5A68 into this+64 and this+60, zeroing this+56. Returns dword_8D5A68.
    // ASSIGNMENT: Set the byte at this+72 to (a3 == 1), selecting the no-internal-buffer layout when a3 is 1. [field:this:0x00000048, source:raw]
    // GUARD: When a3 is zero, run the internal-buffer path: null-check the locale sub-object, conditionally acquire its refcount, and clear the external buffer pointer. [source:raw]
    // CALL: Call NullCheckWithVirtualDispatch on the pointer at this+76 to validate the locale sub-object. [callee:0x00598C70, source:raw]
    // GUARD: Unless this equals -76 (sentinel for the virtual base offset), call LocaleRefcountAcquireUnderLock on the pointer at this+76 to acquire the locale reference count under a lock. [callee:0x00598C1C, source:raw]
    // ASSIGNMENT: Zero the external buffer pointer field at this+68 on the a3 == 0 path. [field:this:0x00000044, source:raw]
    // CALL: Call SelfReferentialPointerRingInit(this) to wire the self-referential ring of buffer pointer slots. [callee:0x0059A4C9, source:raw]
    // GUARD: When a2 is non-null and the byte flag at this+72 is zero, install the external buffer boundary pointers derived from a2. [field:this:0x00000048, source:raw]
    // ASSIGNMENT: Set this+28 to a2 (put back/eback start of the caller buffer). [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Set this+12 and this+16 to a2 + 8 (get pointer and get-end pointer). [field:this:0x0000000C, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Set this+32 to a2 (put pointer). [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Set this+44 and this+48 to a2 + 4 (put-end pointer and put base). [field:this:0x0000002C, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Store a2 into this+80 as the external buffer base pointer. [field:this:0x00000050, source:raw]
    // ASSIGNMENT: Write the global dword_8D5A68 into this+64 as the buffer capacity/limit. [field:this:0x00000040, global:0x008D5A68, source:raw]
    // ASSIGNMENT: Zero this+56 (codecvt/state field) and write dword_8D5A68 into this+60 (encoding state tracking). [field:this:0x00000038, field:this:0x0000003C, global:0x008D5A68, source:raw]
    // RETURN: Return the global dword_8D5A68 value as the function result. [global:0x008D5A68, source:raw]
    // CALL: Invoked during construction of buffer-control objects by ObjectConstructorWithSEHVTableInitChain (0x00598BBC) and by FileCloseWrapperWithStatus (0x00599495). [caller:0x00598BBC, caller:0x00599495, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_5994BC(int this, int a2, int a3) {
    //     byte_at(this + 72) = (a3 == 1);
    //     if (a3 == 0) {
    //       NullCheckWithVirtualDispatch(this + 76);
    //       if (this != -76) LocaleRefcountAcquireUnderLock(this + 76);
    //       dword_at(this + 68) = 0;
    //     }
    //     SelfReferentialPointerRingInit(this);
    //     if (a2 != 0 && byte_at(this + 72) == 0) {
    //       dword_at(this + 28) = a2;
    //       dword_at(this + 12) = a2 + 8;
    //       dword_at(this + 16) = a2 + 8;
    //       dword_at(this + 32) = a2;
    //       dword_at(this + 44) = a2 + 4;
    //       dword_at(this + 48) = a2 + 4;
    //     }
    //     dword_at(this + 80) = a2;
    //     dword_at(this + 64) = dword_8D5A68;
    //     dword_at(this + 56) = 0;
    //     dword_at(this + 60) = dword_8D5A68;
    //     return dword_8D5A68;
    //   }
    // UNRESOLVED: The pointer at this+76 passed to the locale calls has no packet field evidence reference (field list ends at 0x50); its offset is rendered from the raw source only.
    // UNRESOLVED: The exact semantics of the byte flag at this+72 and the purpose of the -76 sentinel comparison are DERIVED from the skeleton fill, not independently evidenced.
    // UNRESOLVED: The owning class is unknown; the packet marks owner as UnknownObject/UNKNOWN.
}
