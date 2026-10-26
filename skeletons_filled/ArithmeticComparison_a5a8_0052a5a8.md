## ArithmeticComparison_a5a8_0052a5a8 — GetAudioCodecBasePointers

**Summary:** Returns four global base pointers (audio decode table, texture heap base, texture atlas, buffer) via output parameters. Used during audio codec initialization to expose internal data addresses to caller.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_527752 (00527752)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output parameter receiving dword_5D9418 (audio decode table pointer) |

**Written-by note (persistence):**
- this 0x0: written once by caller as output buffer; pointer value stored survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d9418 | dword_5D9418 | R | audio decode table base address |
| 005d941c | dword_5D941C | R | texture heap base address |
| 005d9420 | unk_5D9420 | R | texture atlas data pointer |
| 005da420 | unk_5DA420 | R | buffer pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — no branches in function body
