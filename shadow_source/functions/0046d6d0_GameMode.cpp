// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046D6D0
// Canonical corpus name: GameMode
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GameMode_0046d6d0.c

void UnknownObject::GameMode()
{
    // Game-mode state router. Updates the sound system via an indirect vtable call on dword_5EB10C when present, then initializes the buffer at flt_5EA618 with defaults. A switch on dword_7D0410 (jump table jpt_46D704) selects the mode path: modes 1-3 dispatch the circuit-selection prompt, mode 4 chains a session-scene init and dispatches the resume prompt, mode 5 (only when SessionStateCheck(dword_7CD25C) returns 3) sets up a multiplayer session (UI lookup, entrant setup, config writeback, conditional season/track scene load, sets dword_5CC9E8 and calls EmptyStub_0170). Returns -1 on the handled cases and 0 on the default.
    // GUARD: If dword_5EB10C is non-zero, invoke its vtable method at offset 12 (indirect __thiscall) — a sound-system update call. [global:0x005EB10C, source:raw]
    // CALL: BufferInitWith10fDefaults(flt_5EA618) fills the input buffer at flt_5EA618 with its default values. [callee:0x004186A0, global:0x005EA618, source:raw]
    // STATE_TRANSITION: Switch on dword_7D0410 via the jump table jpt_46D704 to select the game-mode path. [global:0x007D0410, global:0x0046D7D0, source:raw]
    // CALL: Modes 1, 2 and 3: GuardedFunctionDispatch(this, aSelectcircuitp) presents the circuit-selection prompt. [callee:0x00486AA0, global:0x005C65EC, source:raw]
    // CALL: Mode 4: SessionSceneInitChain(&unk_7CE24C) chains the session scene init, then GuardedFunctionDispatch(this, aChResume) dispatches the resume prompt. [callee:0x004A0630, global:0x007CE24C, callee:0x00486AA0, global:0x005C6BF8, source:raw]
    // GUARD: Mode 5 entry gate: the multiplayer path runs only when SessionStateCheck(dword_7CD25C) returns 3. [callee:0x00461CD0, global:0x007CD25C, source:raw]
    // CALL: LookupDispatch(*(this+0x40), aMpclientgrid, -1) resolves the multiplayer client-grid UI element using the object at this+0x40. [callee:0x00497940, field:this:0x00000040, global:0x005C5F5C, source:raw]
    // CALL: FAILWRONGDESCRIPTION(v3) fills the entrant-description buffer, then NetworkEntrantSetupWithIDCheck(dword_7CD25C, v3, 0) and SessionConfigWriteback(v3) configure and persist the session. [callee:0x00461550, callee:0x004627C0, callee:0x00461900, global:0x007CD25C, source:raw]
    // GUARD: Conditional indirect __thiscall on dword_7CD8C0's vtable at offset 28 with argument 24; when it returns non-zero the scene loaders run. [global:0x007CD8C0, source:raw]
    // CALL: SeasonSceneNameAccessor() and TrackSceneConfigLoader() load the season/track scene configuration. [callee:0x00477640, callee:0x00477680, source:raw]
    // ASSIGNMENT: Set the multiplayer-active flag: dword_5CC9E8 = 1. [global:0x005CC9E8, source:raw]
    // CALL: EmptyStub_0170() finalizes the multiplayer setup path. [callee:0x004B0170, source:raw]
    // RETURN: Return -1 for handled modes 1-5 and 0 for the default case. [source:raw]

    // Conservative worker pseudocode:
    //   int GameMode(this) {
    //     if (dword_5EB10C) dword_5EB10C->vtable[3]();
    //     BufferInitWith10fDefaults(&flt_5EA618);
    //     switch (dword_7D0410) {
    //       case 1: case 2: case 3: GuardedFunctionDispatch(this, aSelectcircuitp); return -1;
    //       case 4: SessionSceneInitChain(&unk_7CE24C); GuardedFunctionDispatch(this, aChResume); return -1;
    //       case 5:
    //         if (SessionStateCheck(dword_7CD25C) == 3) {
    //           LookupDispatch(*(this+0x40), aMpclientgrid, -1);
    //           FAILWRONGDESCRIPTION(v3);
    //           NetworkEntrantSetupWithIDCheck(dword_7CD25C, v3, 0);
    //           SessionConfigWriteback(v3);
    //           if (dword_7CD8C0->vtable[7](24)) { SeasonSceneNameAccessor(); TrackSceneConfigLoader(); }
    //           dword_5CC9E8 = 1;
    //           EmptyStub_0170();
    //         }
    //         return -1;
    //       default: return 0;
    //     }
    //   }
    // UNRESOLVED: The exact meaning of the dword_7D0410 switch selector (game-mode identifier) is not established by this packet.
    // UNRESOLVED: The semantics of the SessionStateCheck return value 3 that gates the multiplayer path are not defined here.
    // UNRESOLVED: The identities of the objects behind dword_5EB10C, dword_7CD25C, dword_7CD8C0 and unk_7CE24C are not established by this packet.
}
