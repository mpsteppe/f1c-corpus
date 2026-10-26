// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049AA70
// Canonical corpus name: PositionUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PositionUpdate_0049aa70.c

void UnknownObject::UpdatePositionFromBaselines()
{
    // Positional offset accumulator: adds each caller parameter to a corresponding baseline struct field and stores the result in an adjacent output field. Reads baselines this+0x4 and this+0xC, writes computed this+0x8 = a3 + this+0x4 and this+0x10 = a2 + this+0xC, and returns the computed this+0x10 value.
    // CALCULATION: Read baseline v4 = this+0x4 (this[1]). [source:raw, field:this:0x00000004]
    // CALCULATION: Compute result = a2 + this+0xC (this[3]), the primary baseline plus incoming delta. [source:raw, field:this:0x0000000C]
    // ASSIGNMENT: Store a3 + v4 into this+0x8 (this[2]), the second computed output. [source:raw, field:this:0x00000008]
    // ASSIGNMENT: Store result into this+0x10 (this[4]), the first computed output. [source:raw, field:this:0x00000010]
    // RETURN: Return result, the computed primary output. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49AA70(int a2, int a3) {
    //     int result = a2 + this[3];
    //     this[4] = result;
    //     this[2] = a3 + this[1];
    //     return result;
    //   }
    // UNRESOLVED: Interpretation of fields as X/Y baseline and computed positions is DERIVED from existing analysis prose (PositionalOffsetAccumulator), not from the raw source.
    // UNRESOLVED: Owner class is unknown.
}
