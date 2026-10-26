## StringCopyFieldInit_00559350 — StringCopyFieldInit

**Summary:** Copy string parameter into struct start, then init 3 dword fields at offsets 0x14, 0x18, 0x1C from caller parameters (last zeroed). Return a3.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5594B0 (005594b0), sub_559570 (00559570)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Dword field set from parameter a3 |
| this | 0x18 | RW | — | Dword field set from parameter a4 |
| this | 0x1C | RW | 0 | Dword field explicitly zeroed |

**Written-by note (persistence):**
- this 0x14: Written unconditionally from a3 once per init call
- this 0x18: Written unconditionally from a4 once per init call
- this 0x1C: Written unconditionally to 0 once per init call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None (unconditional init).
