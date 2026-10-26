// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DAE00
// Canonical corpus name: sub_4DAE00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DAE00_004dae00.c

void UnknownObject::RaceEndProgressionGate()
{
    // Race-end flow gate. Returns 1 (allow progression) when the short expiration timer at this+0x14 has elapsed (<= 0.0); returns 0 (block) while the hold timer at this+0x1C is still positive. Otherwise, when the current vehicle's finish state (dword_5F073C[4656 * currentIndex], reached through sub_4D1B50(dword_8ACEE0, 0)) equals 1 AND the finished-vehicle count at this+0x20 has reached the player's position threshold (dword_7C54E8 + 16480), the result is set from the player's DSQ/retired flag (dword_7C54E8 + 16484). Finally, if the finished count at this+0x20 equals the vehicle count dword_5C329C, progression is unconditionally allowed.
    // ASSIGNMENT: Initialize the return accumulator v2 to 0. [source:raw]
    // GUARD: When the float at this+0x14 is <= 0.0 (short expiration timer elapsed), return 1 immediately (allow progression). [field:this:0x00000014, source:raw]
    // GUARD: When the float at this+0x1C is > 0.0 (hold timer still running), return v2, i.e. block progression. [field:this:0x0000001C, source:raw]
    // CALL: Resolve the current vehicle index: sub_4D1B50((unsigned __int8*)dword_8ACEE0, 0). [callee:0x004D1B50, global:0x008ACEE0, source:raw]
    // GUARD: When dword_5F073C[4656 * currentIndex] == 1 (current vehicle finished) AND the dword at this+0x20 >= the dword at dword_7C54E8 + 16480, set v2 to (dword at dword_7C54E8 + 16484 != 0) (player DSQ/retired flag). [global:0x005F073C, global:0x007C54E8, field:this:0x00000020, source:raw]
    // RETURN: result preset to 1; if the dword at this+0x20 != dword_5C329C (finished count != vehicle count) return v2, otherwise return 1 (unconditional progression). [field:this:0x00000020, global:0x005C329C, source:raw]

    // Conservative worker pseudocode:
    //   char sub_4DAE00(int this) {
    //     if (*(float*)(this + 0x14) <= 0.0f) return 1;
    //     if (*(float*)(this + 0x1C) > 0.0f) return 0;
    //     bool v2 = 0;
    //     int idx = sub_4D1B50((unsigned __int8*)dword_8ACEE0, 0);
    //     if (dword_5F073C[4656 * idx] == 1 && *(int*)(this + 0x20) >= *(int*)(dword_7C54E8 + 0x4060))
    //       v2 = *(int*)(dword_7C54E8 + 0x4064) != 0;
    //     if (*(int*)(this + 0x20) != dword_5C329C) return v2;
    //     return 1;
    //   }
    // UNRESOLVED: flt_59E440 is flagged as a read global for this function but does not appear in the decompiled body; the existing analysis labels it a zero threshold (~0.0f, physics clamp) [DERIVED], which is unverified here.
    // UNRESOLVED: Caller sub_4DA840 is recorded; frame-path membership is NOT_FOUND.
    // UNRESOLVED: The concrete semantics of the offsets dword_7C54E8 + 16480 / +16484 and of dword_5F073C[4656 * index] (finish state) rest on the existing analysis; no independent runtime evidence.
}
