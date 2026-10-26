## UIObjectConstructor_7ea0_00477ea0 — UITextDisplayDerivedConstructor

**Summary:** Constructor for a UI text display derived class. Calls base constructor, initializes a sub-object at offset 0x124, sets index fields to sentinel values (-1) or 0, and assigns the vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to VTable_off_5A46B0) |
| this | 0x11C | RW | 18446744073709551615 | sentinel/invalid index (-1) |
| this | 0x120 | RW | 18446744073709551615 | sentinel/invalid index (-1) |
| this | 0x158 | RW | 0 | counter / null handle |
| this | 0x15C | RW | 18446744073709551615 | sentinel/invalid index (-1) |

**Written-by note (persistence):**
- this 0x0: written once by constructor; persists for object lifetime
- this 0x11C: written once; persists until changed by accessor
- this 0x120: written once; persists until changed by accessor
- this 0x158: written once; persists until changed by accessor
- this 0x15C: written once; persists until changed by accessor

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a46b0 | off_5A46B0 | R | VTable for this UI text display derived type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488180 | UITextDisplayConstructor | base class constructor for UI text display |
| 00499b10 | sub_499B10 | initializes sub-object at offset 0x124 (collection/list) |

**Guard conditions:** none (constructor — always executes all initializations)
