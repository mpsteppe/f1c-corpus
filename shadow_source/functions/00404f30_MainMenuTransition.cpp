// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404F30
// Canonical corpus name: MainMenuTransition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MainMenuTransition_00404f30.c

void UnknownObject::MainMenuTransition()
{
    // Main-menu transition/restore handler. Enters the session critical section and makes a system OS API call on the session data object unk_7CE24C, then conditionally dispatches the Main Menu scene lookup when ConditionalFlagReturn reports true. If the object header reached from this has its byte activation flag at +0x14 set and the dword at +0x20 equals 1, restores previously saved global values from obj+0x50 and obj+0x54 (the latter clamped into a range bounded by two globals), resets a flag, runs a zero-guarded division, and conditionally resets virtual dispatch state.
    // CALL: Enter the session critical section: sub_4A0250(&unk_7CE24C) acquires the lock on the session data object. [callee:0x004A0250, global:0x007CE24C, source:raw]
    // CALL: SystemOSAPICall(&unk_7CE24C) invokes the system OS API with the session data object. [callee:0x004A03F0, global:0x007CE24C, source:raw]
    // GUARD: Proceeds to the menu dispatch only when ConditionalFlagReturn(this) returns non-zero. [callee:0x00404F10, source:raw]
    // CALL: LookupDispatch(aMainMenu, -1) dispatches the 'Main Menu' scene lookup with key -1. [callee:0x00497940, global:0x005BE708, source:raw]
    // CALCULATION: v3 = *(this): dereference the object pointer stored at this+0x0 into v3. [field:this:0x00000000, source:raw]
    // GUARD: Run the restore path only when the byte activation flag at obj+0x14 is non-zero AND the dword at obj+0x20 equals 1 (guard:0). [field:obj:0x00000014, field:obj:0x00000020, guard:0, source:raw]
    // ASSIGNMENT: dword_7D2E44 = v3[20]: restore the saved value read from obj+0x50 into global dword_7D2E44. [field:obj:0x00000050, source:raw]
    // ASSIGNMENT: v1 = v3[21]; dword_7D0410 = v1: copy the saved value read from obj+0x54 into global dword_7D0410. [field:obj:0x00000054, source:raw]
    // CALCULATION: Clamp dword_7D0410 into the range bounded below by dword_7D0418 and above by dword_7D041C. [source:raw]
    // ASSIGNMENT: byte_5EA53E = 0: reset the scoring gate flag to zero. [source:raw]
    // CALL: SafeDivisionWithZeroGuard(0.1): run a division guarded against zero division using the literal 0.1. [source:raw]
    // GUARD: When flt_7CF380 is greater than 0.0, reset the virtual dispatch state at byte_8AC494. [source:raw]
    // CALL: VirtualDispatchStateReset(&byte_8AC494) resets the virtual dispatch state buffer. [source:raw]
    // CALL: Reached from SessionMenuModeSwitch and RestartGate as part of the menu/restart transition path. [caller:0x004A0C60, caller:0x004A0FD0, source:raw]

    // Conservative worker pseudocode:
    //   void MainMenuTransition(void *this) {
    //     sub_4A0250(&unk_7CE24C);
    //     SystemOSAPICall(&unk_7CE24C);
    //     if (ConditionalFlagReturn(this))
    //       LookupDispatch(aMainMenu, -1);
    //     v3 = *this;
    //     if (*(v3 + 20) && v3[8] == 1) {
    //       dword_7D2E44 = v3[20];
    //       v1 = v3[21];
    //       dword_7D0410 = v1;
    //       if (v1 < dword_7D0418)
    //         dword_7D0410 = dword_7D0418;
    //       else if (v1 > dword_7D041C)
    //         dword_7D0410 = dword_7D041C;
    //       byte_5EA53E = 0;
    //       SafeDivisionWithZeroGuard(0.1);
    //       if (flt_7CF380 > 0.0)
    //         VirtualDispatchStateReset(&byte_8AC494);
    //     }
    //   }
    // UNRESOLVED: Global dword_7CD8C0 is listed in the packet as an accessed global but does not appear in the raw decompiled source for this function; it may be reached through a callee.
    // UNRESOLVED: dword_7D2E44, dword_7D0410, dword_7D0418, dword_7D041C, byte_5EA53E, flt_7CF380 and byte_8AC494 appear in the raw source but are absent from the packet global list, so their addresses cannot be cited as evidence here.
    // UNRESOLVED: SafeDivisionWithZeroGuard(0.1) and VirtualDispatchStateReset(&byte_8AC494) are call targets present in the raw source but not in the packet callee list; their addresses are unknown.
    // UNRESOLVED: The clamp role of dword_7D0418/dword_7D041C as lower/upper bounds is inferred from the decompiled control flow, not from named semantic evidence.
    // UNRESOLVED: Semantic roles of obj+0x14 (activation flag) and obj+0x50/0x54 (saved state) are only DERIVED from the existing analysis; they are not proven by the raw source alone.
}
