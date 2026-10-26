## ShortComputation_84b0_004084b0 — LargeStructConstructorWithVTable

**Summary:** Initializes a struct with vtable pointer at offset 0, zeros all fields, sets offset 0x34 to -1 and offset 0x50 to 2. Object constructor for a managed type with vtable dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40C140 (0040c140)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer set to off_59E60C |
| this | 0x4 | RW | 0 | field zeroed on init |
| this | 0x8 | RW | 0 | field zeroed on init |
| this | 0xC | RW | 0 | field zeroed on init |
| this | 0x10 | RW | 0 | field zeroed on init |
| this | 0x14 | RW | 0 | field zeroed on init |
| this | 0x18 | RW | 0 | field zeroed on init |
| this | 0x1C | RW | 0 | field zeroed on init |
| this | 0x20 | RW | 0 | field zeroed on init |
| this | 0x24 | RW | 0 | field zeroed on init |
| this | 0x28 | RW | 0 | field zeroed on init |
| this | 0x2C | RW | 0 | field zeroed on init |
| this | 0x30 | RW | 0 | field zeroed on init |
| this | 0x34 | RW | 18446744073709551615 | sentinel/id field set to -1 (uninitialized marker) |
| this | 0x38 | RW | 0 | field zeroed on init |
| this | 0x3C | RW | 0 | field zeroed on init |
| this | 0x40 | RW | 0 | field zeroed on init |
| this | 0x44 | RW | 0 | field zeroed on init |
| this | 0x48 | RW | 0 | field zeroed on init |
| this | 0x4C | RW | 0 | field zeroed on init |
| this | 0x50 | RW | 2 | enum/count field set to 2 |

**Written-by note (persistence):**
- this 0x0: set every call to vtable pointer
- this 0x04–0x30, 0x38–0x4C: set to 0 every call
- this 0x34: set to -1 every call
- this 0x50: set to 2 every call
All fields are constructor-initialized; external pokes don't survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e60c | off_59E60C | R | VTable_59E60C [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — function always executes unconditionally as a constructor.
