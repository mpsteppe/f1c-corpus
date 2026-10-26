// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A3B30
// Canonical corpus name: sub_4A3B30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A3B30_004a3b30.c

void UnknownObject::PitCrewExtStructInit()
{
    // Zeroes four consecutive extended DWORD fields at this+0x78, this+0x7C, this+0x80 and this+0x84, then calls sub_4A2220(this) unconditionally and returns its result. Existing analysis reads this as the extended part of a pit-crew/UI component initializer, with sub_4A2220 performing base struct initialization and resource cleanup. Called from sub_4A4900 (0x004A4900) and UIComponentCleanup (0x004A4DB0).
    // ASSIGNMENT: Zero the DWORD at this+0x78. [field:this:0x00000078, function:0x004A3B30, source:raw]
    // ASSIGNMENT: Zero the DWORD at this+0x7C. [field:this:0x0000007C, source:raw]
    // ASSIGNMENT: Zero the DWORD at this+0x80. [field:this:0x00000080, source:raw]
    // ASSIGNMENT: Zero the DWORD at this+0x84. [field:this:0x00000084, source:raw]
    // CALL: Call sub_4A2220(this) unconditionally to run the base struct initialization and cleanup; the call appears in the raw source but sub_4A2220 is absent from this packet's callee list, so no callee evidence reference exists. [function:0x004A3B30, source:raw]
    // RETURN: Return the result of sub_4A2220(this). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A3B30(void* this) {
    //     *(DWORD*)(this + 0x78) = 0;
    //     *(DWORD*)(this + 0x7C) = 0;
    //     *(DWORD*)(this + 0x80) = 0;
    //     *(DWORD*)(this + 0x84) = 0;
    //     return sub_4A2220(this);
    //   }
    // UNRESOLVED: sub_4A2220 is invoked by the raw source but is not listed in this packet's callees, so its semantics here are grounded only in existing analysis (base struct init/cleanup), not packet callee evidence.
    // UNRESOLVED: The purpose of the four zeroed fields at 0x78..0x84 (extended component state) is not evidenced by this packet.
}
