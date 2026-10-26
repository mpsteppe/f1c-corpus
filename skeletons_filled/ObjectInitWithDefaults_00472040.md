## ObjectInitWithDefaults_00472040 — UISimpleComponentConstructor_252

**Summary:** Minimal constructor for a UI component with ID 252. Does not bind an external data source (sets data source to null). Initializes vtable, sets option count to 32, and returns — no linked-list handles or virtual dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Virtual method table pointer |
| this | 0x31C | RW | 0 | Data source interface pointer (null = no external binding) |
| this | 0x324 | RW | 32 | Number of states/options (32) |
| this | 0x328 | RW | 0 | Initial/current state value |
| this | 0x32C | RW | 1 | Minimum state value or enabled flag |
| this | 0x330 | RW | 1 | Maximum state value or visibility flag |
| this | 0x334 | RW | 252 | Unique component ID |

**Written-by note (persistence):**
- this 0x0: Written once during construction (vtable)
- this 0x31C: Written once during construction (explicitly zeroed)
- this 0x324: Written once during construction
- this 0x328: Written once during construction; may be changed by user interaction
- this 0x32C: Written once during construction
- this 0x330: Written once during construction
- this 0x334: Written once during construction

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a1a40 | off_5A1A40 | R | Vtable for this UI component type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | Base constructor/initializer with param 1 |

**Guard conditions:** No guard conditions. Always executes all initialization steps unconditionally.
