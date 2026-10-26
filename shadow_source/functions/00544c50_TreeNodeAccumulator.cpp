// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00544C50
// Canonical corpus name: TreeNodeAccumulator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TreeNodeAccumulator_00544c50.c

void UnknownObject::TreeNodeAccumulator()
{
    // Recursive tree accumulation. Starting from node a2, walks the sibling chain (via the next-sibling pointer at a2+76), and for each node descends into its child-linked list at a2+516. For every linked entry it increments the child counter at this+0x34, adds the entry field v5[72] into this+0x38, then processes v5[70] inner entries at stride 64 from v5[71]: zeroes a WORD at entry+2, folds the DWORD at entry with its own value shifted left by 16, calls TwoCounterIncrements with the DWORD at entry+4, and accumulates the DWORD at entry+8 into the accumulator slot selected by the node flag at a2+60 (this+0x3C or the alternate slot). Then increments the visitation counter at this+0x64 and recursively processes the first child at a2+68 when non-null. Returns the last recursive result.
    // LOOP: Outer loop walks the sibling chain: after processing a node, read a2 = *(v3+76) and continue while non-null. [source:raw]
    // GUARD: Select the accumulator slot: v4 = v2+16, but v4 = v2+15 when the byte at a2+60 has bit 0x10 clear. [source:raw]
    // ASSIGNMENT: Load the child-linked list head v5 = *(a2+516) and process each entry while v5 is non-null. [source:raw]
    // CALCULATION: Increment the child counter this+0x34 and add the entry field v5[72] into this+0x38. [field:this:0x00000034, field:this:0x00000038, source:raw]
    // LOOP: Inner do-while iterates v5[70] entries at a 64-byte stride starting from v5[71], while the entry counter is below v5[70]. [source:raw]
    // ASSIGNMENT: Zero the WORD at entry offset +2. [source:raw]
    // CALCULATION: Fold the DWORD at entry offset +0: entry |= entry << 16. [source:raw]
    // CALL: Call TwoCounterIncrements with the DWORD at entry offset +4. [callee:0x005473C0, source:raw]
    // CALCULATION: Accumulate the DWORD at entry offset +8 into the selected accumulator slot *v4 (this+0x3C, or the alternate slot when the flag bit was set). [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: Advance to the next linked entry: v5 = v5[4]. [source:raw]
    // CALCULATION: Increment the node visitation counter at this+0x64. [field:this:0x00000064, source:raw]
    // CALL: If the first-child pointer at a2+68 is non-null, recurse: result = TreeNodeAccumulator(*(a2+68)). [callee:0x00544C50, source:raw]
    // RETURN: Return the result of the last recursive descent (or the last assigned result). [source:raw]

    // Conservative worker pseudocode:
    //   do {
    //     v4 = (*(byte*)(a2+60) & 0x10) ? this+16 : this+15;
    //     v5 = *(dword**)(a2+516);
    //     while (v5) {
    //       this[13]++;
    //       this[14] += v5[72];
    //       for (i=0; i < v5[70]; i++) {
    //         *(word*)(v5[71]+i*64+2) = 0;
    //         *(dword*)(v5[71]+i*64) |= *(dword*)(v5[71]+i*64) << 16;
    //         TwoCounterIncrements(*(dword*)(v5[71]+i*64+4));
    //         *v4 += *(dword*)(v5[71]+i*64+8);
    //       }
    //       v5 = v5[4];
    //     }
    //     this[25]++;
    //     result = 0;
    //     if (*(dword*)(a2+68)) result = TreeNodeAccumulator(*(dword*)(a2+68));
    //     a2 = *(dword*)(a2+76);
    //   } while (a2);
    //   return result;
    // UNRESOLVED: When the node flag at a2+60 has bit 0x10 set, the accumulator target v4 becomes this+16 (offset 0x40), a second accumulator slot not present in the packet field table.
    // UNRESOLVED: Semantics of the per-entry DWORDs (offsets +0, +4, +8) and the v5[70]/v5[72] fields are not established; the node layout (a2+60, +68, +76, +516) belongs to a different object than this.
    // UNRESOLVED: Purpose of TwoCounterIncrements' two counters is unknown from this packet.
}
