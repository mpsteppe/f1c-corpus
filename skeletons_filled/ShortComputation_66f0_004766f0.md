## ShortComputation_66f0_004766f0 — SeasonDatabaseObjectConstructor

**Summary:** Constructor for a season database object. Sets vtable, stores a parameter ID, and initializes fields with sentinel values (-1) and zero.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDatabaseObjectFactory (0047f440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to VTable_FUN_004766f0) |
| this | 0x180 | RW | — | constructor parameter a2 (some ID/handle) |
| this | 0x184 | RW | 18446744073709551615 | sentinel/invalid index (-1) |
| this | 0x188 | RW | 0 | counter or null handle |
| this | 0x18C | RW | 18446744073709551615 | sentinel/invalid index (-1) |

**Written-by note (persistence):**
- this 0x0: written once by constructor; persists for object lifetime
- this 0x180: written once; persists until changed by accessor
- this 0x184: written once; persists until changed by accessor
- this 0x188: written once; persists until changed by accessor
- this 0x18C: written once; persists until changed by accessor

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a44a0 | off_5A44A0 | R | VTable_FUN_004766f0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048eaa0 | LargeConstructor | base class / large member initialization |

**Guard conditions:** none (constructor — always executes all initializations)
