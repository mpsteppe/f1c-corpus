// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9510
// Canonical corpus name: TimedAudioEventPlayback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimedAudioEventPlayback_004b9510.c

void UnknownObject::TimedAudioEventPlayback()
{
    // Plays timed audio events whose timestamps fall inside the window [a2, a3]. The window is clamped by 1.6670001 depending on the direction flag a4, the playback cursor (this+0x71C) is positioned on the first node at/after a2 (falling back to the head/tail pointers at this+0x714/this+0x718 based on an angle comparison against this+0xF30/this+0xF34), then each event node is played: a resource callback on the node resource handle, stream read into a stack buffer, ring-buffer slot allocation from dword_8AAE64 indexed by dword_83EE60 with a 432-byte stride, and a copy through ArithmeticComparison_3a90. The cursor advances through the next pointers as events play.
    // GUARD: When a2 == a3 the function does nothing; playback only proceeds when the window bounds differ [source:raw]
    // CALCULATION: Clamp the window by 1.6670001: when a4 is set a2 = max(a2, a3 - 1.6670001), otherwise a3 = min(a3, a2 + 1.6670001) [source:raw]
    // ASSIGNMENT: Position the cursor this+0x71C: keep the current cursor when its node data is non-null; otherwise branch on *(this+0xF34) - *(this+0xF30) + *(this+0xF30) >= a2 selecting the head this+0x714 or the tail this+0x718, and store the selection into this+0x71C [field:this:0x0000071C, field:this:0x00000F30, field:this:0x00000F34, field:this:0x00000714, field:this:0x00000718, field:*(this+0x714):0x00000000, field:*(this+0x718):0x00000000, field:*(this+0x71C):0x00000000, source:raw]
    // LOOP: Forward walk from the cursor through the next pointers (node+4) while the node timestamp is below a2; stops when a node timestamp is >= a2 [field:this:0x0000071C, field:*(this+0x71C):0x00000004, field:*(*(this+0x71C)+0x4):0x00000000, field:*(*(*(this+0x71C)+0x4)+0x0):0x00000000, source:raw]
    // LOOP: Backward walk through the prev pointers (node+8) when the cursor data timestamp is above a2; on re-entry the cursor is reset to the head this+0x714 before playback begins [field:this:0x0000071C, field:*(this+0x71C):0x00000008, field:*(*(this+0x71C)+0x8):0x00000000, field:*(*(*(this+0x71C)+0x8)+0x0):0x00000000, field:this:0x00000714, source:raw]
    // CALL: Play one event node: stop when the node timestamp exceeds a3; otherwise sub_566DB0(node resource at +4), WrapperPassThrough(v23), then sub_4B44A0(v23, this+0x6E4) [field:*(*(this+0x714)+0x0):0x00000000, field:*(*(this+0x714)+0x0):0x00000004, callee:0x00566DB0, callee:0x004B4450, callee:0x004B44A0, source:raw]
    // LOOP: Per sub-event loop over the WORD count at node+8: StreamReadWithScale(this+0x6E4, node timestamp, v24); skip allocation when (v24[0] & 0xE0000000) == 0x20000000; otherwise claim a ring-buffer slot (reuse dword_8AAE64 when dword_83EE60 >= 1023, else increment dword_83EE60 and advance dword_8AAE64 by 432) and copy through ArithmeticComparison_3a90(slot, v24) [field:*(*(this+0x714)+0x0):0x00000008, callee:0x004B4360, callee:0x004B3A90, global:0x0083EE60, global:0x008AAE64, source:raw]
    // LOOP: Advance the cursor to the next node through node+4 (this+0x71C = *(node+4)) and continue playing while the next node data is non-null and its timestamp is <= a3 [field:this:0x0000071C, field:*(this+0x71C):0x00000004, source:raw]
    // RETURN: Void return; the sole recorded caller is sub_4B9B80 (004B9B80) [function:0x004B9510, caller:0x004B9B80, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == a3) return;
    //   if (a4) { if (a2 < a3 - 1.6670001f) a2 = a3 - 1.6670001f; }
    //   else   { if (a3 > a2 + 1.6670001f) a3 = a2 + 1.6670001f; }
    //   cursor = this[0x71C/4];
    //   if (!cursor || !*cursor) {
    //     base = (this[0xF34/4] - this[0xF30/4] + this[0xF30/4] >= a2) ? this[0x714/4] : this[0x718/4];
    //     this[0x71C/4] = cursor = base;
    //   }
    //   if (!cursor || !*cursor) return;
    //   data = *cursor;
    //   if (*data <= a2) { while (true) {
    //       node = this[0x71C/4]; if (!node) break;
    //       this[0x71C/4] = next = *(node + 4); if (!next) break;
    //       data = *next; if (!data) break;
    //       if (data[0] >= a2) goto play; } }
    //   else { while (true) {
    //       node = this[0x71C/4]; if (!node) break;
    //       this[0x71C/4] = prev = *(node + 8); if (!prev) break;
    //       data = *prev; if (!data) break;
    //       if (*data < a2) { this[0x71C/4] = *(this[0x71C/4] + 4); data = *(this[0x71C/4]); goto play; } }
    //       this[0x71C/4] = this[0x714/4]; if (!this[0x71C/4]) return; data = *this[0x71C/4]; }
    //   play: while (data && *data <= a3) {
    //     sub_566DB0(data[1]);
    //     WrapperPassThrough(buf); sub_4B44A0(buf, this + 0x6E4);
    //     for (i = 0; i < *(WORD*)(data + 8); ++i) {
    //       StreamReadWithScale(this + 0x6E4, *data, out);
    //       if ((out[0] & 0xE0000000) != 0x20000000) {
    //         if (dword_83EE60 >= 1023) slot = dword_8AAE64;
    //         else { ++dword_83EE60; slot = dword_8AAE64; dword_8AAE64 += 432; }
    //         ArithmeticComparison_3a90(slot, out); } }
    //     if (this[0x71C/4]) this[0x71C/4] = *(this[0x71C/4] + 4);
    //     data = *(this[0x71C/4]);
    //   }
    // UNRESOLVED: The float global flt_5ACD68 appears in the packet fact table but is not referenced in the raw decompiled source, so its role cannot be determined from this packet
    // UNRESOLVED: The angle comparison against this+0xF30/this+0xF34 is read as floats in the raw source; the semantic meaning of those two fields (e.g. directional/angle bounds) is not documented in the packet
    // UNRESOLVED: The 432-byte ring-buffer stride and the 1023 slot ceiling are constants from the raw source; the buffer's owner and format are not established here
    // UNRESOLVED: The event node linked-list layout (data float at +0, resource at +4, WORD count at +8, next at +4, prev at +8 of the node struct) is DERIVED from the chained-dereference field bases and not separately confirmed
}
