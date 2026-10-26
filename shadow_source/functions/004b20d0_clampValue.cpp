// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B20D0
// Canonical corpus name: ArithmeticComparison_20d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_20d0_004b20d0.c

void UnknownObject::clampValue()
{
    // Clamp setter: stores an argument into field this+0x14 and clamps it to the inclusive range [this+0x1C, this+0x20], returning the lower bound.
    // ASSIGNMENT: Store argument a2 into field this+0x14 (element [5]). [field:this:0x00000014, source:raw]
    // GUARD: Branch on whether stored value this+0x14 is below the lower bound this+0x1C (element [7]). [field:this:0x00000014, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Low clamp: when below the bound, set this+0x14 to this+0x1C. [field:this:0x00000014, field:this:0x0000001C, source:raw]
    // GUARD: Branch on whether stored value this+0x14 exceeds the upper bound this+0x20 (element [8]). [field:this:0x00000014, field:this:0x00000020, source:raw]
    // ASSIGNMENT: High clamp: when above the bound, set this+0x14 to this+0x20. [field:this:0x00000014, field:this:0x00000020, source:raw]
    // RETURN: Return the lower bound value read from this+0x1C. [field:this:0x0000001C, source:raw]

    // Conservative worker pseudocode:
    //   value = a2;
    //   if (value < low) value = low;
    //   else if (value > high) value = high;
    //   return low;
    // UNRESOLVED: Object identity unknown; callers are vehicle setup paths (DrivingModeParameterSetup, CarPartVisibilityController, PhysicsParameterInitialization) but class is not established.
    // UNRESOLVED: Semantic meaning of fields this+0x14, this+0x1C, this+0x20 unknown.
    // UNRESOLVED: Structural twin relation to 004b1de0 is DERIVED, not independently verified.
}
