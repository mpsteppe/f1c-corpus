// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404A50
// Canonical corpus name: FAILWRONGTRIAGE
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FAILWRONGTRIAGE_00404a50.c

void UnknownObject::FAILWRONGTRIAGE()
{
    // Allocates an 88-byte object via OperatorNewNhMallocWrapper and runs a field-by-field initializer on it: most dwords are cleared, the dwords at +44/+52/+60 are set to -1, the dword at +24 is set to the decimal literal 1142292480 (the existing analysis interprets that 4-byte pattern as a float constant), and the bytes at +20/+21/+36 are cleared. Stores the object pointer at this+0, or 0 when the allocation fails. An allocator-plus-constructor helper for an 88-byte struct whose type is not evidenced here.
    // CALL: Allocate an 88-byte object via OperatorNewNhMallocWrapper(88); the result gates the initialization branch. [callee:0x00587C03, source:raw]
    // GUARD: If the allocation returned non-null, initialize the object and store it at this+0; otherwise store a null pointer at this+0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero-initialize most of the 88-byte object: dwords at +0/+4/+8/+12/+16/+32/+40/+48/+56/+64/+68/+72/+76/+80/+84 and bytes at +20/+21/+36 are cleared. [source:raw]
    // ASSIGNMENT: Set the dwords at +44/+52/+60 to -1 (sentinel values) and the dword at +24 to the decimal literal 1142292480. [source:raw]
    // ASSIGNMENT: Store the initialized object pointer at this+0 on success, or null on allocation failure. [field:this:0x00000000, source:raw]
    // RETURN: Return this, the pointer to the slot that now holds the allocated object or null. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int* FAILWRONGTRIAGE(int* this) {
    //     int obj = OperatorNewNhMallocWrapper(88);
    //     if (obj) {
    //       *(DWORD*)(obj + 0) = 0;  *(DWORD*)(obj + 4) = 0;
    //       *(DWORD*)(obj + 8) = 0;  *(DWORD*)(obj + 12) = 0;
    //       *(DWORD*)(obj + 16) = 0;
    //       *(DWORD*)(obj + 40) = 0;  *(DWORD*)(obj + 44) = -1;
    //       *(DWORD*)(obj + 48) = 0;  *(DWORD*)(obj + 52) = -1;
    //       *(DWORD*)(obj + 56) = 0;  *(DWORD*)(obj + 60) = -1;
    //       *(DWORD*)(obj + 64) = 0;  *(DWORD*)(obj + 68) = 0;
    //       *(DWORD*)(obj + 72) = 0;  *(DWORD*)(obj + 76) = 0;
    //       *(DWORD*)(obj + 24) = 1142292480;
    //       *(DWORD*)(obj + 32) = 0;
    //       *(BYTE*)(obj + 36) = 0;
    //       *(DWORD*)(obj + 80) = 0;  *(DWORD*)(obj + 84) = 0;
    //       *(BYTE*)(obj + 20) = 0;  *(BYTE*)(obj + 21) = 0;
    //       *(DWORD*)(obj + 28) = 0;
    //       *this = obj;
    //     } else {
    //       *this = 0;
    //     }
    //     return this;
    //   }
    // UNRESOLVED: Global dword_59E48C (0x0059E48C) is listed as read by the deterministic fact table but is not referenced anywhere in the decompiled body; its role is not evidenced in the source.
    // UNRESOLVED: Field semantics of the 88-byte object are unknown: which -1 fields are indices/IDs, and what the dword at +24 (decimal literal 1142292480) represents; the existing analysis interprets +24 as a float, DERIVED only.
    // UNRESOLVED: The object type, its owner class and the caller relationship are not evidenced in this packet; the function has no static callers listed.
    // UNRESOLVED: Why this allocator/constructor is named FAILWRONGTRIAGE in the corpus is not determinable from the body.
}
