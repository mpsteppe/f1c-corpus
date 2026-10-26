## Constructor_e070_0048e070 — BinkVideoPlayerConstructor

**Summary:** Constructs a Bink video player object. Calls ShortComputation_5e30 for base init, zeros fields at 0xE0 and 0xE4 (this[56], this[57]), sets field at 0xEC to -1 (this[59]), sets field at 0xE8 to 0 (this[58]), sets vtable to off_5AC3E0, and calls StringCopyWithBufferRealloc with null (string reset).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FunctionCallWrapper_8bc0 (00478bc0), sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer set to off_5AC3E0 |
| this | 0xE0 | RW | 0 | Video resource handle (this[56]), zero-initialized |
| this | 0xE4 | RW | 0 | Video resource pointer (this[57]), zero-initialized |
| this | 0xE8 | RW | 0 | Unknown field (this[58]), zero-initialized |
| this | 0xEC | RW | 18446744073709551615 | Path/name identifier (this[59]), set to -1 (invalid) |

**Written-by note (persistence):**
- this 0x0: set every call (vtable init); survives external poke
- this 0xE0: zeroed every call; survives external poke
- this 0xE4: zeroed every call; survives external poke
- this 0xE8: zeroed every call; survives external poke
- this 0xEC: set to -1 every call; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac3e0 | off_5AC3E0 | R | VTable_5AC3E0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | Base object initialization |
| 00566650 | StringCopyWithBufferRealloc | Initialize/replace string buffer (called with null to reset) |

**Guard conditions:** None — unconditional constructor.
