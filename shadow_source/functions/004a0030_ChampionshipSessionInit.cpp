// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0030
// Canonical corpus name: sub_4A0030
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A0030_004a0030.c

void UnknownObject::ChampionshipSessionInit()
{
    // Session-state initializer driven by the championship/race mode flag dword_7D0410. Modes 1-4 set the global session state to 1 and dispatch the monitor UI page; modes 5-6 only set the state. Unconditionally runs the global vtable dispatch with parameter 1 and initializes the penalty struct at byte_7C56C0, then returns 0.
    // GUARD: Switch on dword_7D0410 routed through the jump table jpt_4A003B: cases 1-4 and 5-6 take a branch, default blocks. [global:0x007D0410, global:0x004A0088, source:raw]
    // CALL: Cases 1-6 call GlobalStateSetter(1) to set the global session state. [callee:0x004A0D30, source:raw]
    // CALL: Cases 1-4 only: LookupDispatch(dword_7CD8C0, aMonitorpage, -1) dispatches the monitor page through the command dispatch interface. [callee:0x00497940, global:0x007CD8C0, global:0x005C6BD4, source:raw]
    // CALL: Unconditional GlobalVTableDispatchByParam(1) dispatches the global vtable with parameter 1. [callee:0x004C8D90, source:raw]
    // CALL: Unconditional PenaltyStructInit(&byte_7C56C0) initializes the penalty state structure. [callee:0x0042E400, global:0x007C56C0, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   switch (dword_7D0410) {
    //     case 1: case 2: case 3: case 4:
    //       GlobalStateSetter(1);
    //       LookupDispatch(dword_7CD8C0, aMonitorpage, -1);
    //       break;
    //     case 5: case 6:
    //       GlobalStateSetter(1);
    //       break;
    //     default: break;
    //   }
    //   GlobalVTableDispatchByParam(1);
    //   PenaltyStructInit(&byte_7C56C0);
    //   return 0;
    // UNRESOLVED: unk_7CE24D and byte_8AC494 appear in the packet globals table but are not referenced in the decompiled source body; their role here is not evidenced.
    // UNRESOLVED: The meaning of the dword_7D0410 mode enum (which value selects championship vs race session) is DERIVED from the existing analysis and not evidenced by the packet.
}
