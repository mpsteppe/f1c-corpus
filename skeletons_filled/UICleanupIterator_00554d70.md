## UICleanupIterator_00554d70 — UICleanupIterator

**Summary:** Iterates UI resource slot array, releasing each via virtual dispatch and resetting state via StateParameterSetter. Also releases and clears a shared resource pointer (v2[5]) and resets its flags/float fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GuardedSubsystemRelease (00495060), ShortComputation_50c0 (004950c0), RenderTargetCleanup (0053f270), ConditionalUICleanupDispatch (005528f0), D3DResourceRelease (00554cc0), D3DResourceListCleanup (00554e10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1100)+0x0) | 0xF0 | R | — | Device vtable+240 resource release method |
| *(this+0x1100) | 0x0 | R | — | Device object vtable pointer |
| this | 0x0 | RW | — | Result accumulator from dispatch |
| this | 0x1100 | R | — | Pointer to device object (this[1088]) |
| this | 0x13B0 | R | — | Slot count (this[1260]), number of UI resource slots to iterate |

**Written-by note (persistence):**
- this 0x0: Updated from dispatch returns; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00554610 | StateParameterSetterWithVirtualDeviceNotify | Resets device parameter state to null for each slot |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x13B0 | > | 0 | Slot count must be > 0 to enter release loop |

**Guard interpretation:** Entry guard: v2[5] (resource pointer from a2+84) must be non-null. Loop guard: this[1260] (slot count) must be > 0 to iterate. Each iteration releases via vtable+240; if returned handle matches v2[5], resets device parameter to 0 first.
