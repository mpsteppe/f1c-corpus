## SortedStringListInsert_004062b0 — SortedStringListSlottedInsert

**Summary:** Inserts string metadata entries into a slot-based sorted list, or clears and repopulates slots. In insert mode, finds empty slots and copies string data; in clear mode, resets all slots and rebuilds from input array.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | input item index/count field |
| this | 0x0 | R | — | vtable pointer (dispatched through +8 method) |
| this | 0x1C | RW | 18446744073709551615 | slot identifier (checked for -1 to detect empty slot) |
| this | 0x20 | RW | 0 | slot byte flag (checked for 0 to detect empty slot) |

**Written-by note (persistence):**
- this 0x1C: written on insertion — set to slot value from input or -1 on clear
- this 0x20: written on insertion — set to byte flag from input or 0 on clear

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00406750 | AudioStreamCloseAndCleanup | closes audio stream (called in clear mode) |
| 00406790 | sub_406790 | post-insertion/clear finalization |
| 00566650 | StringCopyWithBufferRealloc | copies string data into buffer |
| 00587bcf | FreeWrapper_7bcf | frees string buffer memory |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1C | == | 18446744073709551615 | slot is empty when this value is -1 and other fields also indicate empty |

**Guard interpretation:** In insert mode, a slot identified by the triple (*(this+0x18)==-1, *(this+0x1C)==-1, *(this+0x20)==0) is considered EMPTY and can receive new data. Slots not matching this pattern are SKIPPED. In clear mode, slots are unconditionally reset.
