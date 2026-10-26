// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FD6D0
// Canonical corpus name: TwoCallDelegation_d6d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoCallDelegation_d6d0_004fd6d0.c

void UnknownObject::ResetThenDestroyList()
{
    // Two-stage delegation/cleanup: unconditionally calls MultiFieldReset (0x004FC280) on the sub-object at this + 264, then forwards `this` to DualLinkedListDestruction and returns that callee's result. Called from the Game_Post (0x0042DA30) path.
    // CALL: Call MultiFieldReset (0x004FC280) with the sub-object at this + 264 (decimal offset as written in the raw source). [callee:0x004FC280, source:raw]
    // CALL: Call DualLinkedListDestruction with `this`; its return value is the function result. [source:raw]
    // RETURN: Return the result of DualLinkedListDestruction. [source:raw]
    // CALL: Invoked by Game_Post (0x0042DA30). [caller:0x0042DA30, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4FD6D0(char *this) {
    //     MultiFieldReset(this + 264);
    //     return DualLinkedListDestruction(this);
    //   }
    // UNRESOLVED: DualLinkedListDestruction is named in the raw source but has no packet callee evidence reference; its address and identity are not in this packet.
    // UNRESOLVED: The object type behind `this` and the meaning of the +264 sub-object are not evidenced here.
    // UNRESOLVED: Game_Post is a prelabel label; its semantics are not evidenced in this packet.
}
