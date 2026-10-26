// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D82D0
// Canonical corpus name: HUDFlagRendererMain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HUDFlagRendererMain_004d82d0.c

void UnknownObject::RenderHudFlags()
{
    // HUD flag render main. Collects race-flag bytes into a small buffer based on game-state checks, then renders them via sub_553070 with a white color override. Emits yellow (62), blue (65), black (63), pit (102), checkered (66) flags, plus driver-condition flags (130/-126, 68, -116, -115) when the display mode is 2. Skips rendering when dword_7CFEA0 is 0, when a conditional flag is set, when dword_8AB6E4 equals 2, or when this+0x8 (participant slot) is -1. Invoked by sub_4D8450.
    // GUARD: When dword_7CFEA0 (input display mode) is 0, return immediately with its LOW byte. [global:0x007CFEA0, source:raw]
    // GUARD: Bail out when ConditionalFlagReturn(&dword_5EA43C) is truthy, when dword_8AB6E4 equals 2, or when this+0x8 (participant slot) is not -1 (0xFFFFFFFF). [callee:0x00404F10, global:0x005EA43C, global:0x008AB6E4, field:this:0x00000008, guard:0, source:raw]
    // ASSIGNMENT: Initialize the flag buffer index v3 to 0. [source:raw]
    // ASSIGNMENT: When ShortComputation_bad0() is truthy, store yellow flag code 62 as the first buffer entry. [callee:0x0049BAD0, source:raw]
    // ASSIGNMENT: When VehicleFlagCheck() is truthy, append blue flag code 65. [callee:0x0049BB20, source:raw]
    // ASSIGNMENT: When DisqualificationCheck() is truthy, append black flag code 63. [callee:0x0049BAB0, source:raw]
    // ASSIGNMENT: When PitStateFlagCheck() is truthy, append pit flag code 102. [callee:0x0049BA90, source:raw]
    // GUARD: When dword_7C56A8 (race phase) equals 8, append checkered flag code 66. [global:0x007C56A8, source:raw]
    // GUARD: When dword_7CFEA0 equals 2, append the driver-condition flags: sub_49B9A0 contributes -126, FuelWeightComputation contributes 68, and sub_49BA30 selects -116 or -115. [global:0x007CFEA0, callee:0x0049B9A0, callee:0x0049BA50, callee:0x0049BA30, source:raw]
    // GUARD: When at least one flag was collected (v3 > 0), null-terminate the buffer at index v3. [source:raw]
    // CALL: When dword_8AD394 is non-null, preserve the floats at +92/+96, overwrite both with the constant 1069547520, call FieldSetterAt0x48(0xFFFFFF), render via sub_553070(v9, 10, 0, dword_8B8DC8), then restore the two floats. [global:0x008AD394, global:0x008B8DC8, callee:0x00552FC0, callee:0x00553070, source:raw]
    // RETURN: Return the last flag-selection value v1; the function is invoked by sub_4D8450. [caller:0x004D8450, function:0x004D82D0, source:raw]

    // Conservative worker pseudocode:
    //   if (!dword_7CFEA0) return 0;
    //   if (ConditionalFlagReturn(&dword_5EA43C) || dword_8AB6E4 == 2 || this[2] != -1) return;
    //   count = 0;
    //   if (ShortComputation_bad0()) buf[count++] = 62;
    //   if (VehicleFlagCheck()) buf[count++] = 65;
    //   if (DisqualificationCheck()) buf[count++] = 63;
    //   if (PitStateFlagCheck()) buf[count++] = 102;
    //   if (dword_7C56A8 == 8) buf[count++] = 66;
    //   if (dword_7CFEA0 == 2) {
    //     if (sub_49B9A0()) buf[count++] = -126;
    //     if (FuelWeightComputation()) buf[count++] = 68;
    //     r = sub_49BA30();
    //     if (r == 1) buf[count++] = -116;
    //     if (r == 2) buf[count++] = -115;
    //   }
    //   if (count > 0) {
    //     buf[count] = 0;
    //     if (dword_8AD394) {
    //       save floats at +92/+96; write 1069547520 to both;
    //       FieldSetterAt0x48(0xFFFFFF);
    //       sub_553070(buf, 10, 0, dword_8B8DC8);
    //       restore floats;
    //     }
    //   }
    //   return v1;
    // UNRESOLVED: global:0x007CE234 (unk_7CE234) is reported by the deterministic facts as referenced by this function but does not appear in the available raw body text; its role is unresolved.
    // UNRESOLVED: The exact identities of dword_7CFEA0 (input display mode), dword_8AB6E4 (scoring gate) and dword_7C56A8 (race phase) are DERIVED from the existing analysis, not from this packet alone.
    // UNRESOLVED: The constant 1069547520 overwrites two float fields at dword_8AD394 + 92/+96; it is written as a bit pattern and no float interpretation is asserted.
    // UNRESOLVED: this+0x8 (participant slot) semantics as a driver slot index are DERIVED from the existing analysis; the raw source only shows the != -1 comparison.
}
