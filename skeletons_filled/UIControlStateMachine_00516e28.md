## UIControlStateMachine_00516e28 — UIControlStateMachineTick

**Summary:** UI control state machine per-tick update: manages control activation state, state transitions, virtual-function dispatch for rendering/input handling, and child-control position updates. Implements a state machine with flag-based branching for button press, hold, and release logic.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x17C) | 0x8 | RW | 1 | state transition trigger flag (byte: 1 = pending transition, cleared to 0 on consume) |
| *(this+0x17C) | 0xC | R | — | state machine data field (copied to child control at offset 12) |
| *(this+0x17C) | 0x10 | R | — | state machine data field (used in child control positional math) |
| *(this+0x17C) | 0x14 | R | — | state machine state index for vtable lookup (when button+hold conditions met) |
| *(this+0x17C) | 0x18 | R | — | alternate state index for vtable lookup (when single-button condition met) |
| *(this+0x180) | 0x0 | R | — | vtable function pointer: action dispatch (called with a1, 2 or 0) |
| *(this+0x184) | 0x8 | R | — | vtable function pointer at index 2: update/render dispatch |
| *(this+0x188) | 0x0 | R | — | vtable function pointer: state transition dispatch (called with a1, 0/3) |
| *(this+0x198) | 0x0 | R | — | vtable function pointer: pre-update dispatch (before input check) |
| *(this+0x19C) | 0x0 | R | — | vtable function pointer: post-input processing dispatch |
| *(this+0x1A0) | 0x0 | R | — | vtable function pointer: conditional dispatch (when byte at 0x10 is 0) |
| *(this+0x1A4) | 0x0 | R | — | vtable function pointer: main logic dispatch (called with a1, state flag) |
| *(this+0x8) | 0xC | RW | — | child control width/size field (set from state machine data at 0xC) |
| *(this+0x8) | 0x10 | RW | — | child control position/offset field (computed from state data + flags) |
| *(this+0x8) | 0x11 | R | — | child control flag byte at offset 0x11 (read post-computation) |
| obj | 0x0 | R | — | base object vtable pointer (dereferenced for init call) |
| obj | 0x14 | RW | 45 | base object action code (set to 45 for reset/init path) |
| this | 0x0 | R | — | base object vtable pointer (for init call via (**a1)(a1)) |
| this | 0x8 | R | — | pointer to child/render control (nullable, checked before update) |
| this | 0x40 | R | — | byte flag: gate for child control secondary offset adjustment |
| this | 0x41 | R | — | byte flag: gate for bypass path (when 0, skips some dispatches) |
| this | 0x4A | R | — | byte flag: input condition A (some button/input state) |
| this | 0x50 | R | — | dword: secondary condition value (compared to 0 for input gate) |
| this | 0x58 | R | — | byte flag: input condition B (hold/alternate button state) |
| this | 0x5A | R | — | byte flag: input condition C (third button condition) |
| this | 0x74 | R | — | byte flag: main activation gate (when 0, entire input branch skipped) |
| this | 0x17C | R | — | pointer to state-machine context struct (380 decimal) |
| this | 0x180 | R | — | pointer to action vtable (384 decimal) |
| this | 0x184 | R | — | pointer to update/render vtable (388 decimal) |
| this | 0x188 | R | — | pointer to state-transition vtable (392 decimal) |
| this | 0x18C | R | — | pointer to sub-object (396 decimal, checked at offset 0x11 for byte gate) |
| this | 0x198 | R | — | pointer to pre-update vtable (408 decimal) |
| this | 0x19C | R | — | pointer to post-input vtable (412 decimal) |
| this | 0x1A0 | R | — | pointer to conditional-dispatch vtable (416 decimal) |
| this | 0x1A4 | RW | — | pointer to main-logic vtable (420 decimal; overwritten per state) |

**Written-by note (persistence):**
- *(this+0x17C) 0x8: conditional write (cleared to 0 on transition path, set to 1 on button+hold path) — external poke does NOT persist beyond next tick
- *(this+0x8) 0xC: unconditional write when child control exists — external poke does NOT persist
- *(this+0x8) 0x10: unconditional write when child control exists — external poke does NOT persist
- obj 0x14: conditional write (only on fallback init path) — external poke does NOT persist
- this 0x1A4: conditional write (only on button+hold path) — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x17C) | 0x8 | != | 0 | state transition trigger active: PASSES into transition-reset path (clears flag, dispatches actions 0,2,2); BLOCKED falls to normal update |
| this | 0x5A | != | 0 | third button condition: PASSES allows button+hold vtable assignment path; BLOCKED falls to alternate or fallback |

**Guard interpretation:** Two top-level branches. First: if state transition flag `*(v1+8) != 0`, consume it (set to 0), dispatch three vtable calls, and skip input logic. Second (normal path): if `*(this+0x74) != 0 && *(this+0x116) == 0` (activation gate open, counter zero), then nested: if `*(this+0x80) && *(this+0x90)` both set → button+hold path assigns vtable from `v1+0x14` and sets transition flag; else if `*(this+0x88)` set → single-button path assigns vtable from `v1+0x18`; else → fallback init path writes 45 to base object. After input dispatch, if `*(this+0x65) == 0` (bypass gate open), runs additional dispatches including main logic vtable call and state transition call. Finally, if child control pointer at `this+0x8` non-null, updates its width and position from state data.
