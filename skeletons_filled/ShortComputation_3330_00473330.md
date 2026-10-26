## ShortComputation_3330_00473330 — UIElementWithEnableFlagInit

**Summary:** Initializes a UI element: sets vtable to off_5A2700, stores pointer to EnableFlag (dword_7CF788) at offset 0x31C, configures flags (1/0/1/1), sets value 269 at 0x334, and registers two text-handle nodes including "On" label.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (off_5A2700) |
| this | 0x31C | RW | — | pointer to global EnableFlag (dword_7CF788) |
| this | 0x324 | RW | 1 | flag / counter field |
| this | 0x328 | RW | 0 | flag / counter field |
| this | 0x32C | RW | 1 | flag / counter field |
| this | 0x330 | RW | 1 | flag / counter field |
| this | 0x334 | RW | 269 | value / limit / counter preset |

**Written-by note (persistence):**
- this 0x0: once (constructor vtable); survives external poke
- this 0x31C: once (pointer to EnableFlag); survives external poke
- this 0x324: once (literal 1); survives external poke
- this 0x328: once (literal 0); survives external poke
- this 0x32C: once (literal 1); survives external poke
- this 0x330: once (literal 1); survives external poke
- this 0x334: once (literal 269); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a2700 | off_5A2700 | R | vtable for this UI element type |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 — UI/text handle for first label |
| 005c32c8 | aOn | R | UIStringHandle — text handle for "On" label |
| 007cf788 | dword_7CF788 | R | EnableFlag — global enable/disable flag referenced by pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | basic field initialization / zeroing |
| 00486f30 | LinkedListInsertWithNodeAllocation | insert text-handle node into element's linked list |

**Guard conditions:** none — straight-line, no conditional branches.
