// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004883A0
// Canonical corpus name: F_5FieldInit
// Owner: UIObject [DERIVED]
// Raw source: functions/F_5FieldInit_004883a0.c

void UIObject::FieldInit()
{
    // Field initializer on an unknown UI-related object: zeroes three dwords at 0xE0, 0xE4 and 0xE8, sets the byte at 0xEC to 1 and the byte at 0xED to 0, then returns 0. No reads, no globals, no calls; called from UI construction/dispatch paths.
    // ASSIGNMENT: Zero the dword at this+0xE0. [field:this:0x000000E0]
    // ASSIGNMENT: Zero the dword at this+0xE4. [field:this:0x000000E4]
    // ASSIGNMENT: Zero the dword at this+0xE8. [field:this:0x000000E8]
    // ASSIGNMENT: Set the byte at this+0xEC to 1. [field:this:0x000000EC]
    // ASSIGNMENT: Set the byte at this+0xED to 0. [field:this:0x000000ED]
    // RETURN: Return the integer result 0. [source:raw]

    // Conservative worker pseudocode:
    //   int FieldInit(int this) {
    //     *(DWORD*)(this + 0xE0) = 0;
    //     *(DWORD*)(this + 0xE4) = 0;
    //     *(DWORD*)(this + 0xE8) = 0;
    //     *(BYTE*)(this + 0xEC) = 1;
    //     *(BYTE*)(this + 0xED) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Object type owning the fields at 0xE0..0xED is unknown; the UIObject owner is DERIVED only from the caller names (UIConstructorWithVTableParams, VTableDispatch).
    // UNRESOLVED: Semantic meaning of the three zeroed dwords and the two byte flags (0xEC initialized to 1) is not established.
}
