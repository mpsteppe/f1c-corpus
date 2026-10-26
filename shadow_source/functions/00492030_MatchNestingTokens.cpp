// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00492030
// Canonical corpus name: TokenMatchingLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TokenMatchingLoop_00492030.c

void UnknownObject::MatchNestingTokens()
{
    // Token-balancing helper: first advances through tokenized input (while sub_491FB0 still reads) until the current token in unk_7CDB70 matches the delimiter asc_5CC4F8 or input ends, then scans tokens keeping a nesting counter v2 starting at 1, incrementing on asc_5CC4F8 (open) matches and decrementing on asc_5CC4F4 (close) matches until the balance falls below 1. Finally decrements the nesting counter this[0x194] and returns 0. Called by sub_492A40.
    // ASSIGNMENT: Initialize the nesting counter v2 to 1. [source:raw]
    // GUARD: Enter the skip phase only while sub_491FB0(this) reports more input. [callee:0x00491FB0, source:raw]
    // LOOP: Skip loop: keep reading tokens while the token in unk_7CDB70 does not match the delimiter asc_5CC4F8 per sub_587C20 and input remains. [global:0x007CDB70, global:0x005CC4F8, callee:0x00587C20, callee:0x00491FB0, source:raw]
    // LOOP: Matching do-while loop: repeat while nesting counter v2 >= 1; break out when sub_491FB0(this) fails. [callee:0x00491FB0, source:raw]
    // GUARD: Increment v2 when the current token in unk_7CDB70 matches asc_5CC4F8 via sub_587C20. [global:0x007CDB70, global:0x005CC4F8, callee:0x00587C20, source:raw]
    // GUARD: Decrement v2 when the current token in unk_7CDB70 matches asc_5CC4F4 via sub_587C20. [global:0x007CDB70, global:0x005CC4F4, callee:0x00587C20, source:raw]
    // CALCULATION: Loop continuation condition v2 >= 1 keeps scanning until the open/close balance returns below 1. [source:raw]
    // ASSIGNMENT: Decrement the nesting depth counter this[101] (byte offset 0x194) after matching. [field:this:0x00000194, source:raw]
    // RETURN: Return 0 on completion. [source:raw]
    // CALL: Invoked by sub_492A40 (00492A40). [caller:0x00492A40, source:raw]

    // Conservative worker pseudocode:
    //   int sub_492030(DWORD* this) {
    //     int v2 = 1;
    //     if (sub_491FB0(this)) {
    //       while (!sub_587C20(&unk_7CDB70, asc_5CC4F8) && sub_491FB0(this))
    //         ;
    //     }
    //     do {
    //       if (!sub_491FB0(this)) break;
    //       if (sub_587C20(&unk_7CDB70, asc_5CC4F8)) ++v2;
    //       if (sub_587C20(&unk_7CDB70, asc_5CC4F4)) --v2;
    //     } while (v2 >= 1);
    //     --this[101];
    //     return 0;
    //   }
    // UNRESOLVED: The exact token grammar is not determinable from this packet: asc_5CC4F8 and asc_5CC4F4 are labelled string delimiters, but whether they represent paired brackets, braces, or other delimiter characters is unproven.
    // UNRESOLVED: Meaning of the this[0x194] counter decrement (per-scope depth bookkeeping) depends on the caller sub_492A40, which is outside this packet.
}
