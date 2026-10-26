## UIObjectConstructor_8e10_00478e10 — UIObjectConstructor_8e10

**Summary:** UI object constructor: initializes text display subsystem (UITextDisplayConstructor), sub-struct at offset 0x11C (sub_499B10), zeroes multiple fields (0x150-0x170), sets field at 0x118 to 148 (line/text capacity), assigns vtable off_5A4A20.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5A4A20 | vtable pointer for UI object type |
| this | 0x118 | RW | 148 | line/text capacity count |
| this | 0x150 | RW | 0 | zero-initialized state field |
| this | 0x15C | RW | 0 | zero-initialized path/string field |
| this | 0x160 | RW | 18446744073709551615 | max/limit field set to -1 |
| this | 0x164 | RW | 0 | zero-initialized field |
| this | 0x168 | RW | 0 | zero-initialized field |
| this | 0x16C | RW | 0 | zero-initialized field |
| this | 0x170 | RW | 0 | zero-initialized field |

**Written-by note (persistence):**
- this 0x0: once per call, set to off_5A4A20 (vtable init)
- this 0x118: once per call, set to 148
- this 0x150: once per call, set to 0
- this 0x15C: once per call, set to 0
- this 0x160: once per call, set to -1
- this 0x164: once per call, set to 0
- this 0x168: once per call, set to 0
- this 0x16C: once per call, set to 0
- this 0x170: once per call, set to 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4a20 | off_5A4A20 | R | vtable pointer assigned to UI object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488180 | UITextDisplayConstructor | initializes text display subsystem on this object |
| 00499b10 | sub_499B10 | sub-struct initializer called on this+71 (offset 0x11C) |

**Guard conditions:** none (no branches — unconditional initialization)
