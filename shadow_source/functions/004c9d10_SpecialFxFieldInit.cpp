// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9D10
// Canonical corpus name: TwoFieldSetter_9d10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoFieldSetter_9d10_004c9d10.c

void UnknownObject::SpecialFxFieldInit()
{
    // Initializes two fields of a special-FX object (offset 0x20 to -1.0f, a sentinel/inactive value, and offset 0x24 to 0). Returns the object pointer unchanged. Called from SpecialFX_Init (0x004CF070) during special FX setup.
    // ASSIGNMENT: Set field at offset 0x20 to -1082130432 (-1.0f), a sentinel/inactive value. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Set field at offset 0x24 to 0, clearing a state/counter field. [field:this:0x00000024, source:raw]
    // RETURN: Return the object pointer (this) unchanged; the function has no other effect. [function:0x004C9D10, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *SpecialFxFieldInit(_DWORD *this) {
    //     this[8] = -1082130432; /* -1.0f sentinel * /
    //     this[9] = 0;
    //     return this;
    //   }
    // UNRESOLVED: The concrete special-FX object type and the exact meaning of the sentinel at offset 0x20 and the zeroed field at offset 0x24 are not established from the packet alone.
    // UNRESOLVED: Only one caller (SpecialFX_Init at 0x004CF070) is recorded; the broader lifecycle context of the object is not in this packet.
}
