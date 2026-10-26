// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C2A0
// Canonical corpus name: GlobalZeroInit_c2a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalZeroInit_c2a0_0053c2a0.c

void UnknownObject::GlobalZeroInit()
{
    // Trivial initializer: writes 0 to the global dword_8B6AB8 and 0 to the global byte_8B6AC8, then returns the this pointer unchanged. The this pointer is not otherwise used. Its 36 recorded callers span engine, audio, input, hash-table and struct-init paths, consistent with a shared module/global zeroing routine, but that reading is DERIVED from caller context only.
    // ASSIGNMENT: Write 0 to the global dword_8B6AB8. [global:0x008B6AB8, source:raw]
    // ASSIGNMENT: Write 0 to the global byte_8B6AC8. [global:0x008B6AC8, source:raw]
    // RETURN: Return the this pointer unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   void* sub_53C2A0(void* this) {
    //     dword_8B6AB8 = 0;
    //     byte_8B6AC8 = 0;
    //     return this;
    //   }
    // UNRESOLVED: The this pointer is unused by the body; the relationship between this and the two zeroed globals is unknown.
    // UNRESOLVED: Whether dword_8B6AB8 and byte_8B6AC8 are module state shared by all callers is DERIVED from the broad caller set, not confirmed by the packet.
    // UNRESOLVED: Types and broader layout of the two globals beyond their literal names are unknown.
}
