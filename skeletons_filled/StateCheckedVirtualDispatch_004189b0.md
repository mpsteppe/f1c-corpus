## StateCheckedVirtualDispatch_004189b0 — StateGatedVirtualAction

**Summary:** Checks that the current state ID (this+0xAEC) matches the requested state (a2), then validates through a vtable gate check before dispatching a virtual action method. Returns 1 if action executed, 0 if blocked. Part of state machine infrastructure.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** BooleanOROfTwoChecks (00418a20), PitSelectionStateMachine (0041b3c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xAF4) | 0x8 | R | — | Vtable[2] — gate check function pointer (must return nonzero) |
| *(this+0xAF4) | 0xC | R | — | Vtable[3] — action function pointer (called on success) |
| this | 0xAEC | R | — | Current state ID, compared against parameter a2 |
| this | 0xAF4 | R | — | Pointer to vtable-equipped object (dispatched through) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this[0xAEC] != a2 → return 0 (state mismatch). If this[0xAF4] is null OR vtable[2] gate returns 0 → return 0 (blocked by gate). Otherwise execute vtable[3] action and return 1.
