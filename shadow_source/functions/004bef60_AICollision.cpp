// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BEF60
// Canonical corpus name: AICollision
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AICollision_004bef60.c

void UnknownObject::AICollision()
{
    // AI collision-state check. Returns 0 (no collision) immediately when the global session type dword_7C56A4 is not the qualifying mode (7). Otherwise verifies four consecutive wheel-contact entries (stride 296 from a2+2100): if any entry's dword is null or its byte at +64 is clear it returns 1. Returns 2 when the vehicle state at a2+15724 equals 2. In engine-wear mode 3 (dword_7CEA5C) it resolves the outcome through DriverSetupParamLookupByID on the setup parameter at a2+16444. Otherwise two probabilistic response checks (gated by byte flags this+0x340 and this+0x341, using divider this+0x35C and multiplier this+0x344) draw successive samples from the flt_8AAE74 trig-lookup table indexed by the incrementing byte counter dword_8AAE70 and map threshold crosses to result 1 or 2.
    // GUARD: Return 0 when the global session type dword_7C56A4 is not 7 (the qualifying-session mode); the whole collision check is skipped otherwise. [global:0x007C56A4, source:raw]
    // LOOP: Iterate the four wheel-contact entries beginning at a2+2100 with stride 296: if any entry's first dword is null or its byte at +64 is clear (wheel missing/not in contact), return 1 immediately. [source:raw]
    // GUARD: Return 2 when the vehicle state dword at a2+15724 equals 2 (a fixed collision-severity state). [source:raw]
    // CALL: In engine-wear mode 3 (dword_7CEA5C), resolve the outcome through DriverSetupParamLookupByID(a2, setup param at a2+16444): return 0 when the looked-up value is -1 or lower, otherwise return 2. [callee:0x0042AEB0, global:0x007CEA5C, source:raw]
    // CALCULATION: Primary probabilistic check when byte flag this+0x340 is set: compute threshold v7 = (speed float at a2+17616) * 0.0099999998 / (double)this+0x35C * a3, draw a sample from the flt_8AAE74 lookup at the byte-indexed position dword_8AAE70++ (post-increment), and set v3 = 1 when the sample is at or below the threshold. [field:this:0x00000340, field:this:0x0000035C, global:0x008AAE70, global:0x008AAE74, source:raw]
    // CALCULATION: Secondary probabilistic check when byte flag this+0x341 is set and v3 is not already 1: compute threshold v9 = (1.0 - (wear float at a2+17628) * 0.0099999998) / (double)this+0x35C * a3 * (float)this+0x344, draw the next sample from flt_8AAE74 via dword_8AAE70++, and return 2 when the sample is at or below the threshold. [field:this:0x00000341, field:this:0x00000344, field:this:0x0000035C, global:0x008AAE70, global:0x008AAE74, source:raw]
    // RETURN: Return v3, the accumulated outcome: 0 (no collision), 1 (wheel/missing or primary threshold crossed), or 2 (state-based or secondary threshold crossed). [source:raw]
    // CALL: Invoked from EngineFailureCheck (0x004BEC55). [caller:0x004BEC55, source:raw]

    // Conservative worker pseudocode:
    //   int AICollision(int this, int a2, float a3) {
    //     int v3 = 0;
    //     if (dword_7C56A4 != 7) return 0;
    //     for (int i = 0; i < 4; i++) {
    //       int entry = a2 + 2100 + 296 * i;
    //       if (!*(int*)entry || !*(char*)(entry + 64)) return 1;
    //     }
    //     if (*(int*)(a2 + 15724) == 2) return 2;
    //     if (dword_7CEA5C == 3)
    //       return DriverSetupParamLookupByID((int*)a2, *(int*)(a2 + 16444)) <= -1 ? 0 : 2;
    //     if (*(char*)(this + 0x340)) {
    //       double t = *(float*)(a2 + 17616) * 0.0099999998 / (double)*(int*)(this + 0x35C) * a3;
    //       if (flt_8AAE74[(unsigned char)dword_8AAE70++] <= t) v3 = 1;
    //     }
    //     if (*(char*)(this + 0x341) && v3 != 1) {
    //       double t = (1.0 - *(float*)(a2 + 17628) * 0.0099999998) / (double)*(int*)(this + 0x35C)
    //                  * a3 * *(float*)(this + 0x344);
    //       if (flt_8AAE74[(unsigned char)dword_8AAE70++] <= t) return 2;
    //     }
    //     return v3;
    //   }
    // UNRESOLVED: The globals flt_59E43C and flt_59E444 are listed in the packet as reads but do not appear in the raw body; their role is unknown (the existing analysis associates 0x59E43C with a contact-aging threshold and 0x59E444 with the 1/60 frame delta, both DERIVED and unverified).
    // UNRESOLVED: The literal 0.0099999998 is left verbatim as the float 0.01f spelling; whether the two checks intend percent-based wear/speed probabilities is DERIVED, not locked by the packet.
    // UNRESOLVED: The array at a2+2100 (four 296-byte entries, byte flag at +64) is treated as the wheel-contact table from the existing analysis; the element type is not confirmed here.
    // UNRESOLVED: The trig-lookup interpretation of flt_8AAE74 is DERIVED from existing analysis; the packet only evidences a lookup indexed by the incrementing byte counter dword_8AAE70.
}
