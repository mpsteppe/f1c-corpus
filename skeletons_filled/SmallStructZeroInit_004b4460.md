## SmallStructZeroInit_004b4460 — SmallStructZeroInit

**Summary:** Zero-initializes a 10-byte struct (two dwords + one word). Simple utility called by wrapper and buffer transfer functions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WrapperPassThrough (004b4450), LinkedBufferTransfer (004b5f60), sub_4B7860 (004b7860)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | First dword field |
| this | 0x4 | RW | 0 | Second dword field |
| this | 0x8 | RW | 0 | Word field (2 bytes) |

**Written-by note (persistence):**
- this 0x0: written once — set to 0
- this 0x4: written once — set to 0
- this 0x8: written once — set to 0 (2 bytes)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — always executes fully (unconditional zero-fill of all 10 bytes).
