## MemoryAllocation_afc0_004bafc0 — Dual-list allocation with 1016-byte block init

**Summary:** Allocates a 4-byte pointer block and a 2036-byte initialized block with two 1016-byte sub-chunks. Creates a list node referencing the block and inserts it into the first list. Creates two stride-offset nodes in the second list.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ModelSceneFileLoader (004b6c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First list head pointer |
| this | 0x4 | RW | — | First list tail pointer |
| this | 0x8 | RW | — | First list current/iterator pointer |
| this | 0xC | R | — | First list node count |
| this | 0x10 | RW | — | Second list head pointer (stack-like insert) |
| this | 0x14 | RW | — | Second list anchor (set on first insertion) |
| this | 0x18 | RW | — | Second list secondary reference (set on first) |
| this | 0x1C | R | — | Second list node count |

**Written-by note (persistence):**
- this 0x0-0x1C: all written per-call; persist as list state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b4f50 | DualCallWrapper_4f50 | Initialize each 1016-byte sub-chunk |
| 00587c03 | OperatorNewNhMallocWrapper | Memory allocation (4 bytes, 2036 bytes, 12-byte nodes) |

**Guard conditions:** If 4-byte allocation fails, entire function short-circuits (v12 = 0). Second loop nodes created only when computed offset v9 != 0.
