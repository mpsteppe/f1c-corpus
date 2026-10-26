// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00550620
// Canonical corpus name: ScrollingDataOffsetAcrossLinkedEntries
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScrollingDataOffsetAcrossLinkedEntries_00550620.c

void UnknownObject::ScrollingDataOffsetAcrossLinkedEntries()
{
    // Walks a linked list of scrolling/audio entries anchored at this[129] (offset 0x204), advancing via each node's i[4] (+0x10) slot, and for every node updates a batch of offset fields belonging to a specific target object. For a non-NULL target a2 with a3 within its count at a2+164, it computes v3 = *(a2 + 168) + 148 * a3 (a record base) and, when *(v3 + 72) > 1, visits each node whose count i[70] is non-zero, scanning i[71]-anchored 16-byte-strided entries: an entry whose *(v5 - 12) matches a2 gets *v5 incremented by *(v3 + 80) when *v5 is below it (conditional accumulator add).
    // GUARD: If a2 is 0, return without any effect. [source:raw]
    // GUARD: If a3 is greater than the count stored at a2+164, return without any effect. [source:raw]
    // CALCULATION: Compute v3 = *(a2 + 168) + 148 * a3, the base address of the a3-th 148-byte record for the target. [source:raw]
    // GUARD: If *(v3 + 72) is not greater than 1, return without any effect. [source:raw]
    // LOOP: Iterate the node list starting at this[129] (offset 0x204), advancing through each node's i[4] (+0x10) slot until NULL. [field:this:0x00000204, source:raw]
    // GUARD: If the current node's count i[70] is 0, skip the node. [source:raw]
    // LOOP: Inner do-while: scan i[70] entries starting at v5 = i[71] + 52, striding v5 by 16 bytes per entry until the count is exhausted. [source:raw]
    // GUARD: If the entry's owner slot at *(v5 - 12) does not equal a2, leave this entry untouched. [source:raw]
    // CALCULATION: For a matching entry: v7 = *v5; v8 = *(v3 + 80); if *v5 < v8 then v7 = v7 + v8 (conditional accumulator add). [source:raw]
    // ASSIGNMENT: Write the updated value back into the entry slot *v5. [source:raw]
    // RETURN: Void return after the guarded traversal completes. [source:raw, function:0x00550620]
    // CALL: Called by sub_448140 (00448140) and AudioDSPStateUpdate (00448330) to scroll/offset linked entry data for a target. [caller:0x00448140, caller:0x00448330, source:raw]

    // Conservative worker pseudocode:
    //   void ScrollingDataOffsetAcrossLinkedEntries(_DWORD* this, int a2, int a3) {
    //     if (a2 && a3 <= *(a2 + 164)) {
    //       int v3 = *(a2 + 168) + 148 * a3;
    //       if (*(v3 + 72) > 1) {
    //         for (node = this[0x204]; node; node = node[4]) {
    //           if (node[70]) {
    //             v5 = node[71] + 52;
    //             count = node[70];
    //             do {
    //               if (*(v5 - 12) == a2) {
    //                 v7 = *v5;
    //                 v8 = *(v3 + 80);
    //                 if (*v5 < v8) v7 += v8;
    //                 *v5 = v7;
    //               }
    //               v5 += 16;
    //             } while (--count);
    //           }
    //         }
    //       }
    //     }
    //   }
    // UNRESOLVED: The packet field list includes reads at this+0x224, this+0x32C, this+0x330 and a write at this+0x364, but the raw source only references this[129] (offset 0x204); the role of the other four fields is unresolved here.
    // UNRESOLVED: The offsets a2+164, a2+168, v3+72, v3+80 and the node slots i[4]/i[70]/i[71] belong to objects without packet field evidence; the meaning of the 148-byte record stride and the 16-byte entry stride depends on those external structures.
    // UNRESOLVED: The prelabel proposes this as a structural twin of LinkedListAnimationTimerDecrement (005505a0), but that equivalence is not verified against the raw source here.
}
