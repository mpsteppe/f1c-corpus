## AnimationHandleAlloc_00513cd8 — AnimationHandleHashInit

**Summary:** Generate CRC32 hash via CRC32Computation(0,0,0) and store at this+0x100. Returns hash value. Initializes animation handle identifier.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5119E9 (005119e9), sub_511B7C (00511b7c), sub_519019 (00519019)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x100 | RW | — | animation handle CRC32 hash identifier |

**Written-by note (persistence):**
- this 0x100: written once per call with CRC32 hash; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051923d | CRC32Computation | compute CRC32 hash for animation handle |

**Guard conditions (deterministic — field vs literal):**

No guard conditions — function always executes unconditionally.
