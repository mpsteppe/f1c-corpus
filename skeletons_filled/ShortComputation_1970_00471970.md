## ShortComputation_1970_00471970 — UIComponentConstructor_244

**Summary:** Constructor for a UI component with ID 244. Sets vtable to off_5A1440, binds data source to Unknown_Byte_7CE7F0, configures as two-state (value count 2), inserts three linked-list UI handles (text, registered data, registered ctrl), and calls post-init virtual dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Virtual method table pointer |
| this | 0x31C | RW | — | Data source interface pointer |
| this | 0x324 | RW | 2 | Number of states/values (2 = two-state) |
| this | 0x328 | RW | 0 | Initial/current state value |
| this | 0x32C | RW | 1 | Minimum state value or enabled flag |
| this | 0x330 | RW | 1 | Maximum state value or visibility flag |
| this | 0x334 | RW | 244 | Unique component ID |

**Written-by note (persistence):**
- this 0x0: Written once during construction (vtable)
- this 0x31C: Written once during construction
- this 0x324: Written once during construction
- this 0x328: Written once during construction; may be changed by user interaction
- this 0x32C: Written once during construction
- this 0x330: Written once during construction
- this 0x334: Written once during construction

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a1440 | off_5A1440 | R | Vtable for this UI component type |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] (also: ` — UI/text handle) |
| 005c32a4 | off_5C32A4 | R | RegisteredDataPtr [DERIVED] (also: registered) |
| 005c32a8 | aHigh | R | RegisteredCtrlPtr [DERIVED] (also: registered) |
| 007ce7f0 | dword_7CE7F0 | R | Unknown_Byte_7CE7F0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | Base constructor/initializer with param 1 |
| 004670e0 | SwitchOnActionIDVirtualCall | Post-init virtual dispatch on action ID |
| 00486f30 | LinkedListInsertWithNodeAllocation | Insert UI handle node into linked list |

**Guard conditions:** No guard conditions. Always executes all initialization steps unconditionally.
