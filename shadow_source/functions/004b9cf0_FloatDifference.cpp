// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9CF0
// Canonical corpus name: FloatDifference
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatDifference_004b9cf0.c

void UnknownObject::FloatDifference()
{
    // Computes the difference between a float obtained through the FloatGetter helper (0x004B8790) applied to the object pointed at by *this and a second float read at offset 3900 bytes from a register-derived base pointer v2. The decompiled body leaves v2 uninitialized, so the base for the 3900-byte field is a decompiler artifact and the source register is lost. Returns the difference as a double. Called by particle/weather update and scoring-gate paths.
    // CALL: Call FloatGetter(*this) to obtain the first float value, stored as double v1. [source:raw, callee:0x004B8790, field:this:0x00000000]
    // CALCULATION: Compute the difference v1 minus the float read from (v2 + 3900). [source:raw, abi:lead]
    // RETURN: Return the float difference widened to double. [source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   double FloatDifference(float **this) {
    //     double v1 = (double)FloatGetter(*this);
    //     return v1 - (double)(*(float *)(base + 3900));
    //   }
    // UNRESOLVED: v2 is uninitialized in the decompiled body; the base pointer for the 3900-byte float field is a register-derived value whose source was lost, so the field cannot be located or named.
    // UNRESOLVED: Which object the 3900-byte field belongs to (the same object as *this or another) is unknown.
    // UNRESOLVED: Semantic meaning of the two floats and their difference (particle/wind/weather context suggested by callers, unproven here).
}
