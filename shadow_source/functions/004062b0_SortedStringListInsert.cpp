// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004062B0
// Canonical corpus name: SortedStringListInsert
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SortedStringListInsert_004062b0.c

void UnknownObject::SortedStringListInsert()
{
    // Slot-based string list mutator on this. In insert mode (a4 nonzero) it scans up to 3 fixed slots at this+28 (stride 20 bytes) for an empty slot — recognized by a slot identifier of -1 plus a zero byte flag — and copies a string pointer, two integer fields and a byte flag from the input array a2 (stride 5 dwords). A vtable call at this+0 offset 8 reports the mutation result and sub_406790 finalizes when it fails. In clear mode (a4 zero) it resets all 3 slots to empty, repopulates them from a2's first a3 entries, and calls sub_406790.
    // GUARD: Guard on a2 being non-null before any slot work; the function returns immediately when the input array is absent. [source:raw]
    // GUARD: Guard on the entry count a3 being within the open interval (0, 3]: counts outside 1..3 are rejected. [source:raw]
    // ASSIGNMENT: Insert mode: seed slot cursor to this+28, reset inserted counter v20 to 0 and scan counter v19 to 0, and normalize string reads against the shared default string byte_5EA438. [field:obj:0x00000008, global:0x005EA438, source:raw]
    // LOOP: Insert mode: walk up to 3 slots at this+28 in 20-byte steps; each iteration advances the cursor and breaks after 3 scans. [field:obj:0x00000008, source:raw]
    // GUARD: Empty-slot test on the current slot: the stored string equals the default byte_5EA438, the slot identifiers at this+0x1C and the adjacent identifier are both -1, and the byte flag at this+0x20 is zero. [field:this:0x0000001C, field:this:0x00000020, guard:0, global:0x005EA438, source:raw]
    // ASSIGNMENT: Insert mode fill: copy the input entry's two identifier dwords (at a2+8 and a2+12) into the slot at this+0x1C and its neighbor, and the byte flag from a2+16 into the slot flag at this+0x20; the string is normalized through StringCopyWithBufferRealloc. [callee:0x00566650, field:this:0x0000001C, field:this:0x00000020, field:obj:0x00000008, source:raw]
    // CALL: Insert mode: after at least one insertion, dispatch the vtable method at this+0 offset 8; when it returns 0, run sub_406790 on this to finalize the slot state. [callee:0x00406790, field:this:0x00000000, source:raw]
    // CALL: Clear mode: call AudioStreamCloseAndCleanup(this) before resetting the slots. [callee:0x00406750, source:raw]
    // LOOP: Clear mode: reset all 3 slots at this+28 (stride 20 bytes) to empty, writing -1 to both identifier dwords and 0 to the byte flag, normalizing via StringCopyWithBufferRealloc. [callee:0x00566650, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // LOOP: Clear mode rebuild: copy a3 entries from a2 (stride 5 dwords) into the slots at this+28, restoring the identifier dwords from the entry's +8 and +12 fields, the byte flag from the entry's +4 field of the final dword, and the string via StringCopyWithBufferRealloc with byte_5EA438 fallback. [callee:0x00566650, field:this:0x0000001C, field:this:0x00000020, field:obj:0x00000008, global:0x005EA438, source:raw]
    // CALL: Clear mode: run sub_406790 on this after the slots are repopulated. [callee:0x00406790, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4062B0(char *this, char **a2, int a3, char a4) {
    //     if (!a2) return;
    //     if (a3 <= 3 && a3 > 0) {
    //       if (a4) {
    //         v20 = 0; v19 = 0;
    //         for (v7 = this + 28; v20 < a3; v7 += 20) {
    //           StringCopyWithBufferRealloc(&byte_5EA438);
    //           v8 = slotString(v7) or &byte_5EA438;
    //           if (!strcmp(v8, &byte_5EA438) && slotId(v7) == -1 && slotFlag(v7) == 0) {
    //             v9 = a2 + 5*v20; ++v20;
    //             v10 = v9[0] or &byte_5EA438;
    //             StringCopyWithBufferRealloc(v10);
    //             slotId(v7) = v9[2];
    //             slotId2(v7) = v9[3];
    //             slotFlag(v7) = v9[4];
    //           }
    //           if (++v19 >= 3) break;
    //         }
    //         if (v20 > 0 && !vtableMethod(this, 8))
    //           sub_406790(this);
    //       } else {
    //         AudioStreamCloseAndCleanup(this);
    //         for (v12 = this + 28, v13 = 3; v13; v13--) {
    //           StringCopyWithBufferRealloc(&byte_5EA438);
    //           slotId(v12) = -1; slotId2(v12) = -1; slotFlag(v12) = 0;
    //           v12 += 20;
    //         }
    //         for (v14 = this + 28, v15 = a2 + 3, v16 = a3; v16; v16--) {
    //           v17 = *(v15 - 3) or &byte_5EA438;
    //           StringCopyWithBufferRealloc(v17);
    //           slotId(v14) = *(v15 - 1);
    //           slotId2(v14) = *v15;
    //           slotFlag(v14) = *((char*)v15 + 4);
    //           v15 += 5; v14 += 20;
    //         }
    //         sub_406790(this);
    //       }
    //     }
    //   }
    // UNRESOLVED: FreeWrapper_7bcf is a packet-listed callee but does not appear in the raw decompiled body; it may be an inlined or optimized free path whose call site is invisible in this packet.
    // UNRESOLVED: The vtable method at this+0 offset 8 and sub_406790 semantics (finalization, likely buffer flush or re-sort) are not observable from this function alone.
    // UNRESOLVED: The slot data at this+0x18 (adjacent identifier) is written but has no packet field evidence_ref; the listed fields are this+0x1C and this+0x20 only.
}
