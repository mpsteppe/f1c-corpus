// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406060
// Canonical corpus name: DotProductWithScaleOffset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DotProductWithScaleOffset_00406060.c

void UnknownObject::DotProductWithScaleOffset()
{
    // Computes a pan/balance factor from the dot product of a stored 3-component vector (sub-struct at this[21], components at +112/+116/+120) against a caller-supplied float vector a2, then scales and biases it as (dot * 0.60000002 + 1.0) * 0.5, producing a result in the [0.2, 0.8] range. Used by the 3D sound positioning update.
    // CALCULATION: Load the sub-struct pointer at this[21] (field this+0x54); its vector components are read from sub-struct +112/+116/+120 (fields this+0xC4/+0xC8/+0xCC). [field:this:0x00000054, field:this:0x000000C4, field:this:0x000000C8, field:this:0x000000CC, source:raw]
    // CALCULATION: Compute the dot product of the stored vector components (+112/+116/+120) against the input vector a2. [field:this:0x000000C4, field:this:0x000000C8, field:this:0x000000CC, source:raw]
    // CALCULATION: Scale and bias the dot product: (dot * 0.60000002 + 1.0) * 0.5, mapping the result to the [0.2, 0.8] output range. [source:raw]
    // RETURN: Return the scaled and bias-adjusted value as a double. [source:raw]
    // CALL: Called by F_3DSoundPositioningUpdate (0x00405B90) to compute the stereo pan/balance factor. [caller:0x00405B90, source:raw]

    // Conservative worker pseudocode:
    //   double sub_406060(int* this_, float* a2) {
    //     float* v = (float*)(this_[21] + 112);
    //     double dot = (double)(v[0] * a2[0] + v[1] * a2[1] + v[2] * a2[2]);
    //     return (dot * 0.60000002 + 1.0) * 0.5;
    //   }
    // UNRESOLVED: The three float globals flt_59E43C / flt_59E450 / flt_59E4E8 are not referenced by the raw source; they may back the scale literals (0.60000002, 1.0, 0.5) but this mapping is unproven.
    // UNRESOLVED: The exact meaning of the stored vector and of the caller-supplied a2 vector depends on the 3D sound positioning caller; the [0.2, 0.8] pan range is a DERIVED interpretation.
}
