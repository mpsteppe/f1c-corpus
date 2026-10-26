## GlobalDataStructInitWithFilePaths_0040d980 — GlobalDataStructInit

**Summary:** Initializes a global data structure: stores four global pointers (session manager, pointer table, game state array, unknown) into pointer fields, zeroes counters/state fields, sets a max-size sentinel (-1) and a byte threshold (124), and calls sub-initializers for constraint solver and pointer array sub-structs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Wrapper_0030 (004d0030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | primary state/flags field, initialized to 0 |
| this | 0x4 | RW | — | pointer to dword_5EA510 (SessionManager) |
| this | 0x8 | RW | — | pointer to flt_5EA618 (PointerTableEntry) |
| this | 0xC | RW | — | pointer to dword_5EB978 (GameStatePtrArray3) |
| this | 0x10 | RW | — | pointer to unk_5EC6D0 (unknown global) |
| this | 0x84 | RW | 0 | counter/index field, cleared to 0 |
| this | 0x88 | RW | 0 | counter/index field, cleared to 0 |
| this | 0x8C | RW | 0 | counter/index field, cleared to 0 |
| this | 0x90 | RW | 0 | counter/index field, cleared to 0 |
| this | 0x94 | RW | 18446744073709551615 | sentinel/invalid index, set to -1 (all bits set) |
| this | 0x98 | RW | 0 | counter/index field, cleared to 0 |
| this | 0x9C | RW | 0 | counter/index field, cleared to 0 |
| this | 0xA0 | RW | 124 | max count/threshold (byte), set to 124 |

**Written-by note (persistence):**
- this 0x0: unconditional write, 0 — persists unless external code rewrites
- this 0x4: unconditional write, pointer — persists
- this 0x8: unconditional write, pointer — persists
- this 0xC: unconditional write, pointer — persists
- this 0x10: unconditional write, pointer — persists
- this 0x84: unconditional write, 0 — persists
- this 0x88: unconditional write, 0 — persists
- this 0x8C: unconditional write, 0 — persists
- this 0x90: unconditional write, 0 — persists
- this 0x94: unconditional write, -1 — persists
- this 0x98: unconditional write, 0 — persists
- this 0x9C: unconditional write, 0 — persists
- this 0xA0: unconditional write, 124 — persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | unknown global, stored as pointer at this+0x10 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00434860 | ConstraintSolverParamInit | initializes constraint solver parameter sub-struct at this+0x14 |
| 00567a00 | StructZeroInit_7a00 | zero-initializes sub-struct at this+0x4C |
| 00567f10 | F_9PointerArrayCleanup | cleans up/initializes pointer array at this+0x4C |

**Guard conditions:** No guard conditions — straight-line initialization, all writes unconditional.
