// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D5EE0
// Canonical corpus name: TireLoadFactorSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireLoadFactorSetter_004d5ee0.c

void UnknownObject::TireLoadFactorSetter()
{
    // Writes the four tire-load-factor doubles of the per-wheel tire state: average of the two load inputs (this[0] = (a2 + a3) * 0.5), half-difference (this[1] = (a2 - a3) * 0.5), the incoming load value itself (this[2] = a4) and its reciprocal (this[3] = 1.0 / a4). When a4 is not positive and the session is not the server type (dword_7C569C != 5), a source-path check via StringSplitLoop gates a DebugLogWrite of the "tire load factor" message into the debug buffer at dword_8AD25C. Returns the low dword of a4. Called per frame by TireCompoundPerWheelPhysicsApplication (0043DA10).
    // GUARD: Debug logging is gated on a4 <= 0.0, the session type at dword_7C569C being different from 5, and StringSplitLoop returning non-zero for the source path string aDDevF119992002_4 [callee:0x004D7A50, global:0x007C569C, global:0x005D45E4, source:raw]
    // CALL: Inside that guard, DebugLogWrite(&dword_8AD25C, aTireLoadFactor) emits the tire load factor message into the debug message buffer [callee:0x004D7AA0, global:0x008AD25C, global:0x005D45C0, source:raw]
    // ASSIGNMENT: this[0] = (a2 + a3) * 0.5 : stores the average of the two tire load inputs [field:this:0x00000000, source:raw]
    // ASSIGNMENT: this[1] = (a2 - a3) * 0.5 : stores the half-difference between the two tire load inputs [field:this:0x00000008, source:raw]
    // ASSIGNMENT: this[2] = a4 : stores the incoming tire load value unchanged [field:this:0x00000010, source:raw]
    // CALCULATION: this[3] = 1.0 / a4 : stores the reciprocal of the tire load [field:this:0x00000018, source:raw]
    // RETURN: Returns the low dword of a4 to the caller [source:raw]
    // CALL: Invoked per frame by TireCompoundPerWheelPhysicsApplication (0043DA10) as the tire load factor update step [caller:0x0043DA10, source:raw]

    // Conservative worker pseudocode:
    //   if (a4 <= 0.0 && dword_7C569C != 5 && StringSplitLoop(1, aDDevF119992002_4, 197))
    //     DebugLogWrite(&dword_8AD25C, aTireLoadFactor);
    //   this[0] = (a2 + a3) * 0.5;
    //   this[1] = (a2 - a3) * 0.5;
    //   this[2] = a4;
    //   this[3] = 1.0 / a4;
    //   return LODWORD(a4);
    // UNRESOLVED: Three read-only double globals (dbl_59E420, dbl_59E430, dbl_59E880) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them as the 1.0/0.0/0.5 constant literals, which cannot be tied to a specific source line from this packet
    // UNRESOLVED: The reciprocal division 1.0 / a4 has no zero-divisor guard in the raw source; a4 == 0.0 would produce a non-finite result whose handling is not visible
}
