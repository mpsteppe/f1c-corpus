## ShortComputation_b580_0046b580 — SeasonDatabaseVariantConstructor

**Summary:** Constructor for season database variant object. Calls base initializer sub_4893C0, sets vtable to off_59FA98, clears byte at 0xe0 via ByteSetterAt0xe0, initializes 0x174 to 0, 0x178 to -1, and stores parameter a2 at 0x17C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDatabaseObjectFactory (0047f440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer |
| this | 0x174 | RW | 0 | season state field, initialized to 0 |
| this | 0x178 | RW | 18446744073709551615 | season identifier, initialized to -1 (max) |
| this | 0x17C | RW | — | season parameter (a2), stored from caller |

**Written-by note (persistence):**
- this 0x0: set to vtable once during construction; survives
- this 0x174: set to 0 once; survives
- this 0x178: set to -1 once; survives
- this 0x17C: set from a2 parameter once; survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fa98 | off_59FA98 | R | VTable_59FA98 [DERIVED] — vtable for this variant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004893c0 | sub_4893C0 | base/sub-object constructor |
| 0048a3b0 | ByteSetterAt0xe0 | clears byte at offset 0xe0 to specified value (a3) |

**Guard conditions:** None — unconditional constructor, no branch conditions.
