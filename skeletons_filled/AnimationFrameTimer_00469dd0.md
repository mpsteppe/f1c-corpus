## AnimationFrameTimer_00469dd0 — AnimationFrameTimer

**Summary:** Accumulates frame delta time and advances animation frames when a threshold (2.0) is exceeded. Increments a frame counter by 2, wraps at a limit, and calls a vtable callback for animation update. Belongs to animation timing system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA0 | R | — | vtable offset 160 (0xA0): animation update callback method |
| this | 0x0 | R | — | vtable pointer |
| this | 0x40 | R | — | pointer to object for FloatFieldAccessor (provides frame delta time) |
| this | 0x174 | RW | — | accumulated time float (this[93]); reset to 0.0 each frame step |
| this | 0x178 | RW | — | animation frame counter (this[94]); incremented by 2, wraps at limit |

**Written-by note (persistence):**
- this 0x174: written to accumulated value each frame, then reset to 0.0 on threshold. Survives between frames unless reset.
- this 0x178: incremented by 2 on each frame step, wraps to 0 at limit. Persistent animation position.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 007d2dcc | dword_7D2DCC | R | AnimationFrameWrapLimit [DERIVED] (also: ` — animation frame count wrap limit) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00498730 | FloatFieldAccessor | retrieves frame delta time from object (for accumulation) |

**Guard conditions:** Checks accumulated time (this[93]) against threshold 2.0. If <= 2.0 (BLOCKED), no frame advance — just stores accumulated time. If > 2.0 (PASSES), advances frame counter by 2, resets accumulator, optionally wraps frame counter if >= dword_7D2DCC, and calls vtable animation callback.
