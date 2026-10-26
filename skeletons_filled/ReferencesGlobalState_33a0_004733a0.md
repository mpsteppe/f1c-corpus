## ReferencesGlobalState_33a0_004733a0 — UIElementWithTripleLabelInit

**Summary:** Initializes a UI element: sets vtable to off_5A27C0, stores pointer to global UIControl_RefStore (dword_7D02E4) at 0x31C, configures flags (3/0/3/3), sets value 270 at 0x334, and registers one standard text handle plus three copies of the "On" label handle.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (off_5A27C0) |
| this | 0x31C | RW | — | pointer to global UIControl_RefStore (dword_7D02E4) |
| this | 0x324 | RW | 3 | flag / counter field |
| this | 0x328 | RW | 0 | flag / counter field |
| this | 0x32C | RW | 3 | flag / counter field |
| this | 0x330 | RW | 3 | flag / counter field |
| this | 0x334 | RW | 270 | value / limit / counter preset |

**Written-by note (persistence):**
- this 0x0: once (constructor vtable); survives external poke
- this 0x31C: once (pointer to UIControl_RefStore); survives external poke
- this 0x324: once (literal 3); survives external poke
- this 0x328: once (literal 0); survives external poke
- this 0x32C: once (literal 3); survives external poke
- this 0x330: once (literal 3); survives external poke
- this 0x334: once (literal 270); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a27c0 | off_5A27C0 | R | vtable for this UI element type |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 — UI/text handle for first label |
| 005c32c8 | aOn | R | UIStringHandle — text handle for "On" label (inserted 3x) |
| 007d02e4 | dword_7D02E4 | R | UIControl_RefStore — global reference stored in object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | basic field initialization / zeroing |
| 00486f30 | LinkedListInsertWithNodeAllocation | insert text-handle node into element's linked list |

**Guard conditions:** none — straight-line, no conditional branches.
