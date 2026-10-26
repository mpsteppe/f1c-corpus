// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049AE40
// Canonical corpus name: IndexedListEntryWrite
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedListEntryWrite_0049ae40.c

void UnknownObject::IndexedListEntryWrite()
{
    // Writes two 16-bit values (a3, a4) into the list entry at index a2 of a linked list owned by `this`. Reads the list length via ShortComputation_adb0 (which reads this+0xC). If the index equals the length the entry is appended by delegating to ObjectConstructor_adc0(this, a3, a4). Otherwise, after an out-of-range guard that nulls the walk pointer at this+0x8, the code walks the node chain from this+0x0 using the next-pointer field at node+0x4 down to index a2, then writes a3 and a4 to the selected entry's two 16-bit data slots, returning 1 on success and 0 when the walk or the entry payload is null. Called from sub_493060 (0x00493060).
    // CALL: Reads the list length with ShortComputation_adb0(this), which reads this+0xC [callee:0x0049ADB0, source:raw]
    // GUARD: When a2 equals the returned length the function appends: delegates to ObjectConstructor_adc0(this, a3, a4) and returns its result [callee:0x0049ADC0, source:raw]
    // GUARD: When a2 is negative or not below the capacity this+0xC, the walk pointer this+0x8 is set to null [source:raw]
    // ASSIGNMENT: Initializes the walk pointer this+0x8 from the list head this+0x0 [source:raw]
    // LOOP: When a2 is positive, walks the node chain, repeatedly reading the next-pointer field at node+0x4 and decrementing the remaining count until the target index is reached or the chain ends [source:raw]
    // GUARD: Returns 0 when the selected node pointer this+0x8 is null or when the node's payload pointer is null [source:raw]
    // ASSIGNMENT: Writes a3 to the entry's first 16-bit data slot and a4 to the second, then returns 1 on success [source:raw]
    // CALL: Invoked by sub_493060 (0x00493060) [caller:0x00493060, source:raw]

    // Conservative worker pseudocode:
    //   len = ShortComputation_adb0(this);
    //   if (a2 == len) return ObjectConstructor_adc0(this, a3, a4);
    //   if (a2 < 0 || a2 >= this[3]) { this[2] = 0; }
    //   else {
    //     this[2] = this[0];
    //     while (a2-- > 0) { n = this[2]; if (!n) break; this[2] = *(n + 4); }
    //   }
    //   node = this[2]; data = node ? *node : 0;
    //   if (!node || !data) return 0;
    //   data[0] = a3; data[1] = a4;
    //   return 1;
    // UNRESOLVED: The concrete object type of `this` (head at +0x0, walk pointer at +0x8, length/capacity at +0xC, node next at +0x4) is not named; the layout is inferred only from the raw body and the field sets of the two callees
    // UNRESOLVED: Whether this+0xC is a length or a capacity is ambiguous: the append path compares it against the length from ShortComputation_adb0 while the out-of-range path uses it as an upper bound
    // UNRESOLVED: The distinction between the node pointer this+0x8 and the double-indirected data pointer *node (then written through) is unexplained
}
