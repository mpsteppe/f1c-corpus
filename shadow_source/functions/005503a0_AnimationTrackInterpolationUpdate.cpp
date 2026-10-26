// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005503A0
// Canonical corpus name: sub_5503A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5503A0_005503a0.c

void UnknownObject::AnimationTrackInterpolationUpdate()
{
    // Advances animation-track interpolation values across a linked list of animation nodes. For each node with flag bit 0x80000 set and a non-zero track count, walks its track entries and each track's entry array, moving the current value toward the target according to a loop-mode switch (1 wrap, 2 clamp, 3 ping-pong, 4 one-shot). On one-shot completion it clears a flag field on this via FlagFieldBitManipulation and resets the value to -1. Returns 0.
    // LOOP: Traverse the node linked list starting at this[129] (offset this+0x204), following the next-node pointer stored at node+16. [field:this:0x00000204, source:raw]
    // GUARD: Skip the node unless its flag word at node+20 has bit 0x80000 set and its track count at node+280 is non-zero. [source:raw]
    // LOOP: Iterate node-track-count times over the node's track entries; each track entry is 16 bytes and its base pointer is taken from node+284 plus 52. [source:raw]
    // GUARD: Process a track's entry array only when the entry count at *(track_base)+164 is greater than 0. [source:raw]
    // LOOP: Iterate over the entry array at *(track_base)+168; each entry is 148 bytes (37 dwords stride). [source:raw]
    // GUARD: Skip the per-entry interpolation step when the entry field 8 bytes below the entry start is not greater than 1. [source:raw]
    // GUARD: Apply the step only when the current value is below the target and the byte 16 bytes below the entry has bit 4 (completion) set. [source:raw]
    // CALCULATION: Switch on the loop-mode field at entry+4 masked with 0xFFFF000F; the compiler jump table at 0x005504BC selects cases 1-4. [global:0x005504BC, source:raw]
    // CALCULATION: Cases 1-3 advance the current value toward the target with wrap (1), clamp (2), or ping-pong reversal at the target (3). [source:raw]
    // CALL: Case 4 (one-shot): on reaching the target, call FlagFieldBitManipulation(this, 0, 0, 1, 0), which clears a flag field on this (offset this+0x354), and reset the current value to -1. [callee:0x0054C030, field:this:0x00000354, source:raw]
    // ASSIGNMENT: Write the updated current value back to the track entry's current-value slot. [source:raw]
    // RETURN: Return 0 after processing all list nodes. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5503A0(_DWORD *this) {
    //     for (_DWORD *node = (_DWORD *)this[129]; node; node = (_DWORD *)node[4]) {
    //       if ((node[5] & 0x80000) != 0 && node[70]) {
    //         _DWORD *track = (_DWORD *)(node[71] + 52);
    //         int count = node[70];
    //         do {
    //           int *base = (int *)(track[-12]);
    //           if (*(int *)(base + 164) > 0) {
    //             int *entry = (int *)(*(_DWORD *)(base + 168) + 80);
    //             int i = 0;
    //             do {
    //               if (*(entry - 2) > 1) {
    //                 int cur = *track, tgt = *entry;
    //                 if (cur < tgt && (*(_BYTE *)(entry - 4) & 4) != 0) {
    //                   switch (entry[1] & 0xFFFF000F) {
    //                     case 1: if (++cur >= tgt) cur = tgt - cur; break;
    //                     case 2: if (cur < tgt - 1) ++cur; if (cur >= tgt) cur = tgt - 1; break;
    //                     case 3: if (cur == tgt - 1) cur = -cur; ++cur; break;
    //                     case 4: if (++cur >= tgt) { FlagFieldBitManipulation(this, 0, 0, 1, 0); cur = -1; } break;
    //                     default: break;
    //                   }
    //                   *track = cur;
    //                 }
    //               }
    //               entry += 37;
    //               ++i;
    //             } while (i < *(int *)(base + 164));
    //           }
    //           track += 16;
    //           --count;
    //         } while (count);
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Object type of this and the animation node layout are unverified; owner stays UnknownObject.
    // UNRESOLVED: Fields this+0x218, this+0x31C, this+0x320 are declared in the packet field table (skeleton-derived) but are not referenced by the raw pseudocode; their role in this update is unknown.
    // UNRESOLVED: Exact meaning of the completion bit (entry byte at -16, bit 4) and the loop-mode constant space 0xFFFF000F are inferred, not confirmed.
}
