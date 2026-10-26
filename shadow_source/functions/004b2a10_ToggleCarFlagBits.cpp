// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2A10
// Canonical corpus name: ShortComputation_2a10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_2a10_004b2a10.c

void UnknownObject::ToggleCarFlagBits()
{
    // Bitfield manipulator: builds a 16-bit mask whose high byte is (a2 + 1) and low byte is zero, then toggles the 0xF00 bits of this[11] (dword at byte offset 0x2C) that intersect that mask. Writes the result back to this[11] and returns it.
    // CALCULATION: v2 = (a2 + 1) << 8; builds a word with high byte a2+1, low byte zero; effectively an index-encoded nibble selector [source:raw, field:this:0x0000002C]
    // CALCULATION: result = ((unsigned __int16)this[11] ^ v2) & 0xF00 ^ this[11]; toggles only the 0xF00 bits that differ between the current field value and the selector, leaving the rest unchanged [source:raw, field:this:0x0000002C]
    // ASSIGNMENT: this[11] = result; stores the toggled bit pattern back into the dword at byte offset 0x2C [source:raw, field:this:0x0000002C]
    // RETURN: return result; returns the new field value to the caller [source:raw, function:0x004B2A10]

    // Conservative worker pseudocode:
    //   unsigned short selector = (unsigned char)(a2 + 1) << 8;
    //   this[11] ^= selector & 0xF00;
    //   return this[11];
    // UNRESOLVED: Semantics of the 0xF00 bits of this[11] are unknown; the prelabel marks this as a structural twin of CarFlagByteSetter (00476060), suggesting car flag/lighting state, but no packet evidence names the field or the bits.
    // UNRESOLVED: Called from SetupCarLightingAndRender (0x004C71C0), consistent with a lighting/flag-update role, but that caller relationship does not by itself identify the owner object.
}
