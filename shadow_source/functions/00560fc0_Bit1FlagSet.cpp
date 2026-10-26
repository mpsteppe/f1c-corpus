// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560FC0
// Canonical corpus name: Bit1FlagSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Bit1FlagSet_00560fc0.c

void UnknownObject::Bit1FlagSet()
{
    // Sets flag bit 1 in the state dword at this+0x24 (dword index this[9]) by OR-ing the constant 2. Single-expression body with no reads, guards, globals, or callees. Called from the UI widget recursive state update at 0054C1B0; prelabel marks it a structural twin of the Accumulator at 004C2BE0.
    // ASSIGNMENT: OR-accumulate the mask 2 into the state dword this[9] at byte offset +0x24, raising flag bit 1 [field:this:0x00000024, source:raw]
    // STATE_TRANSITION: Only flag bit 1 at +0x24 is raised; no other field is read or modified and no guard gates the write [field:this:0x00000024, source:raw]
    // RETURN: void function returning no value; the caller 0054C1B0 (UIWidgetRecursiveStateUpdate) invokes it while descending the widget state tree [caller:0x0054C1B0, source:raw]

    // Conservative worker pseudocode:
    //   this[9] |= 2;  // set flag bit 1 at this+0x24
    // UNRESOLVED: Semantics of flag bit 1 at this+0x24 are unknown; only that this function raises it, not which widget state behavior it gates
}
