## AIOpponentSelection_004bf790 — AI opponent list builder

**Summary:** Builds a sorted linked list of AI opponent candidates by randomly selecting vehicles, computing audio/skill parameters for each, and merge-sorting by float value. Used to select opponents for AI path/difficulty assignment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIDriverCountSetup (004bfd90), GameFilterDataLoader (004c0db0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x4)+0x4) | 0x4 | R | — | next pointer in linked list node |
| *(obj+0x4) | 0x4 | RW | 0 | next pointer of current tail node (updated during append) |
| obj | 0x4 | R | — | this[1] — current tail pointer in linked list |
| this | 0x0 | RW | — | head pointer of linked list |
| this | 0x4 | RW | — | tail pointer of linked list |
| this | 0x8 | RW | — | current/iter pointer in linked list |
| this | 0xC | RW | — | count of elements in linked list |

**Written-by note (persistence):**
- *(obj+0x4) 0x4: written each time a new node is appended to list; external poke corrupts list linkage
- this 0x0: written when list empty (first node) and after merge sort (new head); external poke corrupts list
- this 0x4: written each append and after merge sort; external poke corrupts list
- this 0x8: written to list head after merge sort; external poke corrupts iteration
- this 0xC: incremented each append; external poke corrupts count

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d266c | aSNotNotai | R | format string for debug/log output |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac36c | dword_8AC36C | R | vehicle setup/roster data structure pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bf6a0 | sub_4BF6A0 | look up season audio parameter for vehicle |
| 004bf730 | sub_4BF730 | reset/clear the linked list |
| 004bfa00 | AIPathPerformanceFunction | check if specific opponent count is already valid |
| 004c2e20 | MergeSortLinkedListByFloat | merge-sort linked list by float value in data nodes |
| 004c4d50 | sub_4C4D50 | format/log a debug string |
| 004c5070 | RandomVehicleSelector | select random vehicle from pool by index |
| 004c50e0 | GuardedListAccessor | access data from guarded list at vehicle index |
| 005871f0 | ReadFieldAtOffset0x14 | read field at offset 0x14 from a struct |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory for list and data nodes |
| 0058815f | StringFormatWithBufferOverflowCheck | format string with buffer overflow check |
| 00588410 | sub_588410 | compare vehicle string against filter value |
| 005884ed | RandLCGRandomNumberGenerator | generate pseudo-random index for vehicle selection |

**Guard conditions:** If a2 <= 10 and AIPathPerformanceFunction returns == a2, return early (no list rebuild needed). Vehicle selection: skips vehicles where sub_588410 returns false AND v6 >= 2 (vehicle string doesn't match filter when multiple options available). Selection loop continues until v30 (selected count) reaches a2. If linked list has < 2 elements after selection, skip merge sort.
