// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00502BEA
// Canonical corpus name: ZeroPairInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroPairInit_00502bea.c

void UnknownObject::ZeroPairInit()
{
    // Initializes a two-field structure by zeroing consecutive DWORDs: this[1] (offset 0x4) then *this (offset 0x0). Returns the this pointer unchanged.
    // ASSIGNMENT: Zero this[1] at offset 0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero *this at offset 0x0. [field:this:0x00000000, source:raw]
    // RETURN: Return the this pointer unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_502BEA(_DWORD* this) {
    //     this[1] = 0;
    //     *this = 0;
    //     return this;
    //   }
    // UNRESOLVED: Owning class and purpose of the zeroed two-DWORD pair are unknown; callers named NetworkPacketSendReceive and AudioSoundBufferSetup do not identify it.
}
