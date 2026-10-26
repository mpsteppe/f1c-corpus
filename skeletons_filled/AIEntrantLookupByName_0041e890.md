## AIEntrantLookupByName_0041e890 — EntrantNameToIDLookup

**Summary:** Searches the standings buffer for an entrant matching a given name string and returns the entrant's ID/index from offset 408 (0x198); returns 0 if not found within 103 entries.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AITargetDriverSelection (00418ee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c13a0 | ShortComputation_13a0 | Get standings entry pointer by index |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |
| 00588410 | sub_588410 | Compare input name string against entry name at offset 0 |

**Guard conditions:** (none — no race-active or track-condition checks)
