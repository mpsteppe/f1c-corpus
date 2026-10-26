// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A1C0
// Canonical corpus name: ConditionalSingleStoreWithIteration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalSingleStoreWithIteration_0049a1c0.c

void UnknownObject::ConditionalHeadStoreOrIterateAndSet()
{
    // Conditional single-store with iteration. Rejects a zero a2 with return -1. When the head pointer at this+0x0 is NULL, stores a2 as the list head (lazy initialization) and returns 0. When a head already exists, walks the node chain through sub_499E00 and then invokes FieldSetterAt0x68 on a traversed node. Called by sub_493060.
    // GUARD: If a2 is zero, return -1 immediately; zero a2 is the invalid-input sentinel [source:raw]
    // GUARD: Branch on the head pointer at this+0x0: NULL selects the lazy-store path, non-NULL selects the iteration path [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Lazy initialization: when the head is NULL, store a2 at this+0x0 and return 0 [field:this:0x00000000, source:raw]
    // CALL: Initial chain step: sub_499E00 is applied to the head (v4 = *this) and its result decides whether the do-while walk begins [callee:0x00499E00, field:this:0x00000000, source:raw]
    // LOOP: do-while walk: each pass assigns v7 = sub_499E00(v6) and the walk repeats while sub_499E00(v7) is non-zero, so it advances along the node chain until sub_499E00 yields zero [callee:0x00499E00, source:raw]
    // CALL: FieldSetterAt0x68(v6, v5) is invoked after the walk on the non-NULL-head path, writing a field on the traversed node [callee:0x00499DF0, source:raw]
    // RETURN: Return 0 on both the lazy-store and the iteration paths; return -1 on the zero-input guard; invoked from sub_493060 [function:0x0049A1C0, caller:0x00493060, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == 0) return -1;
    //   if (*this == 0) {
    //     *this = a2;
    //     return 0;
    //   }
    //   if (sub_499E00(*this)) {
    //     do v6 = sub_499E00(v6); while (sub_499E00(v6));
    //   }
    //   FieldSetterAt0x68(v6, v5);
    //   return 0;
    // UNRESOLVED: v6 and v5 are decompiler register artifacts not initialized in the visible source, so the exact node targeted by FieldSetterAt0x68 and its second argument are not established
    // UNRESOLVED: sub_499E00's termination contract is defined by its own body, which is outside this packet
    // UNRESOLVED: Why FieldSetterAt0x68 runs only on the branch where the chain already has a head is not documented
}
