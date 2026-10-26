## TimerCountdownWithStateTransition_004c1670 — TimerCountdownHandler

**Summary:** Handles countdown timer for session state transitions. When timer flag at 0xB150 is active, increments counter at 0xB148, checks it against SceneOrderReader threshold — if exceeded, sets phase to 3 at 0xB144. Resets phase counter to 1 and clears timer flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitStopPhaseAdvance (004c15a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB144 | RW | 3 | session state/phase, set to 3 when countdown exceeds threshold |
| this | 0xB148 | R | — | countdown counter, incremented each tick while timer active |
| this | 0xB14C | RW | 1 | phase counter, reset to 1 after timer completes |
| this | 0xB150 | RW | 0 | timer active flag byte (non-zero = countdown running) |

**Written-by note (persistence):**
- this 0xB144: set to 3 conditionally (when counter >= threshold) — external poke survives
- this 0xB14C: set to 1 unconditionally when timer active — external poke survives
- this 0xB150: cleared to 0 unconditionally — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c1190 | SceneOrderReader | read scene order threshold value for comparison |

**Guard conditions:** Byte at this+0xB150 must be non-zero (timer active). If zero, function returns immediately without changes. PASSES: non-zero timer flag.
