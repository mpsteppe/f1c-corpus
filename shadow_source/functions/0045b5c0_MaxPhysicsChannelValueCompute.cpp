// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045B5C0
// Canonical corpus name: sub_45B5C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_45B5C0_0045b5c0.c

void UnknownObject::MaxPhysicsChannelValueCompute()
{
    // Computes the maximum normalized coordinate value across the active physics channels. Reads the channel count via FloatArrayThresholdSearch, iterates over that many active channels resolving each flat index via FindActivePhysicsChannelByIndex, reads the two input fields via DoubleFieldGetterAt0x300x34, computes the normalized coordinate at offset 92*v3 + this + 60 via NormalizedCoordinateCalculator, and keeps the largest result. Returns 0.0 when the count is not positive.
    // ASSIGNMENT: Initialize the running maximum v5 to 0.0 before the loop. [source:raw]
    // CALL: Obtain the number of channels to process from FloatArrayThresholdSearch. [callee:0x0045BB00, source:raw]
    // GUARD: When the channel count is not greater than 0, skip the loop entirely and return the zero-initialized maximum. [source:raw]
    // LOOP: Iterate over the channel count with an ascending index v2 from 0 while v2 is less than the count. [source:raw]
    // CALL: Resolve the flat index of the v2-th active physics channel via FindActivePhysicsChannelByIndex. [callee:0x0045B580, source:raw]
    // CALL: Read the two field values used as inputs for the normalized-coordinate computation via DoubleFieldGetterAt0x300x34. [callee:0x00456040, source:raw]
    // CALL: Compute the normalized coordinate for the channel at offset 92*v3 + this + 60 via NormalizedCoordinateCalculator. [callee:0x004DD400, source:raw]
    // CALCULATION: Compare the computed value against the running maximum and keep the larger of the two. [source:raw]
    // RETURN: Return the maximum normalized coordinate value found (or 0.0 when no channels were processed). [function:0x0045B5C0, source:raw]

    // Conservative worker pseudocode:
    //   double sub_45B5C0(int this) {
    //     int idx = 0;
    //     float max = 0.0f;
    //     int count = FloatArrayThresholdSearch();
    //     if (count > 0) {
    //       do {
    //         int ch = FindActivePhysicsChannelByIndex((float*)this, idx);
    //         float out = 0.0f;
    //         DoubleFieldGetterAt0x300x34((this + 4), &in1, &in2);
    //         NormalizedCoordinateCalculator(92 * ch + this + 60, in1, in2, &out, 0, 0);
    //         if (out > max) max = out;
    //         ++idx;
    //       } while (idx < count);
    //     }
    //     return max;
    //   }
    // UNRESOLVED: The exact meaning of the normalized coordinate and the 92-byte channel stride at this + 60 depend on the physics-channel layout, which is not established in this function.
    // UNRESOLVED: The two field values read from this + 4 are not tied to named fields here.
    // UNRESOLVED: The unused zero parameters of NormalizedCoordinateCalculator are of unknown meaning.
}
