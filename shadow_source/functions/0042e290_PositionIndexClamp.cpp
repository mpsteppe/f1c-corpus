// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042E290
// Canonical corpus name: PositionIndexClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PositionIndexClamp_0042e290.c

void UnknownObject::PositionIndexClamp()
{
    // Maps a normalized double a2 (0.0-1.0) to a clamped integer array index in this[5] (offset 0x14). Splits at a2 < 0.5: the lower half scales the midpoint this[6] (offset 0x18) by 2*a2; the upper half maps from the far side this[4] - this[6] - 1. Finally clamps the result to [0, this[4] - 1] (this[4] at offset 0x10) and returns the upper bound this[4] - 1. No calls.
    // GUARD: Branch on a2 < 0.5 selecting the lower-half mapping versus the upper-half mapping. [source:raw]
    // ASSIGNMENT: Lower half (a2 < 0.5): this[5] = (int)((double)(int)this[6] * (a2 + a2)), scaling midpoint count by doubled normalized position. [field:this:0x00000014, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Upper half (a2 >= 0.5): this[5] = (int)((double)(this[4] - this[6] - 1) * (a2 + a2 - 1.0)) + this[6], folding the remaining range back onto the midpoint. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // GUARD: Final clamp: if the computed this[5] is negative, clamp to 0. [field:this:0x00000014, source:raw]
    // GUARD: Final clamp: if the computed this[5] exceeds the upper bound result = this[4] - 1, clamp this[5] to result. [field:this:0x00000010, field:this:0x00000014, source:raw]
    // RETURN: Return the upper bound result = this[4] - 1. [field:this:0x00000010, function:0x0042E290, source:raw]
    // CALL: Called by PressureForceFieldMapping (0x004313C0) to convert a normalized pressure/force field position into a clamped grid index. [caller:0x004313C0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_42E290(int* this, double a2) {
    //     if (a2 < 0.5)
    //       this[5] = (int)((double)(int)this[6] * (a2 + a2));
    //     else
    //       this[5] = (int)((double)(this[4] - this[6] - 1) * (a2 + a2 - 1.0)) + this[6];
    //     int result = this[4] - 1;
    //     if (this[5] < 0) this[5] = 0;
    //     else if (this[5] > result) this[5] = result;
    //     return result;
    //   }
    // UNRESOLVED: Globals dbl_59E420 (0x0059E420) and dbl_59E880 (0x0059E880) are flagged by packet facts as read but appear nowhere in the raw decompiled source; the skeleton fill calls them BaseDoubleConstant and HalfStep but neither role is verifiable from this packet.
    // UNRESOLVED: Exact meaning of this[4] (range bound) and this[6] (midpoint) outside the pressure-field caller is caller-context dependent.
}
