// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495080
// Canonical corpus name: sub_495080
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_495080_00495080.c

void UnknownObject::StateInitThenSubsystemStep()
{
    // Linear, unconditional sequence of four steps: initialize conditional state at global unk_8AFE18 via ConditionalInit, run a subsystem step via sub_553700 passing global dword_8B8DC8, compute state flags via StateFlagComputation, then reset the conditional state at unk_8AFE18 and return its result. No guard branches. Existing analysis proposes this is a render-frame step (duplicate of sub_495020), while the LEGACY ABI name suggests audio-system init; both are unconfirmed.
    // CALL: Call ConditionalInit(&unk_8AFE18): initialize the conditional/timing state stored at global unk_8AFE18 before the subsystem step. [callee:0x004F9F00, global:0x008AFE18, source:raw]
    // CALL: Call sub_553700(dword_8B8DC8): run the subsystem step, passing the global dword_8B8DC8 (render device per existing analysis). [callee:0x00553700, global:0x008B8DC8, source:raw]
    // CALL: Call StateFlagComputation(0): compute internal state flags after the step. [callee:0x004F9B30, source:raw]
    // CALL: Call ConditionalStateReset(&unk_8AFE18): reset the conditional/timing state at global unk_8AFE18. [global:0x008AFE18, source:raw]
    // RETURN: Return the result of ConditionalStateReset. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_495080() {
    //     ConditionalInit(&unk_8AFE18);
    //     sub_553700(dword_8B8DC8);
    //     StateFlagComputation(0);
    //     return ConditionalStateReset(&unk_8AFE18);
    //   }
    // UNRESOLVED: Which callee reads global dword_7CDE18 (0x007CDE18) and what role it plays is not visible in the raw source.
    // UNRESOLVED: Whether sub_553700 is a render/draw call (existing-analysis claim) or part of the audio-system init path (LEGACY ABI name) is unconfirmed.
    // UNRESOLVED: Meaning and layout of the conditional state object unk_8AFE18 is unknown.
    // UNRESOLVED: Claim that this is functionally identical to sub_495020 is unverified here.
}
