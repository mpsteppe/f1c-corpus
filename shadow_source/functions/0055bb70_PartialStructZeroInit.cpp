// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BB70
// Canonical corpus name: PartialStructZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PartialStructZeroInit_0055bb70.c

void UnknownObject::PartialStructZeroInit()
{
    // Partial zero-initializer (__thiscall): writes zero to eight scattered fields of the object — a dword at offset 0, a byte at offset 4, and six dwords at offsets 0x10C through 0x120. The intervening range is left untouched. Always returns 0.
    // ASSIGNMENT: Initialize the return value result to 0. [source:raw]
    // ASSIGNMENT: Zero the dword at offset 0 of this. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the byte at offset 4 of this. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the dword at offset 0x10C. [field:this:0x0000010C, source:raw]
    // ASSIGNMENT: Zero the dword at offset 0x110. [field:this:0x00000110, source:raw]
    // ASSIGNMENT: Zero the dword at offset 0x114. [field:this:0x00000114, source:raw]
    // ASSIGNMENT: Zero the dword at offset 0x118. [field:this:0x00000118, source:raw]
    // ASSIGNMENT: Zero the dword at offset 0x11C. [field:this:0x0000011C, source:raw]
    // ASSIGNMENT: Zero the dword at offset 0x120. [field:this:0x00000120, source:raw]
    // RETURN: Return 0. [source:raw]
    // CALL: Called by sub_55BE80 (0x0055BE80), which invokes this as part of a larger construction sequence. [caller:0x0055BE80, source:raw]

    // Conservative worker pseudocode:
    //   int sub_55BB70(char* this) {
    //     *(int*)this = 0;
    //     this[4] = 0;
    //     ((int*)this)[67] = 0;
    //     ((int*)this)[68] = 0;
    //     ((int*)this)[69] = 0;
    //     ((int*)this)[70] = 0;
    //     ((int*)this)[71] = 0;
    //     ((int*)this)[72] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The object type and the layout meaning of the zeroed fields are unknown; caller sub_55BE80 (0x0055BE80) provides the only construction context.
    // UNRESOLVED: Only the listed offsets are initialized, leaving the rest of the object untouched — a deliberate partial initialization whose purpose is unknown.
    // UNRESOLVED: The returned 0 is likely ignored by the caller.
}
