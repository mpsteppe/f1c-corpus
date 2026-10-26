// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045D260
// Canonical corpus name: NetworkReplayBufferInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkReplayBufferInit_0045d260.c

void UnknownObject::NetworkReplayBufferInit()
{
    // Initializer for a replay/network buffer-control object. Copies the session port word_7D0FE8 (low 16 bits) into this[1] and this[2], clears the active-flag byte at this, zeroes the four global dwords at 0x008D4680 through 0x008D468C, then XOR-decodes 6 bytes of byte_59F0C4 against the constant 0x3E into the first 6 bytes of dword_8D4680 to build an obfuscation key. Finally calls MemoryObjectAllocator on &dword_8D4680 with size 8, callback sub_45D2D0, and parameters 1 and 0, stores the returned handle into this[3], and returns it.
    // ASSIGNMENT: Copy the low 16 bits of word_7D0FE8 into this[1] (offset 4) as the session port. [field:this:0x00000004, global:0x007D0FE8, source:raw]
    // ASSIGNMENT: Copy the low 16 bits of word_7D0FE8 into this[2] (offset 8) again. [field:this:0x00000008, global:0x007D0FE8, source:raw]
    // ASSIGNMENT: Clear the active/initialized flag byte at this (offset 0). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the global dword_8D4680. [global:0x008D4680, source:raw]
    // ASSIGNMENT: Zero the global dword_8D4684. [global:0x008D4684, source:raw]
    // ASSIGNMENT: Zero the global dword_8D4688. [global:0x008D4688, source:raw]
    // ASSIGNMENT: Zero the global dword_8D468C. [global:0x008D468C, source:raw]
    // LOOP: For i from 0 to 5 inclusive, write byte_59F0C4[i] XOR 0x3E into byte i of dword_8D4680, decoding six obfuscated key bytes. [global:0x008D4680, global:0x0059F0C4, source:raw]
    // CALL: Call MemoryObjectAllocator(&dword_8D4680, 8, sub_45D2D0, 1, 0) to allocate a memory object for network encoding, passing sub_45D2D0 as the callback. [callee:0x00562B50, global:0x008D4680, global:0x0045D2D0, source:raw]
    // ASSIGNMENT: Store the MemoryObjectAllocator result into this[3] (offset 12). [field:this:0x0000000C, source:raw]
    // RETURN: Return the MemoryObjectAllocator result. [source:raw]
    // CALL: Invoked by sub_463E20 (0x00463E20) during network/replay initialization. [caller:0x00463E20, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_45D260(_DWORD *this) {
    //     this[1] = (unsigned __int16)word_7D0FE8;
    //     this[2] = (unsigned __int16)word_7D0FE8;
    //     *(_BYTE *)this = 0;
    //     dword_8D4680 = 0; dword_8D4684 = 0; dword_8D4688 = 0; dword_8D468C = 0;
    //     for (int i = 0; i < 6; ++i)
    //       *((_BYTE *)&dword_8D4680 + i) = byte_59F0C4[i] ^ 0x3E;
    //     int result = MemoryObjectAllocator(&dword_8D4680, 8, sub_45D2D0, 1, 0);
    //     this[3] = result;
    //     return result;
    //   }
    // UNRESOLVED: Global off_5C5B68 is listed as a read global in the packet but never referenced by the raw source; it is left unaccounted in unresolved_evidence_refs.
    // UNRESOLVED: The exact role of sub_45D2D0 (network encode/decode callback) and the meaning of the MemoryObjectAllocator parameters 1 and 0 are DERIVED from the skeleton fill, not independently evidenced.
    // UNRESOLVED: The owning class is unknown; the packet marks owner as UnknownObject/UNKNOWN.
}
