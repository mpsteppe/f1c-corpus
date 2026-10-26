## UIScreenStateMachine_00515df2 — UIScreenStateTick

**Summary:** Ticks UI screen state machine. Reads state from vtable dispatch; handles transition logic for states 1 (active/idle) and 2 (exiting/completed). Manages screen change requests by writing new screen IDs and invoking screen methods through vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Pointer to screen object (first DWORD of this); used to access screen vtable and state |
| obj | 0x14 | RW | 58 | Screen ID to transition to (written as 34 or 58 via vtable dispatch request) |
| this | 0x0 | R | — | First DWORD of self — pointer to screen object (same as obj) |
| this | 0x7C | R | — | Current selection/index value used for state-2 clamp check |
| this | 0x84 | RW | — | Target value clamped down to selection (min) during state-2 transition |
| this | 0x18C | R | — | Pointer to inner state flags byte array (a1[99]) |
| this | 0x190 | R | — | Pointer to state machine vtable/dispatch struct (a1[100]) |
| this | 0x194 | R | — | State machine method table pointer (a1[100] offset 4 used as state getter) |
| this | 0x19C | R | — | Inner flag byte: bit/field at offset 16 from flags base (v1[16]) |
| this | 0x19D | RW | 1 | Inner flag byte: bit/field at offset 17 (v1[17]); written to 1 on state-2 enter |
| this | 0x1A0 | RW | 0 | Inner flag byte at offset 20 from flags (v1[20]); cleared after texture validation |
| this | 0x1E1 | R | — | Byte at a1[100] + 81 (vtable struct field); checked for special transition path |

**Written-by note (persistence):**
- obj 0x14: written conditionally (screen transition request); survives until consumed by screen system
- this 0x84: written in state-2 if current value > selection; clamped down
- this 0x19D: written unconditionally to 1 in state-2; flag persists
- this 0x1A0: written to 0 after texture validation in state-1; flag persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159f5 | TextureSurfaceValidator | Validates/initializes texture surface; called when state=1 and v1[20] flag is set |
| 00515db8 | VtableDelegateDispatch | Dispatches to screen's vtable tick/delegate method; called in state=1 when v1[20] is clear |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1A0 | == | 0 | Inner flag byte at v1[20] — zero means "texture validated" or "no pending validation" |

**Guard interpretation:** State-1 path splits on v1[20] (this+0x1A0): if nonzero, validates texture and clears flag; if zero, checks v1[16] (this+0x19C) for transition-trigger condition. State-2 path also checks v1[20] for special screen-change-via-vtable path. Early return if v1[17] (this+0x19D) is set: returns 2 immediately, blocking all state logic.

