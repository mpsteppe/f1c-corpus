## ObjectInitWithFieldZeroing_0048aa40 — Constructor with field zeroing

**Summary:** Object constructor: calls ConstructorInitVTable, zeros 8 integer fields (offsets 0xEC-0x108) and 2 byte flags (0x10C-0x10D), sets final vtable pointer to off_5ABE28. Returns initialized object pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5ABE28 |
| this | 0xEC | RW | 0 | this[59] — zeroed on init |
| this | 0xF0 | RW | 0 | this[60] — zeroed on init |
| this | 0xF4 | RW | 0 | this[61] — zeroed on init |
| this | 0xF8 | RW | 0 | this[62] — zeroed on init |
| this | 0xFC | RW | 0 | this[63] — zeroed on init |
| this | 0x100 | RW | 0 | this[64] — zeroed on init |
| this | 0x104 | RW | 0 | this[65] — zeroed on init |
| this | 0x108 | RW | 0 | this[66] — zeroed on init |
| this | 0x10C | RW | 0 | byte flag — zeroed on init |
| this | 0x10D | RW | 0 | byte flag — zeroed on init |

**Written-by note (persistence):**
- this 0x0: written once during construction (vtable assignment)
- this 0xEC-0x10D: zeroed once during construction; survive until explicitly modified later

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005abe28 | off_5ABE28 | R | Unknown_VTable_5ABE28 [DERIVED] — vtable assigned to this object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488b00 | ConstructorInitVTable | initializes vtable with flags (called before final vtable assignment) |

**Guard conditions:** No guard — constructor runs unconditionally.
