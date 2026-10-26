// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC240
// Canonical corpus name: sub_4BC240
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BC240_004bc240.c

void UnknownObject::RacingLineResetGuard()
{
    // Per-frame state guard on a vehicle/object. When the session type global is not qualifying (7), reads the object pointer at this+0, checks a flag byte at obj+0x344C, and if it is set resets the racing-line mode at this+0x60 from 2 to 1. Returns the object pointer. Called by sub_4A5EA0 and LapCompletion (004BC4E0) on the frame path.
    // GUARD: Gate the whole body on the session-type global dword_7C56A4 != 7 (qualifying session); body is skipped when the value equals 7. [global:0x007C56A4, source:raw]
    // ASSIGNMENT: result = *this: read the object pointer stored at this+0. [field:this:0x00000000, source:raw]
    // GUARD: Check the object flag byte at obj+0x344C (obj = *this) for non-zero before any mode change. [field:obj:0x0000344C, source:raw]
    // GUARD: Compare the racing-line mode flag this+0x60 (this[24]) with 2; the reset happens only on equality. [guard:0, field:this:0x00000060, source:raw]
    // ASSIGNMENT: When the flag byte is set and mode equals 2, write 1 to this+0x60 (this[24] = 1). [field:this:0x00000060, source:raw]
    // RETURN: Return the object pointer captured at the start (uninitialized result is returned only when the outer guard fails). [field:this:0x00000000, source:raw]
    // CALL: Invoked per frame by sub_4A5EA0 and LapCompletion (004BC4E0). [caller:0x004A5EA0, caller:0x004BC4E0, function:0x004BC240]

    // Conservative worker pseudocode:
    //   int sub_4BC240(void *this) {
    //     if (dword_7C56A4 == 7) return uninitialized;
    //     int result = *(int*)this;
    //     if (*(unsigned char*)(result + 0x344C) != 0) {
    //       if (((int*)this)[24] == 2) ((int*)this)[24] = 1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the flag byte at obj+0x344C is not documented here; only that non-zero enables the mode reset.
    // UNRESOLVED: The exact semantics of the racing-line mode values 1 and 2 at this+0x60 are inferred from the surrounding analysis, not proven.
    // UNRESOLVED: The object type behind 'this' and the target of *this are unknown.
    // UNRESOLVED: Returning an uninitialized result when the outer guard fails is a decompiler artifact and is not meaningful.
}
