## ShortComputation_e300_0048e300 — FontResourceConstructor

**Summary:** Constructs a font resource object. Calls ConstructorWithByteParams for base init, zeros fields at 0xE4 (this[57]) and 0xFC (this[63]), sets field at 0x100 to -1 (this[64]), sets vtable to off_5AC490, and calls StringCopyWithBufferRealloc with null to reset string.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer set to off_5AC490 |
| this | 0xE4 | RW | 0 | Resource pointer (this[57]), zero-initialized |
| this | 0xFC | RW | 0 | Unknown pointer (this[63]), zero-initialized |
| this | 0x100 | RW | 18446744073709551615 | Unknown identifier (this[64]), set to -1 (invalid) |

**Written-by note (persistence):**
- this 0x0: set every call (vtable init); survives external poke
- this 0xE4: zeroed every call; survives external poke
- this 0xFC: zeroed every call; survives external poke
- this 0x100: set to -1 every call; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac490 | off_5AC490 | R | VTable_5AC490 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487220 | ConstructorWithByteParams | Base UI widget constructor with byte parameters |
| 00566650 | StringCopyWithBufferRealloc | Initialize/replace string buffer (called with null to reset) |

**Guard conditions:** None — unconditional constructor.
