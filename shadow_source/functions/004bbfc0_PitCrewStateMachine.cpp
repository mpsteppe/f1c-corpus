// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BBFC0
// Canonical corpus name: PitCrewStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitCrewStateMachine_004bbfc0.c

void UnknownObject::PitCrewStateMachine()
{
    // Pit entry/exit state machine on the this+0x30 pit-state field, driving the vehicle object at this+0x0. On a pit-trigger object (type tag (*(_DWORD*)a2 & 0xFC0000) matching 0x680000) while idle (this+0x30 == 0): set state to 2, store the index byte from the trigger object (a2+8) into this+0x34 if not already stored, then hide the driver model (clear obj+0x105D) if set, update the vehicle render state via the callee at 0x004E0ED0, and call AIStateReset. On a non-pit object: reset state to 0 when it was 2, then show the driver model (set obj+0x105D to 1) if it was not already 1, updating the render state again. Per existing-analysis poke evidence, obj+0x105D is DriverModelVisible and 0x004E0ED0 is the vehicle render-state update (canonically misnamed AudioSoundEffectController).
    // ASSIGNMENT: Initialize result to the trigger object pointer a2. [source:raw]
    // GUARD: Classify the trigger object by type tag: (*(_DWORD*)a2 & 0xFC0000) == 0x680000 selects the pit-entry branch; otherwise the exit branch. [source:raw, global:0x00680000]
    // GUARD: Pit-entry branch: proceed only when the pit-state field this+0x30 is zero (idle). [source:raw, field:this:0x00000030]
    // STATE_TRANSITION: Set pit state this+0x30 to 2 (entering pit); if the stored index this+0x34 is not yet set, store the byte read from the trigger object at a2+8. [source:raw, field:this:0x00000030, field:this:0x00000034]
    // GUARD: If the driver-model flag obj+0x105D is set, read the render mode at obj+0x1054, clear the flag to 0 (hide driver), and call the vehicle render-state update at 0x004E0ED0. [source:raw, field:obj:0x0000105D, field:obj:0x00001054, callee:0x004E0ED0]
    // CALL: Call AIStateReset on the vehicle object at this+0x0 to reset its AI state after entering the pit. [source:raw, field:this:0x00000000, callee:0x0042AF40]
    // GUARD: Exit-branch guard: if the pit state is exactly 2, reset it to 0. [source:raw, guard:1, field:this:0x00000030]
    // ASSIGNMENT: Set result to 1 in the exit branch. [source:raw]
    // GUARD: Exit-branch guard: if the driver-model flag obj+0x105D is not already 1, read the render mode at obj+0x1054, set the flag to 1 (show driver), and call the vehicle render-state update at 0x004E0ED0. [source:raw, guard:0, field:obj:0x0000105D, field:obj:0x00001054, callee:0x004E0ED0]
    // RETURN: Return result: the trigger pointer on the entry path that resets AI state, or 1 on the exit path. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4BBFC0(_BYTE** this_, int a2) {
    //     char result = a2;
    //     if ((*(_DWORD*)a2 & 0xFC0000) == 0x680000) {
    //       if (!this_[12]) {
    //         _BYTE* v4 = this_[13];
    //         this_[12] = (_BYTE*)2;
    //         if (!v4) this_[13] = (_BYTE*)*(char*)(a2 + 8);
    //         if ((*this_)[4189]) {
    //           int v6 = *((_DWORD*)*this_ + 1045);
    //           (*this_)[4189] = 0;
    //           sub_4E0ED0(v6);
    //         }
    //         return AIStateReset(*this_);
    //       }
    //     } else {
    //       if (this_[12] == (_BYTE*)2) this_[12] = 0;
    //       result = 1;
    //       if ((*this_)[4189] != 1) {
    //         int v5 = *((_DWORD*)*this_ + 1045);
    //         (*this_)[4189] = 1;
    //         return sub_4E0ED0(v5);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The exact meaning of the pit-state values (0 idle, 2 entering) and whether additional states exist for the exiting/pit-stop phase.
    // UNRESOLVED: The trigger-object type tag (0xFC0000 mask vs 0x680000 match) and what kind of scene/game object a2 is.
    // UNRESOLVED: Whether obj+0x1054 (render mode) indexes a vehicle render-state enum whose full value set is known; only the read of the current value is evidenced here.
}
