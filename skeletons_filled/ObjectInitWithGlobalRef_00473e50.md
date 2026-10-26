## ObjectInitWithGlobalRef_00473e50 — UIElementWithRendererRefInit

**Summary:** Initializes a UI element: sets vtable to off_5A3240, stores pointer to RendererRef_UI (unk_7CFBB4) at offset 0x31C, configures flags (1/0/1/1), sets value 384 at 0x334, registers two text-handle nodes including "On" label, and triggers virtual dispatch initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (off_5A3240) |
| this | 0x31C | RW | — | pointer to RendererRef_UI (unk_7CFBB4) |
| this | 0x324 | RW | 1 | flag / counter field |
| this | 0x328 | RW | 0 | flag / counter field |
| this | 0x32C | RW | 1 | flag / counter field |
| this | 0x330 | RW | 1 | flag / counter field |
| this | 0x334 | RW | 384 | value / limit / counter preset |

**Written-by note (persistence):**
- this 0x0: once (constructor vtable); survives external poke
- this 0x31C: once (pointer to RendererRef_UI); survives external poke
- this 0x324: once (literal 1); survives external poke
- this 0x328: once (literal 0); survives external poke
- this 0x32C: once (literal 1); survives external poke
- this 0x330: once (literal 1); survives external poke
- this 0x334: once (literal 384); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a3240 | off_5A3240 | R | vtable for this UI element type |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 — UI/text handle for first label |
| 005c32c8 | aOn | R | UIStringHandle — text handle for "On" label |
| 007cfbb4 | unk_7CFBB4 | R | RendererRef_UI — renderer reference stored in object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | basic field initialization / zeroing |
| 004670e0 | SwitchOnActionIDVirtualCall | vtable-based dispatch on action ID |
| 00486f30 | LinkedListInsertWithNodeAllocation | insert text-handle node into element's linked list |

**Guard conditions:** none — straight-line, no conditional branches.
