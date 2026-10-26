## UIOptionsConstructor_004726c0 — UIOptionsComponentConstructor_259

**Summary:** Constructor for a UI options component with ID 259. Sets vtable to off_5A2040, binds data source to ScreenModeSetting, configures with option count 3, initial state 1, and default selection 0xFFFFFFFF (-1). No linked-list handles or virtual dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Virtual method table pointer |
| this | 0x31C | RW | — | Data source interface pointer |
| this | 0x324 | RW | 3 | Number of states/options (3) |
| this | 0x328 | RW | 1 | Initial/current state value |
| this | 0x32C | RW | 1 | Minimum state value or enabled flag |
| this | 0x330 | RW | 1 | Maximum state value or visibility flag |
| this | 0x334 | RW | 259 | Unique component ID |
| this | 0x338 | RW | 18446744073709551615 | Default/disabled selection index (-1 as size_t) |

**Written-by note (persistence):**
- this 0x0: Written once during construction (vtable)
- this 0x31C: Written once during construction
- this 0x324: Written once during construction
- this 0x328: Written once during construction; may be changed by user interaction
- this 0x32C: Written once during construction
- this 0x330: Written once during construction
- this 0x334: Written once during construction
- this 0x338: Written once during construction; default selection sentinel

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a2040 | off_5A2040 | R | Vtable for this UI component type |
| 007cff84 | dword_7CFF84 | R | ScreenModeSetting [DERIVED] (also: ` — screen mode/display setting) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | Base constructor/initializer with param 1 |

**Guard conditions:** No guard conditions. Always executes all initialization steps unconditionally.
