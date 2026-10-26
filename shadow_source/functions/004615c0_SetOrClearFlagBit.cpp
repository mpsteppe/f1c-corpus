// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004615C0
// Canonical corpus name: UtilityFunction_15c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_15c0_004615c0.c

void UnknownObject::SetOrClearFlagBit()
{
    // Sets or clears a single bit in the byte at this+110 (this+0x6E), selected by bit index a2, controlled by boolean a3. When a3 is nonzero the bit is set (OR); when a3 is zero the bit is cleared (AND NOT). Returns the bit mask value, which is the inverted mask after the clear branch.
    // CALCULATION: v4 = 1 << a2; build a single-bit mask from bit index a2. [source:raw]
    // ASSIGNMENT: v5 = this[110]; read the current byte value at this+0x6E. [field:this:0x0000006E, source:raw]
    // GUARD: Branch on a3: nonzero selects the set path, zero selects the clear path. [source:raw]
    // ASSIGNMENT: Set path: this[110] = v4 | v5; OR the mask into the byte at this+0x6E. [field:this:0x0000006E, source:raw]
    // ASSIGNMENT: Clear path: invert the mask (LOBYTE(v4) = ~(_BYTE)v4) then this[110] = v4 & v5; AND the inverted mask into the byte at this+0x6E. [field:this:0x0000006E, source:raw]
    // RETURN: Return v4; the mask value, which is the inverted mask after the clear path. [source:raw]

    // Conservative worker pseudocode:
    //   char SetOrClearFlagBit(BYTE *this, char bitIndex, char enable) {
    //     int mask = 1 << bitIndex;
    //     char cur = this[110];
    //     if (enable)
    //       this[110] = (BYTE)mask | cur;
    //     else {
    //       mask = ~((BYTE)mask);
    //       this[110] = (BYTE)mask & cur;
    //     }
    //     return (char)mask;
    //   }
    // UNRESOLVED: Semantic meaning of the individual flag bits in the byte at this+0x6E is unknown; caller SessionConfigBuilder implies session-configuration flags.
    // UNRESOLVED: Return value is the (possibly inverted) mask; whether callers consume it is unknown.
}
