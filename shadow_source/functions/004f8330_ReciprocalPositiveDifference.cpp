// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8330
// Canonical corpus name: ArithmeticComparison_8330
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_8330_004f8330.c

void UnknownObject::ReciprocalPositiveDifference()
{
    // Computes the reciprocal of a positive float difference: v1 = float(this+0x80) - float(this+0x84); writes 1.0/v1 to this+0x88 when v1 > 0.0, otherwise writes 0. Per-frame helper called from SuspensionAndWheelPhysics.
    // CALCULATION: v1 = *(float*)(this+128) - *(float*)(this+132), the difference between the minuend at this+0x80 and subtrahend at this+0x84. [field:this:0x00000080, field:this:0x00000084, source:raw]
    // GUARD: Branch on sign of v1: if v1 <= 0.0 take the zero-assignment path, else take the reciprocal path. [source:raw]
    // ASSIGNMENT: *(this+136) = 0 when v1 <= 0.0 (zero floor for non-positive difference). [field:this:0x00000088, source:raw]
    // ASSIGNMENT: *(float*)(this+136) = 1.0 / v1 when v1 > 0.0. [field:this:0x00000088, source:raw]

    // Conservative worker pseudocode:
    //   float diff = float_at(this, 0x80) - float_at(this, 0x84);
    //   if (diff <= 0.0f)
    //       dword_at(this, 0x88) = 0;
    //   else
    //       float_at(this, 0x88) = 1.0f / diff;
    // UNRESOLVED: Globals flt_59E43C / flt_59E440 are listed as read but do not appear in the raw source; their role here is unconfirmed.
    // UNRESOLVED: Semantic purpose (reciprocal distance/stiffness factor for suspension) is prose-only, not proven.
    // UNRESOLVED: this+0x88 is recalculated every frame, so an external poke does not persist.
}
