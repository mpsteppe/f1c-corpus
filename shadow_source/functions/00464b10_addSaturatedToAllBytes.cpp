// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464B10
// Canonical corpus name: sub_464B10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_464B10_00464b10.c

void UnknownObject::addSaturatedToAllBytes()
{
    // Iterates 104 byte elements of the this array, applying SaturatedByteAdd(&this[i], a2) to each and keeping the last result as the return value. Only known caller is FloatFractionFromInt (0x00464EF0).
    // LOOP: Loop i from 0 to 103, exactly 104 iterations over the byte array this. [source:raw]
    // CALL: Call SaturatedByteAdd(&this[i], a2) for each element and store the result. [callee:0x00464A10, source:raw]
    // RETURN: Return the result of the last SaturatedByteAdd call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_464B10(_BYTE* this, int a2) {
    //     int result;
    //     for (int i = 0; i < 104; ++i)
    //       result = SaturatedByteAdd(&this[i], a2);
    //     return result;
    //   }
    // UNRESOLVED: Whether this is a 104-entry array of independent per-element flags or a packed byte block is unknown; 104 matches the engine's vehicle slot count but no packet evidence links them.
    // UNRESOLVED: Saturation semantics and exact byte type produced by SaturatedByteAdd (0x00464A10) live in that callee.
}
