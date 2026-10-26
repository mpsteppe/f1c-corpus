## ShortComputation_12e0_004212e0 — SumMatchingSceneField

**Summary:** Iterates active entities in RaceStandingsSortBuffer linked list, sums field at offset 416 for entities whose scene name matches the `this` parameter. Returns total sum.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GdbSeasonSelector (00420cf0)

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
| 004c0a20 | SceneNameLookupBySeason | Look up scene name string for current season into buffer |
| 004c1370 | ActiveEntityCounter | Count number of active entities in linked list |
| 004c13a0 | ShortComputation_13a0 | Get entity pointer at given index from linked list |
| 004c2850 | LinkedListDereference | Dereference linked list to get working data pointer |
| 00566810 | sub_566810 | String comparison function (scene name vs this) |

**Guard conditions:** `this` null: early return 0. `ActiveEntityCounter(v5) <= 0`: skip loop entirely. `sub_566810(v7, this)` mismatch (scene name does not match target): skip entity, do not add its field(offset 416) to sum.
