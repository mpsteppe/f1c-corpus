## CarCrashDamageProcessing_00496030 — CarCrashDamageProcess

**Summary:** Processes car crash damage animation over its lifecycle. On initial frame (timer == 0.01f), randomly selects impact origin from 8 screen-edge directions. Each frame decrements the damage timer, renders impact damage rectangles via sub_495DC0, and cleans up when timer expires. Part of the vehicle crash damage display system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_496E90 (00496e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x157C) | 0x4 | R | — | Damage data field at +0x4 — used as Y-screen-edge reference for direction computation |
| *(this+0x157C) | 0xC | R | — | Damage data field at +0xC — used as X-screen-edge reference for direction computation |
| this | 0xDC | RW | 0 | Float timer/countdown for damage animation duration; starts at 0.01f, decremented by frame delta |
| this | 0x1578 | RW | — | Damage impact type (0-4, randomized at init); determines direction selection behavior |
| this | 0x157C | RW | 0 | Pointer to damage geometry/data struct; cleared to 0 on timer expiry |
| this | 0x1580 | RW | 800 | X screen position of damage impact origin (may be negative for off-screen entry) |
| this | 0x1584 | RW | 18446744073709551016 | Y screen position of damage impact origin (signed value, may be negative for off-screen entry) |
| this | 0x18EC | RW | 0 | BYTE zeroed for damage types 2/3/4 (possibly a cleanup-ready flag) |
| this | 0x18F0 | RW | 0 | DWORD zeroed for damage types 2/3/4 (possibly secondary cleanup state) |

**Written-by note (persistence):**
- this 0xDC: decremented by frame delta each call; set to 0 on expiry; persists across frames during animation
- this 0x1578: initialized once on first frame (0.01f) via random(2); persists for animation duration
- this 0x157C: read from initial state, cleared to 0 on timer expiry; persists while animating
- this 0x1580: set on first frame based on random direction; persists through animation
- this 0x1584: set on first frame based on random direction; persists through animation
- this 0x18EC: zeroed for damage types 2/3/4; survives external poke
- this 0x18F0: zeroed for damage types 2/3/4; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00496250 | jpt_4960A2 | R | Jump table for damage direction switch (case 0, 8-way direction) |
| 00496264 | jpt_4960C3 | R | Jump table for damage direction switch (case 1, 3-way direction) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f) — used for timer expiry comparison |
| 0059e6f8 | flt_59E6F8 | R | Signed short scale factor — used in FloatFieldAccessor delta computation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00495dc0 | sub_495DC0 | Render damage impact rectangles for current frame |
| 00497100 | SceneEntityCleanup | Clean up scene entity associated with the damage event |
| 00497250 | ShortComputation_7250 | Post-damage processing (update damage counters/effects) |
| 00498730 | FloatFieldAccessor | Get frame delta time for decrementing damage timer |
| 00498740 | InitViewportDimensions | Get viewport dimensions for damage rectangle scaling |
| 005884ed | RandLCGRandomNumberGenerator | LCG random number generator for damage direction/type selection |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xDC | == | 1008981770 → 0.01f | Damage timer at initial value — triggers first-frame setup (randomize direction, init state) |

**Guard interpretation:** Timer at 0xDC <= 0.0f → BLOCKED (return 0, skip damage processing). Pointer at 0x157C == NULL → BLOCKED (return 0, no damage data). When timer == 0.01f (exact initial value), run first-frame initialization (randomize impact direction); otherwise proceed directly to per-frame timer decrement and damage rendering.
