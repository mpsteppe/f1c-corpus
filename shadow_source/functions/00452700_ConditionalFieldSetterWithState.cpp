// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00452700
// Canonical corpus name: ConditionalFieldSetterWithState
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFieldSetterWithState_00452700.c

void UnknownObject::ConditionalFieldSetterWithState()
{
    // Value-capture routine with a one-shot activation flag. If the override flag this+0x8 is non-zero, the input is always stored to this+0x10 and returned. Otherwise the input is captured into this+0x10 on the first activation (input non-zero while state this+0xC is zero, which then sets this+0xC = 1); a zero input resets the state flag this+0xC = 0 and clears the captured value, and a new non-zero input while already activated clears this+0x10 without re-capturing. Returns the original input in every path. Called from sub_4537B0 (0x004537B0).
    // GUARD: If override flag this+0x8 is non-zero, always capture: store a2 into this+0x10 and return a2, bypassing activation state. [field:this:0x00000008, field:this:0x00000010, source:raw]
    // STATE_TRANSITION: First activation: when input a2 is non-zero and activation state this+0xC is zero, store a2 into this+0x10 and set this+0xC = 1. [field:this:0x0000000C, field:this:0x00000010, source:raw]
    // STATE_TRANSITION: Deactivation: when input a2 is zero, reset activation state this+0xC = 0. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Clear the captured value this+0x10 = 0 in the fall-through paths: either after a zero input, or after a new non-zero input while already activated (override off). [field:this:0x00000010, source:raw]
    // RETURN: Return the original input a2 in all control-flow paths. [abi:lead, source:raw]
    // CALL: Invoked from sub_4537B0 (0x004537B0); existing analysis describes that caller as a per-frame collision-update path. [caller:0x004537B0]

    // Conservative worker pseudocode:
    //   int ConditionalFieldSetterWithState(int* this, int a2) {
    //     if (this[2] != 0) { this[4] = a2; return a2; }   // override this+0x8
    //     if (a2 != 0) {
    //       if (this[3] == 0) {                            // this+0xC first activation
    //         this[4] = a2;
    //         this[3] = 1;
    //         return a2;
    //       }
    //     } else {
    //       this[3] = 0;
    //     }
    //     this[4] = 0;                                     // this+0x10 captured value
    //     return a2;
    //   }
    // UNRESOLVED: The semantic roles of override (this+0x8), activation state (this+0xC) and captured value (this+0x10) as 'override mode', 'first capture' and 'captured value' are DERIVED from existing analysis prose; the raw source shows only conditional integer writes.
    // UNRESOLVED: The init literals 0 for this+0xC and this+0x10 come from the packet field metadata, not from the raw source text.
}
