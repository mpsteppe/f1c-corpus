## UIObjectConstructor_fc50_0048fc50 — HUDTextNodeConstructor

**Summary:** Constructor for a UI object: calls UIStructInit_e9e0 to initialize base struct, then zeroes field at offset 0x30, sets sentinel -1 at offset 0x34, zeroes field at offset 0x38, and sets vtable to off_5A4450 (VTable_HUDTextNode).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIOptionsConstructor_6030 (00476030), sub_4760D0 (004760d0), UIObjectInit (004761c0), ProfileBitmapBrowser (00477cb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5A4450) |
| this | 0x30 | RW | 0 | additional state / counter field |
| this | 0x34 | RW | 18446744073709551615 | sentinel "no selection" / invalid index (-1) |
| this | 0x38 | RW | 0 | additional state / counter field |

**Written-by note (persistence):**
- this 0x0: set during construction; overwritten only by destructor
- this 0x30: set once during construction; survives until explicitly changed
- this 0x34: set once during construction; survives until explicitly changed
- this 0x38: set once during construction; survives until explicitly changed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4450 | off_5A4450 | R | VTable_HUDTextNode [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048e9e0 | UIStructInit_e9e0 | initialize base UI control struct |

**Guard conditions:** None — unconditional constructor with no branches.
