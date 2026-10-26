// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DEDB0
// Canonical corpus name: SortedArrayInsertWithLRUEviction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SortedArrayInsertWithLRUEviction_004dedb0.c

void UnknownObject::SortedArrayInsertWithLRUEviction()
{
    // Inserts a 9-float entry (36 bytes) into a fixed-capacity sorted array owned by `this` (max 20 entries, entry stride 9 floats, element count at this+0x18). Duplicate entries are rejected with a -1 index report. When full, a minimum-score LRU candidate is evicted by shifting entries left. The entry is then placed in sorted position (ordered by key a2[1]) by shifting entries right, the count is incremented, and sub_4DF110 reports the inserted key and position.
    // ASSIGNMENT: Read the current element count from this+0x18 (int32 at dword index 6) into v4. [source:raw, field:this:0x00000018]
    // LOOP: Scan the v4 existing entries (9 floats / 36 bytes each) comparing all 9 dword/float components of a2 against the entry data starting at this+0x20. [source:raw, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x0000001C]
    // GUARD: If an exact duplicate of the 9-float entry a2 is already present, return early with sub_4DF110(a2[1], -1). [source:raw]
    // CALL: On duplicate detection, call sub_4DF110 with the entry key a2[1] and index -1 to report the rejected insertion. [callee:0x004DF110]
    // GUARD: When the array is full (count == 20), select an LRU eviction candidate before inserting. [source:raw]
    // CALCULATION: Scan all 20 entries' state/score slots selecting the minimum-score index as the eviction candidate, reading flag/constant globals flt_59E670 and flt_5AD140 as part of the scoring. [source:raw, global:0x0059E670, global:0x005AD140]
    // ASSIGNMENT: Evict by shifting entries from the eviction index up to count-1 left by one slot (36-byte copies) and decrementing the count at this+0x18. [source:raw, field:this:0x00000018, field:this:0x0000001C]
    // CALCULATION: Scan existing entries comparing key a2[1] against each entry's first float to find the sorted insertion position. [source:raw, field:this:0x00000020]
    // ASSIGNMENT: If the insertion position is before the old tail, shift entries right by one slot (36-byte copies) to make room for the new entry. [source:raw, field:this:0x0000001C]
    // ASSIGNMENT: Copy the 9-float entry a2 into the vacated slot and increment the element count at this+0x18. [source:raw, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020]
    // RETURN: Return the result of sub_4DF110 with the inserted key v2[1] and the insertion index. [callee:0x004DF110, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4DEDB0(float *this, float a2[9]) {
    //     int count = *(int*)(this + 6);                    // this+0x18
    //     for (int i = 0; i < count; i++)                   // duplicate scan
    //       if (memcmp(a2, &this[8 + 9*i], 36) == 0)
    //         return sub_4DF110(a2[1], -1);
    //     if (count == 20) {                                // full: LRU eviction
    //       int evict = -1; float best = 3.4028235e38;
    //       for (int i = 0; i < 20; i++) {                  // min-score candidate
    //         float score = scoreOf(&this[7 + 9*i]);
    //         if (score < best) { best = score; evict = i; }
    //       }
    //       for (int j = evict; j < count - 1; j++)         // shift left
    //         memcpy(&this[7 + 9*j], &this[7 + 9*(j+1)], 36);
    //       count--;
    //     }
    //     int pos = 0;
    //     while (pos < count && a2[1] >= this[8 + 9*pos]) pos++;  // sorted key position
    //     for (int j = count; j > pos; j--)                 // shift right
    //       memcpy(&this[7 + 9*j], &this[7 + 9*(j-1)], 36);
    //     memcpy(&this[7 + 9*pos], a2, 36);                 // insert
    //     count++;
    //     return sub_4DF110(a2[1], pos);
    //   }
    // UNRESOLVED: Exact meaning of the per-entry state/score fields and the eviction cost model (which combination of state flag and score yields eviction) is not fully determined.
    // UNRESOLVED: Role of read-only globals flt_59E670 / flt_5AD140 within the LRU scoring is inferred from the read evidence, not confirmed.
    // UNRESOLVED: sub_4DF110 reporting semantics (key, index) are inferred from the two call sites; the callee body is not analyzed here.
}
