## UIStructInit_0048e600 — UIBaseStructInit

**Summary:** Initializes base UI struct: calls ShortComputation_5e30 for base init, sets vtable to off_5AC540, zeroes fields at 0xE0/0xE8/0xEC, sets sentinel -1 at 0xE4, copies default directory string. Part of UI object construction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_466090 (00466090), sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer |
| this | 0xE0 | RW | 0 | resource handle / counter, zeroed on init |
| this | 0xE4 | RW | 18446744073709551615 | sentinel "no selection" / invalid handle (-1) |
| this | 0xE8 | RW | 0 | state flag / counter, zeroed on init |
| this | 0xEC | RW | 0 | secondary state field, zeroed on init |

**Written-by note (persistence):**
- this 0x0: once during construction; overwritten only by another constructor/destructor
- this 0xE0: once during construction; may be updated by later resource allocation
- this 0xE4: once during construction; survives until explicitly changed
- this 0xE8: once during construction; survives until explicitly changed
- this 0xEC: once during construction; survives until explicitly changed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac540 | off_5AC540 | R | PTR_VTABLE_5AC540 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | base struct initialization |
| 00566650 | StringCopyWithBufferRealloc | copy default directory string into struct buffer |

**Guard conditions:** None — unconditional initialization with no branches.
