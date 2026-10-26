// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004319DA
// Canonical corpus name: TimeFormatStringForDebugDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimeFormatStringForDebugDisplay_004319da.c

void UnknownObject::TimeFormatStringForDebugDisplay()
{
    // Formats a raw time value into a debug display string with a unit suffix via StringFormatWithBufferOverflowCheck. Combines register inputs (LOBYTE(_EAX) = BYTE1(_ECX) + _EAX); when the high bit (_EAX & 0x80) of the result is set it increments a dword counter at a3 + 1149962476, indexes a float lookup table inside _ECX (base offset 1CD8h, element index (_EAX & 0xC) * 4), scales that value by dbl_59EA20 and points v7 at the unit-suffix string (_ECX + 24). If the dword at _ECX + 4 equals 1 the scaled value is formatted with "%.2f %s" (a2fS at 0x005C3820) and returned; otherwise the value is scaled by dbl_59EA18 and formatted with "%.3f %s" (a3fS at 0x005C3780).
    // CALCULATION: Combine incoming register bytes: LOBYTE(_EAX) = BYTE1(_ECX) + _EAX. [source:raw, function:0x004319DA]
    // GUARD: If (_EAX & 0x80) is nonzero (high bit set), take the alternate lookup-and-scale path. [source:raw]
    // CALCULATION: Increment the dword counter at a3 + 1149962476. [source:raw]
    // CALCULATION: Mask the accumulator to (_EAX & 0xC) and load a float from the lookup table at _ECX + (_EAX & 0xC) * 4 + 1CD8h. [source:raw]
    // CALCULATION: Multiply the lookup-table value by dbl_59EA20 (0x0059EA20). [source:raw, global:0x0059EA20]
    // ASSIGNMENT: Set v7 = (const char *)(_ECX + 24), the unit-suffix string pointer. [source:raw]
    // GUARD: If *(_DWORD *)(_ECX + 4) equals 1, select the two-decimal format path. [source:raw]
    // CALL: Call StringFormatWithBufferOverflowCheck(a5, "%.2f %s", scaled value, v7) using the two-decimal format string (a2fS at 0x005C3820). [callee:0x0058815F, global:0x005C3820, source:raw]
    // RETURN: Return the formatted string produced by the two-decimal path. [source:raw]
    // CALCULATION: Multiply the pending time value by dbl_59EA18 (0x0059EA18). [source:raw, global:0x0059EA18]
    // CALL: Call StringFormatWithBufferOverflowCheck(a5, "%.3f %s", scaled value, v7) using the three-decimal format string (a3fS at 0x005C3780). [callee:0x0058815F, global:0x005C3780, source:raw]
    // RETURN: Return the formatted string produced by the three-decimal path. [source:raw]

    // Conservative worker pseudocode:
    //   LOBYTE(_EAX) = BYTE1(_ECX) + _EAX;
    //   if ((_EAX & 0x80) != 0) {
    //       ++*(_DWORD *)(a3 + 1149962476);
    //       _EAX &= 0xC;
    //       // load float at _ECX + (_EAX * 4) + 1CD8h, scale by dbl_59EA20
    //       v7 = (const char *)(_ECX + 24);
    //       if (*(_DWORD *)(_ECX + 4) == 1)
    //           return StringFormatWithBufferOverflowCheck(a5, "%.2f %s", <scaled>, v7);
    //       // reload <scaled>
    //   }
    //   // scale <pending> by dbl_59EA18
    //   return StringFormatWithBufferOverflowCheck(a5, "%.3f %s", <scaled value>, v7);
    // UNRESOLVED: v7 (unit-suffix pointer) is only assigned inside the 0x80-set branch; the fallthrough path formats with it per Hex-Rays, whose stack view shows it uninitialized there.
    // UNRESOLVED: The 1149962476 increment offset is a Hex-Rays artifact of an unknown base address; the exact target offset is unconfirmed.
    // UNRESOLVED: When the 0x80 branch's field check (_ECX + 4 == 1) fails, Hex-Rays reloads the already-scaled value and scales it again by dbl_59EA18 before the three-decimal format; the intended math is unclear.
    // UNRESOLVED: Purpose and scale of the float lookup table at _ECX + (_EAX & 0xC) * 4 + 1CD8h are unknown.
    // UNRESOLVED: Semantics of the register byte arithmetic BYTE1(_ECX) + _EAX are unclear.
    // UNRESOLVED: Meaning of the value at _ECX + 4 (1 = two-decimal selector) is unknown.
    // UNRESOLVED: Parameter a4 is unused in the decompiled body.
}
