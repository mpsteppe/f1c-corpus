## AIPathPerformanceFunction_004bfa00 — AI performance-sorted opponent list builder

**Summary:** Builds a merge-sorted linked list of AI opponents from the vehicle pool by excluding already-selected vehicles and lookup up audio/skill parameters. Used to generate a performance-ranked opponent list for path assignment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIOpponentSelection (004bf790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | head of output linked list |
| this | 0x4 | RW | — | tail of output linked list |
| this | 0x8 | RW | — | current/iter pointer in output list |
| this | 0xC | RW | — | count of elements in output list |

**Written-by note (persistence):**
- this 0x0: written when list empty (first node) and after merge sort; external poke corrupts list
- this 0x4: written each append and after merge sort; external poke corrupts list
- this 0x8: written to new head after merge sort; external poke corrupts iteration
- this 0xC: incremented each append; external poke corrupts count

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac36c | dword_8AC36C | R | vehicle setup/roster data structure pointer |
| 008ac390 | dword_8AC390 | R | count of vehicle file entries |
| 008ac394 | dword_8AC394 | R | pointer to vehicle file entry array (stride 0x424) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bac20 | ShortComputation_ac20 | wrap data node into linked list node |
| 004bf6a0 | sub_4BF6A0 | look up season audio parameter for vehicle |
| 004c2e20 | MergeSortLinkedListByFloat | merge-sort output list by float key |
| 004c2f20 | LinkedListDestructorWithData | destroy temporary exclusion list |
| 004c5070 | RandomVehicleSelector | select random vehicle by index |
| 004c50e0 | GuardedListAccessor | access data from guarded list at vehicle index |
| 00566650 | StringCopyWithBufferRealloc | copy vehicle name string with buffer realloc |
| 005871f0 | ReadFieldAtOffset0x14 | read pool size from vehicle setup struct |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory for list and data nodes |
| 00588410 | sub_588410 | compare two vehicle strings (match/exclusion check) |
| 005884ed | RandLCGRandomNumberGenerator | generate pseudo-random indices |

**Guard conditions:** Returns 0 if ReadFieldAtOffset0x14 result (pool size) <= 0. First loop: vehicles whose string matches a3 filter (sub_588410 returns true) are skipped from exclusion list; vehicles that don't match are added to exclusion list. Second loop: vehicles in exclusion list (sub_588410 matches against excluded string) are skipped from main output list. Loop safety: v33 counter decrements from 200 with each attempt, preventing infinite loop when pool is exhausted before reaching a2 count. Loop also terminates when v30 >= a2.
