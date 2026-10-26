// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C88A0
// Canonical corpus name: ConditionalRatioCompute
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalRatioCompute_004c88a0.c

void UnknownObject::ConditionalRatioCompute()
{
    // Conditionally computes a ratio into a struct. When the enable byte this+0x10 is non-zero, the global pointer dword_8AC4C8 is non-null, and the mixer level *(dword_8AC4C8+4) is >= 0.0, it sets the state field this+0x14 to 2 and writes the ratio field this+0x18: the constant flt_7CF380 when the argument a2 is <= 0.0, otherwise *(dword_8AC4C8+4)/a2. When any guard fails the function does nothing. Called by sub_4F9480 (0x004F9480).
    // GUARD: Guard: proceed only when byte this+0x10 is non-zero, dword_8AC4C8 is non-null, and *(dword_8AC4C8+4) >= 0.0. [field:this:0x00000010, global:0x008AC4C8, source:raw]
    // ASSIGNMENT: Write the state field this+0x14 = 2. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Branch a2 <= 0.0: write the ratio field this+0x18 = flt_7CF380. [field:this:0x00000018, global:0x007CF380, source:raw]
    // CALCULATION: Else (a2 > 0.0): write the ratio field this+0x18 = *(dword_8AC4C8+4) / a2. [field:this:0x00000018, global:0x008AC4C8, source:raw]

    // Conservative worker pseudocode:
    //   if (this->enable && dword_8AC4C8 && *(float*)(dword_8AC4C8 + 4) >= 0.0f) {
    //       this->state = 2;
    //       this->ratio = (a2 <= 0.0f) ? flt_7CF380 : (*(float*)(dword_8AC4C8 + 4) / a2);
    //   }
    // UNRESOLVED: Semantic roles of the three globals (flt_7CF380 constant, dword_8AC4C8 mixer pointer with level at +4) and the meaning of the literal 2 written to this+0x14 are inferred, not confirmed.
    // UNRESOLVED: The argument a2 is read as the ratio denominator (scaling factor); its origin and units are unresolved.
    // UNRESOLVED: Packet global flt_59E440 is listed but not referenced by the raw source; its role is unresolved.
}
