## WindowControlTypeDetection_0048c0e0 — WindowControlTypeFromPath

**Summary:** Detects window control type (0/1/2) by comparing path string at this+0xB8 against reference strings. Sets type at this+0x30C based on last matching condition: 0 for "UI_Load"/byte_5CC21C match, 1 for "R"/aR match, 2 for "c"/aC_0 match.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneGraphQueryConditionalCall (00472bc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB8 | R | — | Path/string pointer (fallback to byte_5EA438 if null) |
| this | 0x30C | RW | 2 | Window control type: 0=UI_Load, 1=R, 2=c (last match wins) |

**Written-by note (persistence):**
- this 0x30C: written on each matching condition; last match persists. If no match, value unchanged.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c36f0 | aR | R | Reference string "R" — matched for type 1 |
| 005cc210 | aC_0 | R | Reference string "c" / ".c" — matched for type 2 |
| 005cc21c | byte_5CC21C | R | Reference string "UI_Load" — matched for type 0 |
| 005ea438 | byte_5EA438 | R | Default application directory (fallback when this+0xB8 is null) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | String comparison/matching function; returns 0 on match |

**Guard conditions:** If this+0xB8 path pointer is null, defaults to byte_5EA438 for each comparison. No early returns — all three comparisons run sequentially. Each match overwrites this+0x30C, so the last matching case determines the final type.
