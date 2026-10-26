## CollisionGridInit97_0044eb40 — CollisionInitBlockO

**Summary:** Initializes fifteenth collision block (dword_7CA51C–7CA530). Sets tag to 97 (grid size), zeros grid state fields, sets max distance to 27000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca51c | dword_7CA51C | W | CollisionGridSize_97 [DERIVED] (also: ` — grid size (97) |
| 007ca520 | dword_7CA520 | W | CollisionGridState_zeroed [DERIVED] |
| 007ca524 | dword_7CA524 | W | Zeroed grid state field |
| 007ca528 | dword_7CA528 | W | Zeroed grid state field |
| 007ca52c | dword_7CA52C | W | CollisionGridStateField [DERIVED] (also: ` — grid state (zeroed) |
| 007ca530 | dword_7CA530 | W | CollisionMaxDistance [DERIVED] (also: ` — max distance (27000) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
