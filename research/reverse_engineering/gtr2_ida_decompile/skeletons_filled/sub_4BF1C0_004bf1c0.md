## sub_4BF1C0_004bf1c0 — destructor body: frees buffers at +0x25C and +0x264

**Summary:** Destructor body for the class: releases two owned heap buffers (offsets 0x264 and 0x25C), then returns the result of the class's subsequent cleanup call on this object. Storage deallocation is left to the caller (sub_4BF1A0).

**Called by:** sub_4BF1A0 (004bf1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x25C | R | — | Owned heap pointer (this[151]); freed with j_j__free if non-null |
| this | 0x264 | R | — | Owned heap pointer (this[153]); freed with j_j__free if non-null |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006308d8 | j_j__free | CRT free wrapper; releases the two buffers owned at +0x25C / +0x264 |

**Guard conditions:** Two independent null checks: `if (this[153] != 0)` frees the 0x264 buffer; `if (this[151] != 0)` frees the 0x25C buffer. Null pointers are skipped. In both cases execution proceeds to the final cleanup call whose return value becomes this function's result — no early return.
