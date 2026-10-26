// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456FB0
// Canonical corpus name: ClampedFloatSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClampedFloatSetter_00456fb0.c

void UnknownObject::setClampedFloat()
{
    // Writes a2 into the float field at this+0xAC, clamped to the inclusive range bounded by the floats at this+0x80 (min) and this+0x84 (max): values below min are replaced by min, values above max by max, in-range values pass through. Called by CameraPositionDefinitions (0x00408870) and CollisionCoefficientApplication (0x00456F70).
    // ASSIGNMENT: Write a2 into the float field at this+0xAC. [field:this:0x000000AC, source:raw]
    // GUARD: If a2 < bound at this+0x80, replace the field at this+0xAC with that lower bound. [field:this:0x00000080, field:this:0x000000AC, source:raw]
    // GUARD: Else if a2 > bound at this+0x84, replace the field at this+0xAC with that upper bound. [field:this:0x00000084, field:this:0x000000AC, source:raw]
    // RETURN: Return after the clamp. [function:0x00456FB0]

    // Conservative worker pseudocode:
    //   float min = *(float*)(this + 0x80);
    //   float max = *(float*)(this + 0x84);
    //   *(float*)(this + 0xAC) = a2;
    //   if (*(float*)(this + 0xAC) < min) *(float*)(this + 0xAC) = min;
    //   else if (*(float*)(this + 0xAC) > max) *(float*)(this + 0xAC) = max;
    // UNRESOLVED: Object type owning offsets 0x80/0x84/0xAC is unknown; the meaning of the clamped quantity and its bounds is not determinable from this function alone.
}
