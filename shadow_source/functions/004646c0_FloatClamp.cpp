// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004646C0
// Canonical corpus name: FloatClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatClamp_004646c0.c

void UnknownObject::FloatClamp()
{
    // Clamps the float value stored at this->offset 0 into the inclusive range [a2, a3]: below a2 sets it to a2, above a3 sets it to a3, otherwise unchanged.
    // GUARD: Checks whether *this is below the lower bound a2 to select the lower-clamp path. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Sets *this to a2 when the value is below the lower bound. [field:this:0x00000000, source:raw]
    // GUARD: When not below the lower bound, checks whether *this is above the upper bound a3 to select the upper-clamp path. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Sets *this to a3 when the value is above the upper bound. [field:this:0x00000000, source:raw]
    // RETURN: Void return; the value is left unchanged when it already lies within [a2, a3]. [source:raw]

    // Conservative worker pseudocode:
    //   if (*this < a2) { *this = a2; } else if (*this > a3) { *this = a3; }
}
