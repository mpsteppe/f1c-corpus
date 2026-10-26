## CollisionGlobalInitC_0044d940 — InitializeCollisionObjectIndex28

**Summary:** Sets CollisionObjectIndex to 28 (0x1c) and zeroes five adjacent collision zeroed fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccdc8 | dword_7CCDC8 | W | CollisionObjectIndex (0x1c) [DERIVED] |
| 007ccdcc | dword_7CCDCC | W | CollisionZeroField5 [DERIVED] (also: ` through `DAT_007ccddc` — 5 zeroed fields) |
| 007ccdd0 | dword_7CCDD0 | W | Zeroed field slot 3 |
| 007ccdd4 | dword_7CCDD4 | W | Zeroed field slot 4 |
| 007ccdd8 | dword_7CCDD8 | W | Zeroed field slot 5 |
| 007ccddc | dword_7CCDDC | W | CollisionZeroedFields [DERIVED] (also: ` — 5 zeroed fields) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
