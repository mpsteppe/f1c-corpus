// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00584110
// Canonical corpus name: sub_584110
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_584110_00584110.c

void UnknownObject::accumulateAt0xE0()
{
    // Trivial thiscall accumulator: adds float argument a2 to the 8-byte field at offset 0xE0 of this (this[28] on a double-typed pointer) in place.
    // CALCULATION: Accumulate a2 into the field at offset 0xE0: this[28] = a2 + this[28]. [field:this:0x000000E0, source:raw]

    // Conservative worker pseudocode:
    //   this[0xE0] += a2;
    // UNRESOLVED: Owner class unknown; meaning of the float accumulator at offset 0xE0 not established. Single caller 0x00583D90 (StartAddress).
}
