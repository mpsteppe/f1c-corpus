// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1DE0
// Canonical corpus name: ClampedFloatSetter_1de0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClampedFloatSetter_1de0_004b1de0.c

void UnknownObject::ClampedFloatSetter()
{
    // Stores a caller-supplied float value (bitcast from integer a2) at this+0x14 and clamps it into the interval bounded by this+0x1C (lower bound) and this+0x20 (upper bound): when the stored value exceeds the upper bound it is overwritten with the upper bound, and when it falls below the lower bound it is overwritten with the lower bound.
    // ASSIGNMENT: Read the lower bound from this+0x1C and the upper bound from this+0x20 as floats into locals v2 and v3. [field:this:0x0000001C, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Write the integer argument a2 (bitcast to float) into the destination field at this+0x14. [field:this:0x00000014, source:raw]
    // GUARD: When the stored value at this+0x14 is greater than the upper bound (v3), clamp it to the upper bound. [field:this:0x00000014, field:this:0x00000020, source:raw]
    // GUARD: When the stored value at this+0x14 is below the lower bound (v2), clamp it to the lower bound. [field:this:0x00000014, field:this:0x0000001C, source:raw]

    // Conservative worker pseudocode:
    //   lower = *(float*)(this + 0x1C);
    //   upper = *(float*)(this + 0x20);
    //   *(float*)(this + 0x14) = *(float*)&a2;
    //   if (*(float*)(this + 0x14) > upper) *(float*)(this + 0x14) = upper;
    //   if (*(float*)(this + 0x14) < lower) *(float*)(this + 0x14) = lower;
    // UNRESOLVED: The owning object is unknown; callers DrivingModeParameterSetup (0x004ADF10), sub_4AE9F0 (0x004AE9F0) and PhysicsParameterInitialization (0x004AF3A0) show this runs during vehicle parameter setup but not which class owns this+0x14.
    // UNRESOLVED: The float interpretation of the integer argument a2 is implied by the decompiler's _DWORD write into a float-typed field.
    // UNRESOLVED: The legacy ABI label Clamped_Float_Setter_4b1de0 (abi:lead) is not adopted as an independent owner claim.
}
