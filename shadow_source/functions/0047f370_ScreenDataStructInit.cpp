// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047F370
// Canonical corpus name: ScreenDataStructInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScreenDataStructInit_0047f370.c

void UnknownObject::ScreenDataStructInit()
{
    // ScreenData object constructor: zeroes the large structure region via LargeStructZeroInit, installs the TextureManager vtable pointer off_5A6E70, clears a texture-related byte flag at +0x210C, zeroes a 0x7F0-byte texture-data region, and initializes three (min, max) range pairs to the sentinel defaults (0, -1). Returns this. Called by sub_485B90 (00485B90).
    // CALL: Call LargeStructZeroInit (00495190) to zero the large struct region before field setup. [callee:0x00495190, source:raw]
    // ASSIGNMENT: Install the TextureManager vtable pointer: this+0x0 = off_5A6E70. [field:this:0x00000000, global:0x005A6E70, source:raw]
    // CALCULATION: Zero the texture-data region: memset(this + 1607, 0, 0x7F0) covers 0x7F0 bytes starting at the 1607th dword. [source:raw]
    // ASSIGNMENT: Clear the byte flag at +0x210C to 0. [field:this:0x0000210C, source:raw]
    // ASSIGNMENT: First range pair: min +0x218C = 0, max +0x2190 = -1. [field:this:0x0000218C, field:this:0x00002190, source:raw]
    // ASSIGNMENT: Second range pair: min +0x2194 = 0, max +0x2198 = -1. [field:this:0x00002194, field:this:0x00002198, source:raw]
    // ASSIGNMENT: Third range pair: min +0x219C = 0, max +0x21A0 = -1. [field:this:0x0000219C, field:this:0x000021A0, source:raw]
    // RETURN: Return the constructed object pointer this. [source:raw]
    // CALL: Invoked by sub_485B90 (00485B90) during construction of the ScreenData object. [caller:0x00485B90, source:raw]

    // Conservative worker pseudocode:
    //   LargeStructZeroInit();
    //   this[0x0] = off_5A6E70;
    //   memset(this + 1607, 0, 0x7F0);
    //   *((_BYTE *)this + 8460) = 0;
    //   this[2147] = 0; this[2148] = -1;
    //   this[2149] = 0; this[2150] = -1;
    //   this[2151] = 0; this[2152] = -1;
    //   return this;
    // UNRESOLVED: The semantic meaning of the three (min, max) range pairs is not documented in this function; their use depends on the ScreenData consumer.
    // UNRESOLVED: The zeroed texture-data region has no per-field evidence refs in the packet, so individual fields inside it cannot be named.
}
