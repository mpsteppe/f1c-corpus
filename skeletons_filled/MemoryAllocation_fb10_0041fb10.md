## MemoryAllocation_fb10_0041fb10 — DualStatusValidator

**Summary:** Validates that a named entrant has both status values 10 and 6 in standings entries at a rank-derived offset (entry + 4*v3 + 212), indicating both completed/retired and active session states are present.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c0a20 | SceneNameLookupBySeason | Fill buffer with scene/track name associated with current entry |
| 004c1370 | ActiveEntityCounter | Count active entries in standings |
| 004c1390 | FixedOffsetReturn | Get first/base standings entry pointer |
| 004c13a0 | ShortComputation_13a0 | Get standings entry pointer by index |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |
| 004c2990 | sub_4C2990 | Compute rank-derived index v3 from sort buffer |
| 00566810 | sub_566810 | Compare entry name against input name |

**Guard conditions:** (none — no race-active or track-condition checks). Internal:
- Both status flags must be true (`v2` for value 10 and `v11` for value 6 at derived offset) for the function to return true.
- No early exit if one flag is already set — both first-entry and all-entries scans may contribute to either flag.
