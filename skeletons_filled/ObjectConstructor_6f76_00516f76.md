## ObjectConstructor_6f76_00516f76 — ConstructSubObject

**Summary:** Allocates a 28-byte sub-object via vtable allocator at this+0x4, stores at this+0x17C. Initializes byte flag at +8 to 0, stores UIControlStateMachine pointer and PhysicsStepCounterIncrement function pointer. Delegates remaining init to sub_516C7B.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateMachineWithDispatch (0050fb3b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | first vtable entry of allocator, called with (this, 1, 28) to allocate sub-object |
| this | 0x4 | R | — | pointer to allocator object |
| this | 0x17C | RW | — | stores allocated sub-object pointer |

**Written-by note (persistence):**
- this 0x17C: written once with allocated pointer, persists until freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00516e28 | UIControlStateMachine | R | state machine pointer stored as first dword of sub-object |
| 00516f55 | PhysicsStepCounterIncrement | R | function pointer stored as second dword of sub-object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00516c7b | sub_516C7B | completes initialization of the constructed object |

**Guard conditions:** No conditional branches — always allocates and initializes unconditionally.
