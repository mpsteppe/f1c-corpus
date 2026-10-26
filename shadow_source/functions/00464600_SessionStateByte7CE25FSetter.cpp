// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464600
// Canonical corpus name: SessionStateByte7CE25FSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionStateByte7CE25FSetter_00464600.c

void UnknownObject::SessionStateByte7CE25FSetter()
{
    // Session flag setter called from Game_Post. Guards on the init byte_7CE260: when it is zero (not initialized), builds the track configuration name into byte_7CE498, conditionally runs a short computation plus a guarded init call on the object at *this, calls a single-function wrapper with the dword at obj+0x3FB8, then reads two object state bytes at +0xC5/+0xC6 and sets the persistent session flag to 1 if either is nonzero. Returns the guard byte state (or last checked byte); the flag is never cleared here.
    // GUARD: Read init guard byte_7CE260; if nonzero (already initialized) the body is skipped and the guard state is returned. [global:0x007CE260, source:raw]
    // CALL: Call TrackConfigurationNameBuilder with a pointer to byte_7CE498 to build the track configuration name string. [callee:0x004B16B0, global:0x007CE498, source:raw]
    // GUARD: Dereference this (field at +0x0) to obtain the underlying object pointer; check the dword at obj+0x3FC4 for nonzero to decide whether the init pair runs. [field:this:0x00000000, field:obj:0x00003FC4, source:raw]
    // CALL: Conditionally call ShortComputation_3140(this) before the guarded init call. [callee:0x00463140, field:this:0x00000000, source:raw]
    // CALL: Conditionally call GuardedInitCall on the object pointer at *this advanced by 112528 bytes. [callee:0x0045D500, field:this:0x00000000, source:raw]
    // CALL: Call SingleFunctionCallWrapper_a910 with the dword read from obj+0x3FB8 as its argument. [callee:0x0057A910, field:obj:0x00003FB8, source:raw]
    // ASSIGNMENT: Read the object state byte at +0xC5 and the byte at +0xC6; if either is nonzero set the persistent session flag (byte_7CE25F) to 1. [field:obj:0x000000C5, field:obj:0x000000C6, source:raw]
    // RETURN: Return the guard byte state (result of the byte_7CE260 check), or the last state byte examined. [global:0x007CE260, source:raw]

    // Conservative worker pseudocode:
    //   char sub_464600(obj* this) {
    //     char result = byte_7CE260;
    //     if (!byte_7CE260) {
    //       TrackConfigurationNameBuilder(&byte_7CE498);
    //       if (*(*this + 0x3FC4)) {
    //         ShortComputation_3140(this);
    //         GuardedInitCall((*this) + 112528);
    //       }
    //       SingleFunctionCallWrapper_a910(*(*this + 0x3FB8));
    //       if (*(*this + 0xC5) || *(*this + 0xC6))
    //         byte_7CE25F = 1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: global unk_7CE24D is listed as read by the packet but does not appear in the raw source text; it may alias the byte_7CE25F flag region set by this function.
    // UNRESOLVED: The write target byte_7CE25F has no packet global entry of its own; only the nearby unk_7CE24D is catalogued, so the exact flag field is identified only through the canonical name.
    // UNRESOLVED: The exact meaning of the object state bytes at +0xC5/+0xC6 (which state they encode) is unknown.
    // UNRESOLVED: The relationship between the init guard byte_7CE260 and the 0x45D500 guarded-init routine is not visible from this function alone.
}
