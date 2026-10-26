## ConditionalRenderStateUpdate_00460710 — ConditionalRenderStateUpdate

**Summary:** Updates render state bitfield when session phase is not 1. Sets bit 4 of render state flag to 1 via state buffer initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890), NetworkUIUpdate (00462848)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3FC4 | R | — | Session phase (guard: skips update when phase == 1) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461470 | ThunkToFUN00461480 | Initialize local state buffer |
| 004614f0 | BitfieldSetClearAt0x88 | Set bit 4 to 1 on render state at offset 0x88 |
| 004623b0 | ShortComputation_23b0 | Finalize/cleanup state buffer |
| 004623e0 | FunctionCallWrapper_23e0 | Process state buffer |
| 004b0170 | EmptyStub_0170 | Empty stub (cleanup) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3FC4 | != | 1 | Session phase |

**Guard interpretation:**
- this[0x3FC4/4] (phase) == 1 → skip, return 0 (no render update).
- Phase != 1 → init state buffer, set bitfield bit 4 = 1, cleanup, return.
