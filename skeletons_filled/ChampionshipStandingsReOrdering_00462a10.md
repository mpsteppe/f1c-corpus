## ChampionshipStandingsReOrdering_00462a10 — Championship Standings Re-Ordering After Race

**Summary:** Re-orders championship standings after a race result. Builds linked list of driver entries with their new positions based on flag state and stored values, merge-sorts them, writes position indices back to VEH array and struct field. Frees allocated memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiplayerVehiclePlacement (0042cf10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3E14 | R | — | count of driver entries to process; guard > 0 |
| obj | 0x3FD9 | RW | — | final count of re-ordered positions written back |
| this | 0x0 | R | — | vtable/primary pointer |
| obj | 0x394 | R | — | flag bitset for each entry (test bit 2 via FlagBitTest) |
| obj | 0x410 | R | — | driver index read per entry |
| obj | 0x3C74 | R | — | per-entry value (initial 15476 = 0x3C74, stride +4) |

**Written-by note (p****ersistence):**
- obj 0x3FD9: once, unconditional at end; written with final position count

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005f0730 | dword_5F0730 | RW | VEH[0].0x4058 = plannedPositionAtStart [CONFIRMED] |
| 007c9530 | dword_7C9530 | R | DriverTeamIndexTableEnd [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461530 | FlagBitTest | tests bit 2 of per-entry flag field to determine if driver has valid result |
| 004647d0 | LinkedListMergeSort_47d0 | merge-sorts linked list of driver entries by position value |
| 00587bcf | FreeWrapper_7bcf | frees linked list nodes and their contained data after reordering |
| 00587c03 | OperatorNewNhMallocWrapper | allocates linked list nodes (12 bytes each) for sort entries |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x3E14 | > | 0 | driver entry count |

**Guard interpretation:** If count at +0x3E14 is <= 0, skip linked-list building entirely (no entries to reorder), proceed directly to sort step with null list. PASSES only when count > 0.
