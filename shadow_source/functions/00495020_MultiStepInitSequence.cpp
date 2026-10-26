// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495020
// Canonical corpus name: MultiStepInitSequence
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiStepInitSequence_00495020.c

void UnknownObject::MultiStepInitSequence()
{
    // Runs an unconditional multi-step sequence: initializes conditional/timing state on the global at 0x8AFE18, performs a render/draw operation via the render device pointer stored at 0x8B8DC8, computes internal state flags with a zero argument, then resets the state at 0x8AFE18 and returns its result.
    // CALL: Call ConditionalInit(&unk_8AFE18) to initialize the conditional/timing state object at global 0x8AFE18 before rendering. [callee:0x004F9F00, global:0x008AFE18, source:raw]
    // CALL: Call sub_553700(dword_8B8DC8), passing the render device pointer stored at global 0x8B8DC8 to perform a render/draw operation. [callee:0x00553700, global:0x008B8DC8, source:raw]
    // CALL: Call StateFlagComputation(0) to compute internal state flags after the render step. [callee:0x004F9B30, source:raw]
    // RETURN: Return the result of ConditionalStateReset(&unk_8AFE18), which resets the state object at global 0x8AFE18. [global:0x008AFE18, source:raw]

    // Conservative worker pseudocode:
    //   int MultiStepInitSequence() {
    //     ConditionalInit(&unk_8AFE18);
    //     sub_553700(dword_8B8DC8);
    //     StateFlagComputation(0);
    //     return ConditionalStateReset(&unk_8AFE18);
    //   }
    // UNRESOLVED: Global dword_7CDE24 is read (packet R evidence) but never appears in the raw source; its role here is unknown.
    // UNRESOLVED: Global dword_8B8DC8 is only labelled as a render device pointer by existing analysis; its concrete type is unverified.
    // UNRESOLVED: The trailing ConditionalStateReset call has no corresponding callee entry in the packet, so its address is not recorded.
}
