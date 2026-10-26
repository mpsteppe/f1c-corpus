// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FE060
// Canonical corpus name: CarPositionTargetCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CarPositionTargetCheck_004fe060.c

void UnknownObject::CarPositionTargetCheck()
{
    // Checks the car's current position (this+0x8) against a target computed by sub_4FC910 from this+0x20 and a2. Sets the match flag this+0x4 to 2.0f (0x40000000) when |current - target| <= 0.5, else to 0, then runs RangeInterpolationTable on this. The whole evaluation is skipped in multiplayer sessions unless the scoring gate is active and its packed flag is clear.
    // GUARD: Execute the check only when the multiplayer flag dword_7C56A0 has bit 0 clear, or when the scoring gate dword_8AB6E4 equals 2 and PackedFlagRead_9a00 on dword_8AB6EC reports the flag unset. [callee:0x004B9A00, global:0x007C56A0, global:0x008AB6E4, global:0x008AB6EC, source:raw]
    // CALL: Call sub_4FC910 with a float pointer at this+0x20 and argument a2 to compute the target value. [callee:0x004FC910, source:raw]
    // CALCULATION: Tolerance test: fabs(value at this+8 minus the computed target) <= 0.5. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: On a match, set this+0x4 to 0x40000000 (2.0f). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: On no match, set this+0x4 to 0. [field:this:0x00000004, source:raw]
    // CALL: Call RangeInterpolationTable (0x004FD6F0) on this as a float pointer after the flag is set. [callee:0x004FD6F0, source:raw]
    // CALL: Invoked by sub_4B3400 (0x004B3400), the only known caller. [caller:0x004B3400]

    // Conservative worker pseudocode:
    //   void CarPositionTargetCheck(int self, int a2) {
    //     if (!(dword_7C56A0 & 1) || (dword_8AB6E4 == 2 && !PackedFlagRead_9a00(&dword_8AB6EC))) {
    //       sub_4FC910((float *)(self + 0x20), a2);
    //       if (fabs(*(float *)(self + 0x8) - target) <= 0.5f)
    //         *(int *)(self + 0x4) = 0x40000000; /* 2.0f * /
    //       else
    //         *(int *)(self + 0x4) = 0;
    //       RangeInterpolationTable((float *)self);
    //     }
    //   }
    // UNRESOLVED: Global flt_59E450 (0x0059E450) is attributed to this function by static facts but does not appear in the raw source; its role (possibly a degrees-to-radians constant) is unconfirmed.
    // UNRESOLVED: The raw source reads *v3 in the tolerance test, but v3 is an uninitialized float pointer in the Hex-Rays output; the concrete source of the target value is not explicit.
    // UNRESOLVED: The owning object is unidentified; this+0x4 (match flag), this+0x8 (current position) and this+0x20 (target-computation input) semantics rest only on the legacy ABI lead Car_Position_Target_Check.
}
