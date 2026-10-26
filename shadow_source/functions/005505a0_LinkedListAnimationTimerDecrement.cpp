// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005505A0
// Canonical corpus name: LinkedListAnimationTimerDecrement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListAnimationTimerDecrement_005505a0.c

void UnknownObject::LinkedListAnimationTimerDecrement()
{
    // Walks the animation-node linked list anchored at this+0x204, and for each node's track array decrements track values that reference a given animation data entry (a2) by that entry's step value, gated by the entry index being in bounds (a3 <= a2+164), the entry type being non-terminal (a2-derived value at +72 > 1), and the track value being at or above the step threshold (a2-derived value at +80).
    // GUARD: If a2 is null, skip the entire function (no animation data reference). [source:raw]
    // GUARD: If a3 is greater than the entry count at *(a2+164), skip (entry index out of bounds). [source:raw]
    // CALCULATION: v3 = *(a2+168) + 148 * a3 — compute the entry pointer for entry a3. [source:raw]
    // GUARD: If *(v3+72) is <= 1, skip the traversal (entry type is terminal/single-frame). [source:raw]
    // LOOP: Iterate the linked list of animation nodes from this[129] (this+0x204), following the next-node pointer i[4] until null. [field:this:0x00000204, source:raw]
    // GUARD: If i[70] is zero, the node has no tracks to process — skip to the next node. [source:raw]
    // LOOP: Iterate the node's track slots: v5 starts at i[71]+52 and advances by 16 per slot, for i[70] iterations. [source:raw]
    // GUARD: If *(v5-12) != a2, the track does not reference this animation data entry — skip the decrement. [source:raw]
    // CALCULATION: v7 = *v5; if *v5 is >= the step value *(v3+80), v7 is reduced by that step value. [source:raw]
    // ASSIGNMENT: Store the adjusted value back: *v5 = v7 — decrement the track value by the entry's step value. [source:raw]
    // RETURN: Function returns void; traversal completes without a value. [function:0x005505A0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == 0) return;
    //   if (a3 > *(a2+164)) return;
    //   v3 = *(a2+168) + 148 * a3;
    //   if (*(v3+72) <= 1) return;
    //   for (i = this[0x204]; i; i = i[4]) {
    //     if (i[70] == 0) continue;
    //     for (v5 = i[71]+52, v6 = i[70]; v6; v5 += 16, v6--) {
    //       if (*(v5-12) == a2) {
    //         v7 = *v5;
    //         if (*v5 >= *(v3+80)) v7 -= *(v3+80);
    //         *v5 = v7;
    //       }
    //     }
    //   }
    // UNRESOLVED: The semantic roles of a2 and a3 (which animation data entry and index) are inferred but not independently established.
    // UNRESOLVED: Fields this+0x224, this+0x32C, this+0x330, this+0x364 are listed by the fact table but are not referenced in this function's raw source, so they cannot be assigned to an operation here.
    // UNRESOLVED: The caller AudioDSPStateUpdate (0x00448330) is not analyzed in this packet.
}
