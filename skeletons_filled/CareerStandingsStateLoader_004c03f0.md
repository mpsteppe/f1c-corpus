## CareerStandingsStateLoader_004c03f0 — Career standings state loader

**Summary:** Loads career season standings from an ini-file buffer into the standings object. Reads finish positions, points, season totals, grid positions, and active flag for each indexed entry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CareerSeasonStateFileReader (004c0b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B0 | RW | — | active flag (byte) for this standings entry |

**Written-by note (persistence):**
- this 0x1B0: written from parsed "Active" field value; external poke overwrites activation state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cc650 | aName_2 | R | "Name" field key for ini parsing |
| 005d267c | aActive | R | "Active" field key for ini parsing |
| 005d2684 | aControltype | R | "ControlType" field key |
| 005d2690 | aCurrentgridpos | R | "CurrentGridPos" field key |
| 005d26a4 | aOriginalgridpo | R | "OriginalGridPos" field key |
| 005d26bc | aPolestaken | R | "PolesTaken" field key |
| 005d26c8 | aPointsposition | R | "PointsPosition" field key |
| 005d26d8 | aSeasonpoints | R | "SeasonPoints" field key |
| 005d26e8 | aFinishpoints | R | "FinishPoints" field key |
| 005d26f8 | aS22d | R | "%s%2.2d" format string for indexed field names |
| 005d2700 | aFinishposition | R | "FinishPosition" field key |
| 005d2710 | aRcdfile | R | "RcdFile" field key |
| 005d2718 | aVehfile | R | "VehFile" field key |
| 008ac050 | unk_8AC050 | R | scene setup data structure |
| 008ac1e8 | unk_8AC1E8 | R | scene render/state struct for conditional dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005651b0 | sub_5651B0 | check scene setup dispatch return |
| 005654a0 | sub_5654A0 | read string field from ini section |
| 00565760 | sub_565760 | write integer value from ini field to standings struct |
| 00566650 | StringCopyWithBufferRealloc | copy string with buffer reallocation |
| 00566cc0 | ConditionalDispatchBasedOnFlag | iterate over ini file entries with flag check |
| 00587c20 | sub_587C20 | locate field within ini section by name |
| 00587ece | sub_587ECE | parse integer value from field string |
| 0058815f | StringFormatWithBufferOverflowCheck | format indexed field name string |

**Guard conditions:** Returns 0 if input buffer a2 is NULL/empty. Returns immediately if ConditionalDispatchBasedOnFlag returns false (no more entries). Returns early (with value 1) if sub_5651B0 returns 1 or 4 (certain scene dispatch codes indicating skip). Finish position and finish points only parsed if their indexed index is < 48 (0x30). Season totals (points, position, poles, grid) written unconditionally when entry is active.
