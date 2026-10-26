## AIStateBufferInitialize_0042ec60 — AIStateBufferInitialize

**Summary:** Initializes AI state history buffers by left-shifting all entries (discarding oldest), sets four float fields to 0.5f (default weights/confidence), and marks activation flag to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CleanupWrapper (00433eb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | Activation/ready flag byte, set to 1 |
| this | 0xC4 | RW | — | Start of first history buffer (4×11 elements at 64-byte stride) |
| this | 0xC8 | R | — | Second element of first history buffer (source for left-shift) |
| this | 0xBC4 | RW | — | Start of second history buffer (55 elements at 64-byte stride) |
| this | 0xBC8 | R | — | Second element of second history buffer (source for left-shift) |
| this | 0x1CA8 | RW | 1056964608 → 0.5f | Float field 1, initialized to 0.5 (default weight/confidence) |
| this | 0x1CAC | RW | 1056964608 → 0.5f | Float field 2, initialized to 0.5 |
| this | 0x1CB0 | RW | 1056964608 → 0.5f | Float field 3, initialized to 0.5 |
| this | 0x1CB4 | RW | 1056964608 → 0.5f | Float field 4, initialized to 0.5 |

**Written-by note (persistence):**
- this 0x0: Set to 1 every call.
- this 0xC4: Overwritten by copying from offset 0xC8+ (left shift). Repeated calls erase history.
- this 0xBC4: Overwritten by copying from offset 0xBC8+ (left shift). Repeated calls erase history.
- this 0x1CA8-0x1CB4: Set to 0.5f every call. Always initialized.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always executes all shifts and initializations unconditionally.
