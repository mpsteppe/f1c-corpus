// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2C80
// Canonical corpus name: VectorToShort3Conversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VectorToShort3Conversion_004b2c80.c

void UnknownObject::FloatVectorToInt16SaturationPackWithClassification()
{
    // Packs a 3D float vector (a2) into three signed 16-bit components written at this+0x9, this+0xB and this+0xD. Each component is scaled by 64.0 after passing through FloatToRGBColorConversion and ShortVectorToFloatWithScale, and is clamped: values within +/-511.98001 become the scaled integer, otherwise they saturate to -32767 or 0x7FFF. The vector then feeds ShortComputation_29f0/FloatThresholdClassification for a classification pass and BitfieldExtractScale/BitfieldUpdateFromFloat for a bitfield update whose result is returned. Invoked by EntityVisibilityGridManager (00465460).
    // CALCULATION: Stage the input vector into three locals: v14 = a2[0], v15 = a2[1], v16 = a2[2] [source:raw]
    // CALL: FloatToRGBColorConversion converts the staged float triple into a packed color-like value stored into the receiver [callee:0x004B21F0, source:raw]
    // CALL: ShortVectorToFloatWithScale rescales the short-vector interpretation of a2 back through the staging floats [callee:0x004B2580, source:raw]
    // CALCULATION: X component clamp-and-scale: if within +/-511.98001 multiply by 64.0 and truncate to int16, otherwise clamp to -32767 or 0x7FFF; write the word result to this+0x9 [field:this:0x00000009, source:raw]
    // CALCULATION: Y component clamp-and-scale: same +/-511.98001 / 64.0 / -32767 / 0x7FFF handling; write the word result to this+0xB [field:this:0x0000000B, source:raw]
    // CALCULATION: Z component clamp-and-scale: same +/-511.98001 / 64.0 / -32767 / 0x7FFF handling; write the word result to this+0xD [field:this:0x0000000D, source:raw]
    // CALL: ShortComputation_29f0 derives a classification input v12 from the input vector a2 [callee:0x004B29F0, source:raw]
    // CALL: FloatThresholdClassification classifies the receiver using the computed v12 value [callee:0x004B2B90, source:raw]
    // CALL: BitfieldExtractScale derives a scale/bitfield value v13 from a2 [callee:0x004B2980, source:raw]
    // RETURN: BitfieldUpdateFromFloat applies v13 to the receiver's bitfield and its return value is returned to the caller; the function is invoked by EntityVisibilityGridManager (00465460) [callee:0x004B2C20, caller:0x00465460, function:0x004B2C80, source:raw]

    // Conservative worker pseudocode:
    //   v14 = a2[0]; v15 = a2[1]; v16 = a2[2];
    //   FloatToRGBColorConversion(this, &v14);
    //   ShortVectorToFloatWithScale((__int16*)a2, &v14);
    //   this+0x9 = clamp_scale(v14);   // within +/-511.98001 ? (int)(v*64.0) : (v<0 ? -32767 : 0x7FFF)
    //   this+0xB = clamp_scale(v15);
    //   this+0xD = clamp_scale(v16);
    //   return BitfieldUpdateFromFloat(this, BitfieldExtractScale(a2))
    //     after FloatThresholdClassification(this, ShortComputation_29f0(a2));
    // UNRESOLVED: The three read-only globals (flt_59E708, flt_59E70C, flt_59E710) are flagged as read but never appear in the raw decompiled source; the skeleton fill labels them threshold constants (SoundVolumeLowThreshold, FFBMinThreshold, FFB_SaturationThreshold) which is not verifiable from this packet
    // UNRESOLVED: The exact semantics of FloatToRGBColorConversion and the threshold-classification chain relative to the int16 packing are not documented by the raw source
}
