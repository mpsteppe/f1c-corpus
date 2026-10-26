// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004636A0
// Canonical corpus name: CollisionThresholdCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionThresholdCheck_004636a0.c

void UnknownObject::CollisionThresholdCheck()
{
    // Reads a float value through this+0x0 (dereferenced pointer +0x388) and compares it against a threshold chosen by state: 20.0 when StateCheckWrapper(this) returns true, otherwise 1.25. Returns true when the value is strictly greater than the threshold, false when it is less than or equal.
    // CALL: Call StateCheckWrapper(this) to determine which threshold applies; branch on the boolean result. [callee:0x00461DC0, source:raw]
    // GUARD: Guard on StateCheckWrapper(this): true selects the 20.0 threshold, false selects the 1.25 threshold. [source:raw]
    // CALCULATION: Read the float value at obj+0x388, where obj is the pointer stored at this+0x0. [field:obj:0x00000388, field:this:0x00000000, source:raw]
    // CALCULATION: Compare the value against the selected threshold, recording strict-less-than and equality flags. [source:raw]
    // RETURN: Return the negation of (value < threshold OR value == threshold), i.e. true when value > threshold. [source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_4636A0(void *this) {
    //     double v = *(float *)(*(_DWORD *)this + 904);
    //     double threshold = StateCheckWrapper(this) ? 20.0 : 1.25;
    //     return v > threshold;
    //   }
    // UNRESOLVED: The exact meaning of the compared value at +0x388 (collision-related quantity) is not established by the evidence.
    // UNRESOLVED: Which object state StateCheckWrapper tests to select the threshold is unknown.
    // UNRESOLVED: The DERIVED global names (SpeedDeadzone flt_59E8EC, UILayoutOffset flt_59F124) are not used directly by this function's code path.
}
