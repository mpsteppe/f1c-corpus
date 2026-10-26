## VirtualDispatchConditionalValue_00516937 — SetDispatchPriorityValue

**Summary:** Dispatches a virtual call to *(this+4)+0x24 with argument 1, then reads byte flag at this+0xC to determine result value (200 if non-zero, 100 if zero). Stores result at this+0x10 and returns it.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateMachineDispatcher (0050f904), StateMachineDispatch_f9ab (0050f9ab)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x24 | R | — | virtual function at offset 0x24 in dispatch object, called with (this, 1) |
| this | 0x4 | R | — | pointer to dispatch object whose vtable entry at +0x24 is called |
| this | 0xC | R | — | byte flag used as condition for value selection (200 vs 100) |
| this | 0x10 | RW | — | stores computed result value (200 or 100) |

**Written-by note (persistence):**
- this 0x10: written each call with computed priority value, persists until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | != | 0 | byte flag — non-zero yields result 200, zero yields 100 |

**Guard interpretation:** If byte at this+0xC is non-zero → PASS (use 200); if zero → alternate path (use 100). No early return — both paths compute and store result.
