// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB8E0
// Canonical corpus name: sub_4BB8E0
// Owner: SessionStateObject [DERIVED]
// Raw source: functions/sub_4BB8E0_004bb8e0.c

void SessionStateObject::SessionStateReset()
{
    // Session/vehicle state reset routine called per-frame from sub_4C6B60. When the global session type dword_7C56A4 is <= 6 (non-qualifying session) and the object condition at obj+0x32C8 (reached through the pointer at this+0x0) is <= 1, it re-initializes the AI racing line via AIRacingLinePathFollowing, downgrades the mode flag this+0x60 from 2 to 1, and resets the three float fields this+0x18/0x1C/0x20 to -1.0f. Regardless of those guards it unconditionally clears the status flags this+0xA8/0xAC/0xB0/0xB4/0xD0/0xD4, then returns the value read at entry (the session type, or the object condition when the guard failed).
    // GUARD: Read the global session type dword_7C56A4; the reset body runs only when the type is <= 6 (non-qualifying session). [function:0x004BB8E0, global:0x007C56A4, source:raw]
    // GUARD: Load the object pointer stored at this+0x0 and test the per-object condition flag at obj+0x32C8; the reset body runs only when the condition is <= 1. [field:this:0x00000000, field:obj:0x000032C8, source:raw]
    // CALL: Invoke AIRacingLinePathFollowing on the object racing-line subobject (object base + 12) to re-initialize path following. [callee:0x004E9CA0, field:this:0x00000000, source:raw]
    // STATE_TRANSITION: Guard on the mode flag at this+0x60: when it equals 2, downgrade it to 1. [field:this:0x00000060, guard:0, source:raw]
    // ASSIGNMENT: Reset the three float fields this+0x18, this+0x1C and this+0x20 to -1.0f. [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Unconditionally zero the status flags at this+0xA8, this+0xAC, this+0xB0, this+0xB4, this+0xD0 and this+0xD4 (a mix of dword and byte flags). [field:this:0x000000A8, field:this:0x000000AC, field:this:0x000000B0, field:this:0x000000B4, field:this:0x000000D0, field:this:0x000000D4, source:raw]
    // RETURN: Return the value read at entry (the session type from dword_7C56A4, or the object condition at obj+0x32C8 when the guard failed); called from the frame-path ticker sub_4C6B60. [global:0x007C56A4, field:obj:0x000032C8, caller:0x004C6B60, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int SessionStateReset(DWORD* this) {
    //     unsigned int result = dword_7C56A4;
    //     if (dword_7C56A4 <= 6) {
    //       DWORD* obj = (DWORD*)*this;
    //       result = *(DWORD*)((char*)obj + 0x32C8);
    //       if (result <= 1) {
    //         AIRacingLinePathFollowing((char*)obj + 12);
    //         if (this[24] == 2) this[24] = 1;
    //         this[6] = this[7] = this[8] = -1.0f;
    //       }
    //     }
    //     this[44] = 0; *((BYTE*)this + 0xA8) = 0;
    //     this[43] = 0; *((BYTE*)this + 0xB4) = 0;
    //     this[52] = 0; *((BYTE*)this + 0xD4) = 0;
    //     return result;
    //   }
    // UNRESOLVED: Whether `this` is the vehicle array slot itself or a controller object holding a vehicle pointer (this+0x0) is unconfirmed; the object reached at this+0x0 is treated as the vehicle/object for the racing-line and condition checks.
    // UNRESOLVED: Semantic purpose of the per-object condition at +0x32C8 (tested <= 1) and of the cleared flags this+0x60/0xA8..0xD4 beyond 'reset to default' depends on the caller sub_4C6B60 and is not determined here.
    // UNRESOLVED: The owner type SessionStateObject is DERIVED from the legacy ABI label 'State_Reset_on_Session_Condition' and the reset semantics; no independent class evidence exists.
}
