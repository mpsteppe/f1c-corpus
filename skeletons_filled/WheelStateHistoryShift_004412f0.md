## WheelStateHistoryShift_004412f0 — WheelStateHistoryBufferShift

**Summary:** Shifts wheel state history buffers forward by one frame — copies current frame state to the "previous" slot for 4 wheels, then shifts per-wheel data blocks. Part of vehicle wheel state history management for physics integration.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** StateAccumulateDelta (00441360), PhysicsStepFrame (00441600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x338 | RW | — | wheel state history slot 0 (current → previous) |
| this | 0x33C | RW | — | wheel state history slot 0 (second field) |
| this | 0x340 | R | — | wheel state history slot 1 (current value, source for copy) |
| this | 0x344 | R | — | wheel state history slot 1 (second field) |
| this | 0x348 | RW | — | wheel state history slot 2 (copied forward) |
| this | 0x34C | RW | — | wheel state history slot 2 (second field) |
| this | 0x350 | R | — | wheel state history slot 3 (current value) |
| this | 0x354 | R | — | wheel state history slot 3 (second field) |
| this | 0x1C5C | RW | — | second wheel state buffer slot 0 (copied forward) |
| this | 0x1C60 | RW | — | second wheel state buffer slot 0 (second field) |
| this | 0x1C64 | R | — | second wheel state buffer slot 1 (source) |
| this | 0x1C68 | R | — | second wheel state buffer slot 1 (second field) |
| this | 0x1E38 | RW | — | third wheel state buffer slot 0 (copied forward) |
| this | 0x1E3C | RW | — | third wheel state buffer slot 0 (second field) |
| this | 0x1E40 | R | — | third wheel state buffer slot 1 (source) |
| this | 0x1E44 | R | — | third wheel state buffer slot 1 (second field) |

**Written-by note (persistence):**
- this 0x338: recalc every frame — external poke does NOT persist
- this 0x33C: recalc every frame — external poke does NOT persist
- this 0x348: recalc every frame — external poke does NOT persist
- this 0x34C: recalc every frame — external poke does NOT persist
- this 0x1C5C: recalc every frame — external poke does NOT persist
- this 0x1C60: recalc every frame — external poke does NOT persist
- this 0x1E38: recalc every frame — external poke does NOT persist
- this 0x1E3C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** no branches (unrolled loop over 4 iterations)
