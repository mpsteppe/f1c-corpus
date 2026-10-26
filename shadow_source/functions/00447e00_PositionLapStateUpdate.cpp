// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00447E00
// Canonical corpus name: PositionLapStateUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PositionLapStateUpdate_00447e00.c

void UnknownObject::PositionLapStateUpdate()
{
    // Position/lap-change state handler. Takes a new position value a2 and an event kind a3. When a2 differs from the previously stored position (this+0x1EF4), it encodes a change direction into this+0x1EF8 (1 for a2 == -1, +1 when a2 exceeds the counter at this+0x1EF0, -1 when a2 is lower, 0 when a2 == 0), stores the new position, and resets the counter. Lost-position (direction <= 0) and gained-position (direction > 0) branches each copy their reference data into this+0x1E7C/0x1E80 and fire a sound trigger on base ID this+0x1F00 + 20 (different trigger per branch). Depending on a3 (0 = plain change, 4 = with lap) it sets the UI state at this+0x34 (2 lost, 3 gained, 5 lost+lap, 6 gained+lap) and commits UI params this+0x38 = this+0x60 and this+0x3C = this+0x64. Called from Gearbox, VehicleMainPhysicsUpdate and sub_447780.
    // GUARD: Change detection: if a2 equals this+0x1EF4 (previously stored position) skip the whole update and return unchanged. [field:this:0x00001EF4, source:raw]
    // ASSIGNMENT: Encode direction into this+0x1EF8: a2 == -1 -> 1; a2 nonzero -> 2 * (a2 > this+0x1EF0) - 1 (+1 gained / -1 lost against the tracking counter); a2 == 0 -> 0. [field:this:0x00001EF8, field:this:0x00001EF0, source:raw]
    // ASSIGNMENT: Store the new position: this+0x1EF4 = a2, then reset the tracking counter this+0x1EF0 = 0. [field:this:0x00001EF4, field:this:0x00001EF0]
    // GUARD: Branch on change direction: if this+0x1EF8 (v5) > 0 take the gained-position branch, otherwise the lost-position branch. [field:this:0x00001EF8]
    // ASSIGNMENT: Lost-position reference copy: this+0x1E7C = this+0x1E94 and this+0x1E80 = this+0x1E98. [field:this:0x00001E7C, field:this:0x00001E94, field:this:0x00001E80, field:this:0x00001E98]
    // CALL: Lost-position sound: SoundEffectTrigger_89a0(this+0x1F00 + 20). [callee:0x004F89A0, field:this:0x00001F00]
    // ASSIGNMENT: Lost-position UI state: if a3 == 0 set this+0x34 = 2 (lost, plain); else if a3 == 4 set this+0x34 = 5 (lost + lap). [field:this:0x00000034, source:raw]
    // ASSIGNMENT: Gained-position reference copy: this+0x1E7C = this+0x1E84 and this+0x1E80 = this+0x1E88. [field:this:0x00001E7C, field:this:0x00001E84, field:this:0x00001E80, field:this:0x00001E88]
    // CALL: Gained-position sound: SoundEffectTrigger(this+0x1F00 + 20). [callee:0x004F88A0, field:this:0x00001F00]
    // ASSIGNMENT: Gained-position UI state: if a3 == 0 set this+0x34 = 3 (gained, plain) and return; else if a3 == 4 set this+0x34 = 6 (gained + lap) and return. [field:this:0x00000034, source:raw]
    // ASSIGNMENT: Common-tail UI param commit (a3 == 1, or the lost-branch a3 == 4 path after setting state 5): this+0x38 = this+0x60 and this+0x3C = this+0x64. [field:this:0x00000038, field:this:0x00000060, field:this:0x0000003C, field:this:0x00000064]
    // RETURN: Return the accumulated result (the last UI value read from this+0x60, or a2 when unchanged). [source:raw]

    // Conservative worker pseudocode:
    //   if a2 == this[0x1EF4]: return a2;
    //   this[0x1EF8] = (a2 == -1) ? 1 : (a2 ? 2 * (a2 > this[0x1EF0]) - 1 : 0);
    //   this[0x1EF4] = a2; this[0x1EF0] = 0;
    //   if this[0x1EF8] <= 0:  // lost or unchanged
    //     this[0x1E7C] = this[0x1E94]; this[0x1E80] = this[0x1E98];
    //     SoundEffectTrigger_89a0(this[0x1F00] + 20);
    //     if a3 == 0: this[0x34] = 2; else if a3 == 4: this[0x34] = 5;
    //   else:  // gained
    //     this[0x1E7C] = this[0x1E84]; this[0x1E80] = this[0x1E88];
    //     SoundEffectTrigger(this[0x1F00] + 20);
    //     if a3 == 0: this[0x34] = 3; return;
    //     if a3 == 4: this[0x34] = 6; return;
    //   this[0x38] = this[0x60]; this[0x3C] = this[0x64];
    // UNRESOLVED: The exact semantics of a3 values other than 0 and 4 (e.g. a3 == 1, seen in the VehicleMainPhysicsUpdate caller) are not special-cased in the .c; they only hit the common-tail param commit without changing the UI state.
    // UNRESOLVED: a2 == -1 encodes direction 1 (gained) in the .c, which reads as an anomaly against the fills' 'direction -1 = lost, +1 = gained' convention; the -1 input likely means a special 'no position / leaving grid' event, but the .c alone does not disambiguate it.
}
