// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C1A0
// Canonical corpus name: Bit12FlagSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Bit12FlagSet_0054c1a0.c

void UnknownObject::Bit12FlagSet()
{
    // Sets flag bits 1 and 2 in the state dword at this+0x3C (dword index this[15]) by OR-ing the constant 6. Single-expression body with no reads, guards, globals, or callees. Invoked by three flag-driven loop/conditional dispatchers (004A3390, 004A3440, 004A34A0); prelabel marks it a structural twin of the BitClear at 0054C190.
    // ASSIGNMENT: OR-accumulate the mask 6 into the state dword this[15] at byte offset +0x3C, raising flag bits 1 and 2 [field:this:0x0000003C, source:raw]
    // STATE_TRANSITION: Only the two state flag bits at +0x3C are raised; no other field is read or modified and no guard gates the write [field:this:0x0000003C, source:raw]
    // RETURN: void function returning no value; the three callers 004A3390, 004A3440 and 004A34A0 invoke it from their per-element flag paths [caller:0x004A3390, caller:0x004A3440, caller:0x004A34A0, source:raw]

    // Conservative worker pseudocode:
    //   this[15] |= 6;  // set flag bits 1 and 2 at this+0x3C
    // UNRESOLVED: Semantics of the two flag bits at this+0x3C are unknown; only that this function raises them, not which behavior they gate
}
