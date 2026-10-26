## CollisionParameterBlockInit_0044dbe0 — InitializeRainDampeningRear48

**Summary:** Sets RainDampeningRear to 48 and zeroes five adjacent parameter block fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cce70 | dword_7CCE70 | W | RainDampeningRear [DERIVED] |
| 007cce74 | dword_7CCE74 | W | Parameter block field slot 2 (zeroed) |
| 007cce78 | dword_7CCE78 | W | Parameter block field slot 3 (zeroed) |
| 007cce7c | dword_7CCE7C | W | Parameter block field slot 4 (zeroed) |
| 007cce80 | dword_7CCE80 | W | Parameter block field slot 5 (zeroed) |
| 007cce84 | dword_7CCE84 | W | Parameter block field slot 6 (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
