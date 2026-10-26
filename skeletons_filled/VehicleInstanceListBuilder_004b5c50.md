## VehicleInstanceListBuilder_004b5c50 — Vehicle Instance List Builder

**Summary:** Iterates 104 vehicle entries from a2 (each 18624 bytes stride), building per-slot linked lists of tracked vehicle instances. Compares vehicle identity strings, sets initial timestamps for new entries, and manages free list allocation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimingUpdate (004b7a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x44)+0x0) | 0x88 | RW | — | Vehicle instance timestamp field (set to session time if -1.0e32) |
| *(this+0x10) | 0x84 | RW | — | Entry driver name/timestamp field (set to session time) |
| *(this+0x44) | 0x0 | R | — | Per-slot linked list head node pointer |
| *(this+0x44) | 0x4 | RW | — | Node next link in list |
| this | 0x10 | R | — | Free list head (pool of reusable entry nodes) |
| this | 0x18 | RW | 0 | Free list temp/current pointer (cleared to 0) |
| this | 0x44 | RW | — | Per-slot list head (current new entries prepended here) |
| this | 0x48 | RW | — | Per-slot list tail (first entry anchor) |
| this | 0x4C | RW | — | Per-slot entry count |

**Written-by note (persistence):**
- *(*(this+0x44)+0x0) 0x88: Set to session time if currently -1.0e32; persists.
- *(this+0x10) 0x84: Set to session time for new entries; persists in node.
- *(this+0x44) 0x4: Updated with new entry next link; persists.
- this 0x18: Written with free list current position; per-call overwrite.
- this 0x44: Prepended with new entry each time; persists.
- this 0x48: Written once on first insertion (tail anchor); persists.
- this 0x4C: Incremented per insertion; persists.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd10 | flt_5ACD10 | R | EntityActiveDefault [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: current session time) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b5120 | VehicleIdentityStringComparison | Compare vehicle identity string against entry |
| 004b51e0 | DriverNameTeamCopy | Copy driver/team name from a2 into entry |
| 004ba830 | LinkedListNodeRemoval_a830 | Remove node from free list for reuse |
| 004baa50 | FixedSizeContainerConstructor | Initialize fixed-size container allocation |
| 004baf10 | sub_4BAF10 | Initialize or set up entry node |
| 004bb0c0 | sub_4BB0C0 | Pop entry from free list |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 4-byte or 12-byte structures |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x44 | == | 0 | This per-slot list head |

**Guard interpretation:** If this+0x44 (slot list head) is NULL, skip identity check and session time update for that slot entirely. Entry creation also checks a2+13000 != -1 to gate insertion (vehicle slot is active/used).
