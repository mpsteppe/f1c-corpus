## ShortComputation_fb70_0048fb70 — UIObjectVariantStructInit

**Summary:** Initializes a UI struct variant: calls ShortComputation_5e30 for base init, sets vtable to off_5AC5F0, zeroes field at 0xE0, sets sentinel -1 at 0xE4. A simpler init variant compared to UIStructInit_0048e600 (fewer fields initialized).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_478110 (00478110), ShortComputation_81e0 (004781e0), ObjectConstructorWithVTable_8280 (00478280)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer |
| this | 0xE0 | RW | 0 | resource handle / counter, zeroed on init |
| this | 0xE4 | RW | 18446744073709551615 | sentinel "no selection" / invalid handle (-1) |

**Written-by note (persistence):**
- this 0x0: once during construction; overwritten only by another constructor/destructor
- this 0xE0: once during construction; may be updated by later resource allocation
- this 0xE4: once during construction; survives until explicitly changed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac5f0 | off_5AC5F0 | R | VTablePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | base struct initialization |

**Guard conditions:** None — unconditional initialization with no branches.
